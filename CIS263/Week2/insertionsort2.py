def insertsort(numlist):
    i=1
    while i < len(numlist):
        numholder1 = numlist[i]
        j=0
        while j < i:
            if numlist[i] < numlist[j]:
                numlist.pop(i)
                numlist.insert(j, numholder1)
                break
            j+=1
        i+=1
    print(numlist)


    

insertsort([5,4,3,2,1])
insertsort([1,3,6,2,7])

#best: n
#avg: n^2
#worst: n^2