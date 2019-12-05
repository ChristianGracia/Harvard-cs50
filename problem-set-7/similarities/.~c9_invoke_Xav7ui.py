from nltk.tokenize import sent_tokenize
import re

def lines(a, b):

    linesA = a.split("\n")

    linesB = b.split("\n")
    linesMatch = []


    for x in linesA:
        for y in linesB:
            if x == y:
                if y not in linesMatch:
                    linesMatch.append(y)


    return linesMatch


def sentences(a, b):

    aList = sent_tokenize(a);
    bList = sent_tokenize(b);
    sentanceMatch = []

    for x in aList:
        for y in bList:
            if x == y:
                if y not in sentanceMatch:
                    sentanceMatch.append(y)


    return sentanceMatch


def substrings(a, b, n):

    stringMatch = []

    for x in range(0, len(a)):
        subStringA = a[x:x+n]

        if subStringA in b:
            if subStringB not in a:
                stringMatch.append(subStringA)
        for y in range(0, len(b)):
            subStringB = b[y:y+n]
            if subStringB in a:
                if subStringB not in a:
                    stringMatch.append(subStringB)
            if subStringA == subStringB:
                if subStringB not in stringMatch:
                    stringMatch.append(subStringB)

    return stringMatch
