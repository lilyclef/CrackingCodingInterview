import string
import random

number_of_strings = 1000000
length_of_string = 8
# 9.0M
f = open('data.txt', 'w', encoding='UTF-8')

for x in range(number_of_strings):
  s = []
  for y in range(length_of_string):
    s.append(random.choice(string.ascii_lowercase))
  f.write(''.join(s))
  f.write('\n')
f.close()