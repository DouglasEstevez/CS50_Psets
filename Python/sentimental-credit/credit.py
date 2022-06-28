from cs50 import get_string
from re import search


def main():
    credit = get_string("Number: ")
    Check(credit)


def Check(credit):
    # Check the conditions to be a AMEX
    if (len(credit) == 15 and search("^34", credit) != None or search("^37", credit) != None):
        print("AMEX")
    # Check the conditions to be a MASTERCARD
    elif len(credit) == 16 and search("^51", credit) != None or search("^55", credit) != None or search("^52", credit) != None or search("^53", credit) != None or search("^54", credit) != None:
        print("MASTERCARD")
    # Check the conditions to be a VISA
    elif (len(credit) == 16 or len(credit) == 13) and (search("^4", credit) != None):
        print("VISA")
    # If is not one of the above is invalid
    else:
        print("INVALID")


main()