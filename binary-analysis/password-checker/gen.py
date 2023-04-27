password = list(b"GinkoidGallantlyGallopsAtGoogle!")

assert len(password) % 8 == 0

def unpermute(cur):
    nchunks = len(cur) // 8
    new = [0] * len(cur)
    for i in range(len(cur)):
        chunk = i % nchunks
        offset = i // nchunks
        new[chunk * 8 + offset] = cur[i]
    return new

def permute(cur):
    nchunks = len(cur) // 8
    new = [0] * len(cur)
    for i in range(len(cur)):
        chunk = i % nchunks
        offset = i // nchunks
        new[i] = cur[chunk * 8 + offset]
    return new

def untransmute(cur):
    mod = 2 ** 64
    nums = [(int.from_bytes(cur[i:i + 8], "little") * pow(1337, -1, mod)) % mod for i in range(0, len(cur), 8)]
    return [b for n in nums for b in n.to_bytes(8, "little")]

for _ in range(50):
    password = unpermute(password)
    print(password)
    password = untransmute(password)
    print(password)

print(password)
