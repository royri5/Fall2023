def bubblesort(numlist):
    #loops through all elements of list
    for num in numlist:
        i = 0
        #continuously swaps current element with next
        #if next# > current#
        while i+1 < len(numlist):
            #holds current element
            numholder1 = 0
            #holds next element
            numholder2 = 0

            #checks if walking off list
            #if (i+1) < len(numlist):
                #holds current and next elements for swap
            numholder1 = numlist[i]
            numholder2 = numlist[i+1]
                
                #checks if swap is needed
            if numlist[i] > numlist[i+1]:
                    #swaps elements
                numlist[i+1] = numholder1
                numlist[i] = numholder2
            i+=1
    print(numlist)
                
bubblesort([5,4,3,2,1])
bubblesort([4,6,2,7,1,83,7,2,8])

