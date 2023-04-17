#!/usr/local/bin/python
if input("Password? ") == "I love cats":
    print("Seems legit, here's the flag!")
    with open("flag.txt", "r") as f:
        print(f.read().strip())
else:
    print("Hmm that's not the password...")
