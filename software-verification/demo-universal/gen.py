from z3 import *
import random
from tqdm import tqdm

random.seed(1337)

flag = b"flag{r0r7_d6_h3x8r_j01m_m37w4r3_l4b}"
symflag = [BitVec(f"f_{i}", 8) for i in range(len(flag))]

constraints = []
pt = []

for i in range(500):
    [a, b, c] = random.sample(range(len(flag)), k=3)
    target = (flag[a] ^ (flag[b] * 7) ^ (0xff - flag[c] + 13)) & 0xff
    constraints.append(symflag[a] ^ (symflag[b] * 7) ^ ((~symflag[c]) + 13) == target)
    pt.append(f"(((flag.charCodeAt({a}) ^ (flag.charCodeAt({b}) * 7) ^ ((~flag.charCodeAt({c})) + 13)) & 0xff) == {target})")
    s = Solver()
    s.add(*constraints)
    s.add(Or(*(a != b for (a, b) in zip(flag, symflag))))
    if s.check() == unsat:
        break
else:
    raise Exception("it's doomed")

print(f"flag.length == {len(flag)} && " + " && ".join(pt))