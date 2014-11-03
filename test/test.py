#!/usr/bin/env python3.4
# -*- coding: utf-8 -*-

import random
import sys
from subprocess import *

if len(sys.argv) < 2:
    size = 1000
else:
    size = int(sys.argv[1])

ops = ["+", "-"]
for i in range (0, size):
    s = ""
    l = random.randint(1, 100)
    for i in range(0, l):
        s += str(int(random.getrandbits(random.randint(1, 200)))) + random.sample(ops, 1)[0]
    s += str(int(random.getrandbits(random.randint(1, 200))))
    res_bc = check_output("echo \"{0}\" | bc".format(s), shell = True)
    res_calc = check_output("echo \"{0}\" | ../calc 0123456789 \"\" {1}".format(s, len(s)), shell = True)
    if res_bc == res_calc:
        print ("OK")
    else:
        print ("FAIL")
        print (s)
        print ("bc\t->\t{0}".format(res_bc))
        print ("bm\t->\t{0}".format(res_calc))
        exit(1)
