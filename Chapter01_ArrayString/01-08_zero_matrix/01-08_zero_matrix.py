# -*- coding: utf-8 -*-
m = int(input())
n = int(input())
matrix = []
for i in range(0, m):
  matrix_input = input()
  matrix.append(list(map(int, matrix_input.split(','))))

#matrix = [[ 0,  1,  2,  3],
#[ 4,  5,  6,  7],
#[ 8,  9, 10, 11,],
#[12, 13, 14, 15] ]
zero = []
zero2 = []
for i in range(0, m):
   for j in range(0, n):
      if matrix[i][j] == 0:
        zero.append(i)
        zero2.append(j)
for i in range(0, m):
   for j in range(0, n):
      if (i in zero) or (j in zero2): 
        matrix[i][j] = 0
print(matrix)
