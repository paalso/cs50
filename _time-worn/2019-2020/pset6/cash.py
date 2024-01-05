# -----------------------------------------------------------------------------
# cash.py
#
# Computer Science 50
# Problem Set 6
#
# Calculates the minimum number of coins required to give a user change
#
# 2019:
# https://docs.cs50.net/2019/x/psets/6/sentimental/cash/cash.html
# 2020:
# https://cs50.harvard.edu/x/2020/psets/6/cash/
#
# -----------------------------------------------------------------------------


from cs50 import get_float

while True:         # input the sum required to change
    cash = get_float("Change owed: ")
    if cash > 0:
        break

# converting the sum (float value) into integer
cash_in_cents = int(cash * 100)

# coins to change set
coins = [25, 10, 5, 1]

coins_to_change = 0

for coin in coins:
    coins_to_change += cash_in_cents // coin
    cash_in_cents %= coin
    if cash_in_cents == 0:
        break

print(coins_to_change)
