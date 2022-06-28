from cs50 import get_string
from re import findall
from collections import Counter

text = get_string("Text: ")

# Total os words
words = float(text.count(' '))
# + 1 Because counting spaces get 1 less word
words += 1
# Count senteces
dot = float(text.count('.'))
exclamation = float(text.count('!'))
question = float(text.count('?'))
senteces = dot + exclamation + question

# Variables to store letters and digits
digit = 0
letter = 0
# Loop to go through the text
for i in text:
    # Count digits
    if (i.isdigit()):
        digit += 1
    # Count letters
    elif (i.isalpha()):
        letter += 1
letters = float(letter + digit)

# Getting the variables of the Coleman-Liau index.
L = float(letters * 100 // words)
S = float(senteces * 100 // words)

# Calculeting Coleman-Liau index.
tem_index = 0.0588 * L - 0.296 * S - 15.8

# Printing the grades
index = int(round(tem_index))
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

