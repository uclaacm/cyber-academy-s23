import operator
import functools
import itertools

d = [76, 70, 75, 77, 81, 77, 69, 69, 78, 117, 69, 70, 117, 82, 69, 88, 117, 66, 75, 89, 117, 68, 79, 92, 79, 88, 117, 76, 75, 67, 70, 79, 78, 117, 75, 68, 83, 69, 68, 79, 87]

if all(itertools.starmap(operator.eq, zip(map(functools.partial(operator.xor, 42), input("Flag? ").encode()), d))):
    print("Correct!")
else:
    print("Incorrect!")
