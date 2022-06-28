import csv
import sys


def main():

    # check for correct number of arguments
    if len(sys.argv) != 3:
        print("Incorrect")

    # open files
    database = open("./" + sys.argv[1])
    dna_file = open("./" + sys.argv[2])

    # obtain STRs from header of database
    reader = csv.DictReader(database)
    strs = reader.fieldnames[1:]

    # copy contents of dna_file into string dna and close file
    dna = dna_file.read()
    dna_file.close()

    # count number of occurences of each STR in sequence.txt and store value in dict dna_fingerprint
    dna_fingerprint = {}
    for str in strs:
        dna_fingerprint[str] = consec_repeats(str, dna)

    # search through csv file to find match
    for row in reader:

        # if there is match, print name, close files, and end program
        if match(strs, dna_fingerprint, row):
            print(f"{row['name']}")
            database.close()
            return

    # if no match was found, print No match and close files.
    print("No match")
    database.close()


# repeats determines the maximum number of consecutive repeats of str in dna
def consec_repeats(str, dna):
    i = 0
    while str*(i+1) in dna:
        i += 1
    return i


# match determines whether dna_fingerprint matches row from database
def match(strs, dna_fingerprint, row):
    for str in strs:
        if dna_fingerprint[str] != int(row[str]):
            return False
    return True


main()


# def longest_match(sequence, subsequence):
# """Returns length of longest run of subsequence in sequence."""

# Initialize variables
# longest_run = 0
# subsequence_length = len(subsequence)
# sequence_length = len(sequence)

# Check each character in sequence for most consecutive runs of subsequence
# for i in range(sequence_length):

# Initialize count of consecutive runs
# count = 0

# Check for a subsequence match in a "substring" (a subset of characters) within sequence
# If a match, move substring to next potential match in sequence
# Continue moving substring and checking for matches until out of consecutive matches
# while True:

# Adjust substring start and end
# start = i + count * subsequence_length
# end = start + subsequence_length

# If there is a match in the substring
# if sequence[start:end] == subsequence:
# count += 1

# If there is no match in the substring
# else:
# break

# Update most consecutive matches found
#longest_run = max(longest_run, count)

# After checking for runs at each character in seqeuence, return longest run found
# return longest_run


main()
