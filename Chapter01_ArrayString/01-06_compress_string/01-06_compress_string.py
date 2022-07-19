# -*- coding: utf-8 -*-
input_str = input()
ans = ""
pre_s = ""
count = 1
for s in input_str:
    if s == pre_s:
        count += 1
    else:
        ans += pre_s
        if count > 1:
            ans += str(count)
        pre_s = s
        count = 1 
ans += pre_s
if count > 1:
    ans += str(count)

if len(input_str) < len(ans):
    print(input_str)
else:
    print(ans)

