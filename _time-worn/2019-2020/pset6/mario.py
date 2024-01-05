# ------------------------------------------------------------------------------
# mario.py
# "Less comfortable" version
#
# Computer Science 50
# Problem Set 6
#
# Prints out a half-pyramid of a specified heigh
#
# 2020:
# https://cs50.harvard.edu/x/2020/psets/6/mario/less/
# 2019
# https://docs.cs50.net/2019/x/psets/6/sentimental/mario/less/mario.html
# ------------------------------------------------------------------------------

from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 0 < height < 9:
        break

for k in range(height):
    print('{0}{1}  {1}'.format((height - k - 1) * ' ', (k + 1) * '#'))
