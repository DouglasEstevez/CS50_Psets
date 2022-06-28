from cs50 import get_float


while True:
    # Get number
    money = get_float("Change owed: ")
    # Make sure to be positive
    if money > 0.00:
        break

# Trasform cents in ints
cents = money * 100

# Stores how many coins
moedas = 0
# A loop to divid each number in the list 
for coin in [25, 10, 5, 1]:
    moedas += cents // coin
    cents %= coin
print(moedas)