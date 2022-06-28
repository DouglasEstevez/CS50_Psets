from cs50 import get_int


def main():
    height = get_height()
    print_pyramid(height)


def get_height():
    # Infinte loop to prompt for a valid number
    while True:
        # Prompt for a number
        height = get_int("Height: ")
        # Making sure is a valid number
        if height > 0 and height <= 8:
            # Break the loop if is a valid number
            break
    # Return de value
    return height


def print_pyramid(height):
    # For i in range(0, height, +1):
    # Loop so can print the rows
    i = 0
    # Loop to print the empty spaces
    for j in range(height - 1, -1, -1):
        # To adjust the varible to print the right amount of #
        i += 1
        # Print space * the varible j, j decrease every row
        print(" " * j, end="")
        # Print # * i, i increase every row
        print("#" * i, end="")
        # Print the two spaces empty between the to pyramids
        print("  ", end="")
        # Print the second pyramid
        print("#" * i, end="")
        # Next row
        print()
        # When the iner loop ends the two pyramids will be completed so we need to break the loop
        if i == height:
            break


main()
