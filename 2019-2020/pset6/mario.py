# https://docs.cs50.net/2019/x/psets/6/sentimental/mario/more/mario.html
# https://cs50.harvard.edu/x/2020/psets/6/mario/more/

# Mario, more comfortable
# Implement a program that prints out a double half-pyramid of a specified
# height, per the below.

from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for k in range(height):
    print('{0}{1}  {1}'.format((height - k - 1) * ' ', (k + 1) * '#'))
