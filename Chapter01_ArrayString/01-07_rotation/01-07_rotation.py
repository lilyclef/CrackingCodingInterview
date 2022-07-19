# -*- coding: utf-8 -*-

target = [[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]]
ans = []
for i in range(0, 4):
    ans2 = []
    for j in range(0,4): 
        ans2.append(target[4-j-1][i])	
    ans.append(ans2)
print(ans)
