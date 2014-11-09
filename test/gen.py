#!/usr/bin/env python3.4
# -*- coding: utf-8 -*-

import random
import sys
import uuid
import os
from subprocess import *

if len(sys.argv) < 2:
    size = 1000
else:
    size = int(sys.argv[1])

ops = ["/", "+", "-", "*"]
rops = ["(", ")", "+", "-", "*", "/", "%"]
complexity = 20
bcomplexity = 5
brackets_count = 0
for i in range (0, size):
    name = str(uuid.uuid4())
    fcmd = open(os.path.dirname(os.path.realpath(__file__)) + "/testscases/" + name + ".cmd", "w")
    fres = open(os.path.dirname(os.path.realpath(__file__)) + "/testscases/" + name + ".res", "w")
    s = ""
    l = random.randint(1, 20)
    for i in range(0, l):
        s += str(random.randint(-10 * complexity, 10 * complexity)) + random.sample(ops, 1)[0]
        if random.randint(0, 10) >= bcomplexity:
            s += rops[0]
            brackets_count += 1
        if random.randint(0, 10) >= bcomplexity and brackets_count > 0 and s[-1] not in rops:
            s += rops[1]
            brackets_count -= 1
    s += str(random.randint(1, 10 * complexity))
    while brackets_count > 0:
        s += rops[1]
        brackets_count -= 1
    res_bc = check_output("echo \"{0}\" | bc 2> /dev/null | tr -d '\n' | tr -d '\\\\'".format(s), shell = True)
    fcmd.write("0123456789" + '\n')
    fcmd.write(str(len(s)) + '\n')
    fcmd.write(''.join(rops) + '\n')
    fcmd.write(s + '\n')
    fres.write(res_bc.decode('utf-8'));
    fcmd.close()
    fres.close()
