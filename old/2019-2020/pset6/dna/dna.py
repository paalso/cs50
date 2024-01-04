# -----------------------------------------------------------------------------
# dna.py
#
# Computer Science 50
# Problem Set 6
#
# Identifies a person based on their DNA
#
# 2020:
# https://cs50.harvard.edu/x/2020/psets/6/dna/
# -----------------------------------------------------------------------------


class PersonSTRS:
    def __init__(self, name, strs):
        self.name = name
        self.strs = strs

    def __str__(self):
        return f'{self.name}: {str(self.strs)}'


def longest_sequence_len(text, sample):
    """
    Returns the repeats of the longest consecutive sequence of repeated 'sample'
    substring (e.g. STR in the DNA) in the 'text'

    text: string (e.g. DNA sequence)
    sample: string (e.g. STR short sequence)

    returns: int
    """
    sample_size = len(sample)
    index = -1
    max_adjacent = 0

    while True:
        index = text.find(sample, index + 1)
        if index < 0:
            return max_adjacent

        counter = 1
        while text[index + counter * sample_size:
            index + (counter + 1) * sample_size] == sample:
            counter += 1

        if counter > max_adjacent:
            max_adjacent = counter

        index += 1 if counter == 1 else (counter + 1) * sample_size - 1


def sequence_strs_dict(sequence, strs):
    """
    Returns the dictionary
    {'STR': the repeats of the longest consecutive sequence of repeated 'STR'
    in the 'sequence' for the STRs in the list 'strs'}

    sequence: string (e.g. DNA sequence)
    strs: list of strings (e.g. list if STRs)

    returns: dictionary
    """
    d = {}
    for s in strs:
        d[s] = str(longest_sequence_len(sequence, s))
    return d


def person_by_strs(strs_database, strs_dict):
    """
    Returns the name of the person with appropriate STRs set ('strs_dict')
    if the person is in the STRS database ('strs_databas') else None

    strs_database: list of PersonSTRS objects
    strs_dict: dictionary (string -> string)

    returns: string or None
    """
    for entry in strs_database:
        if entry.strs == strs_dict:
            return entry.name


def csv_strs_reader(file_name):
    """
    Returns the DNA sequense string (given in the file 'file_name')

    file_name: string

    returns: string
    """
    with open(file_name) as f:
        return f.readline().rstrip().split(',')[1:]


def csv_database_reader(file_name):
    """
    Reads the database (given in the file 'file_name')
    and return it as a list of PersonSTRS Objects
    [PersonSTRS(name, dict {'STR':'number'})]

    file_name: string

    returns: list (of PersonSTRS objects)
    """
    import csv
    strs_list = []
    with open(file_name) as f:
        reader = csv.DictReader(f, delimiter=',')
        for line in reader:
            name = line.pop('name')
            strs = dict(line)
            strs_list.append(PersonSTRS(name, strs))
    return strs_list


def dnasequence_reader(file_name):
    """
    Reads the database (given in the file 'file_name')
    and return the list of STRs

    file_name: string

    returns: list (of strings)
    """
    with open(file_name) as f:
        return f.readline().rstrip()


def main():
    from sys import argv, exit

    if len(argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')
        exit(1)

    database_filename, sequence_filename = argv[1:]

    strs = csv_strs_reader(database_filename)
    strs_by_persons = csv_database_reader(database_filename)
    dna_sequence = dnasequence_reader(sequence_filename)

    person = person_by_strs(
        strs_by_persons,
        sequence_strs_dict(dna_sequence, strs))

    print(person if person else 'No match')


if __name__ == "__main__":
    main()
