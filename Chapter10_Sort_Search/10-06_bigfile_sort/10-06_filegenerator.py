import string
import random

number_of_strings = 1000000
length_of_string = 8
f = open('sampledata.txt', 'w', encoding='UTF-8')
for x in range(number_of_strings):
  f.write(''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length_of_string)))
f.close()