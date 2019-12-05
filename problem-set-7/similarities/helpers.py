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

    aList = sent_tokenize(a)
    bList = sent_tokenize(b)
    sentanceMatch = []

    for x in aList:
        for y in bList:
            if x == y:
                if y not in sentanceMatch:
                    sentanceMatch.append(y)

    return sentanceMatch


def substrings(a, b, n):

    counter = 0

    stringMatch = []

    while counter < len(a) - n + 1:
        if a[counter:counter+n] in b:
            if a[counter:counter+n] not in stringMatch:
                stringMatch.append(a[counter:counter+n])
        counter += 1

    return stringMatch
