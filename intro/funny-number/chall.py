#!/usr/local/bin/python
import collections as c;n=str(int(input("What's the funny number? "))).zfill(10);assert len(n)==10;x=c.Counter(n);print(["Not funny enough!",open("flag.txt","r").read().strip()]["".join(str(x.get(str(i),0))for i in range(10))==n])
