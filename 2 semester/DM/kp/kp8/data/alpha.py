import os
import pathlib
import random

file = "graph.txt"
size = random.randint(5, 15)
raw = []
for i in range(size):
    raw.append([])
    for j in range(size):
        raw[-1].append(random.choice((0, 1)))
        if i == j:
            raw[-1][-1] = -1
raw = list(map(lambda x: " ".join(map(str, x)) + '\n', raw))
data = open(file, mode='w')
data.writelines(raw)

os.system("start ../cmake-build-debug/kp8.exe")