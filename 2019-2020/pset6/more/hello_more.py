# https://docs.cs50.net/2019/x/psets/6/sentimental/mario/more/mario.html

# Mario, more comfortable

from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for k in range(height):
    print('{0}{1}  {1}'.format((height - k - 1) * ' ', (k + 1) * '#'))
