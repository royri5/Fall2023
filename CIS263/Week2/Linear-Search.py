def linearsearch(numlist, querynum):
    retindex="num not found"
    i=0
    while i < len(numlist):
        if numlist[i] == querynum:
            retindex = i
        i+=1
    print(retindex)

linearsearch([1,2,3,4,5,6,7,8,9,10], 5)

#best: 1
#avg: n/2
#worst: n