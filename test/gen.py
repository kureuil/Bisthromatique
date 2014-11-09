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

ops = ["*", "+", "-"]
rops = ["(", ")", "+", "-", "*", "/", "%"]
for i in range (0, size):
    name = str(uuid.uuid4())
    fcmd = open(os.path.dirname(os.path.realpath(__file__)) + "/testscases/" + name + ".cmd", "w")
    fres = open(os.path.dirname(os.path.realpath(__file__)) + "/testscases/" + name + ".res", "w")
    s = ""
    l = random.randint(1, 100)
    for i in range(0, l):
        s += str(int(random.getrandbits(random.randint(1, 200)))) + random.sample(ops, 1)[0]
    s += str(int(random.getrandbits(random.randint(1, 200))))
    res_bc = check_output("echo \"{0}\" | bc | tr -d '\n' | tr -d '\\\\'".format(s), shell = True)
    fcmd.write("0123456789" + '\n')
    fcmd.write(str(len(s)) + '\n')
    fcmd.write(''.join(rops) + '\n')
    fcmd.write(s + '\n')
    fres.write(res_bc.decode('utf-8'));
    fcmd.close()
    fres.close()
