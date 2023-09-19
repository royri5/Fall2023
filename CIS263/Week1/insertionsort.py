def insertsort(numlist):
    returnlist = []
    for num in numlist:
        for retnum in returnlist:
            if num <= retnum:
                returnlist.insert(returnlist.index(retnum), num)
                break
        if len(returnlist) <= numlist.index(num):
            returnlist.append(num)
    print(returnlist)


insertsort([3,4,1,7,0,5])
insertsort([1,3,6,2,7])