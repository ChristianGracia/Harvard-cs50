from nltk.tokenize import sent_tokenize
import re

def lines(a, b):
    """Return lines in both a and b"""

    linesA = a.split("\n")
    linesB = b.split("\n")
    linesMatch = []

    counter = 0
    while counter < len(linesA):
        flag = True
        for x in linesA:
            for y in linesB:
                if x != y:
                    flag = False
        if flag == True:
            linesMatch.append(linesA)

        counter += 1

    for c in linesA:
      print(c);
    for c in linesB:
      print(c);
    for c in linesMatch:
       print(c);


    return linesMatch


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    return []


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    return []
