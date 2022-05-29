B = [[1, 1, 0, 0], [0, 1, 0, 1], [1, 1, 1, 1], [1, 0, 0, 1]]
for l in range(4):
    D1 = [[0 for i in range(4)] for j in range(4)]
    for i in range(4):
        for j in range(4):
            D1[i][j] = B[i][l] and B[l][j]
    B_copy = B
    B = [[(B_copy[i][j] or D1[i][j]) for j in range(4)] for i in range(4)]
    print(*zip(B_copy, D1, B), sep='\n', end='\n\n***\n')
