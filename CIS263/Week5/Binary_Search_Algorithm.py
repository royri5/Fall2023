#defining recursive binary search
def binarysearch(numlist, querynum, startindex):
    #check if list is empty
    if len(numlist) <= 0:
        return "Querynum not found"
    
    #base case
    if len(numlist) == 1:
        if numlist[0] == querynum:
            return "Querynum at index: " + str(startindex)

        else:
            return "Querynum not found"
        
    #recursive case
    else:
        #check if querynum is at middle index
        middleindex = (int)(len(numlist)/2)
        if numlist[middleindex] == querynum:
            return "Querynum at index: " + str(startindex + middleindex)
        
        #check if querynum is less than middle index
        elif numlist[middleindex] > querynum:
            #call binarysearch on first half of list
            return binarysearch(numlist[0:middleindex], querynum, startindex)
        
        #check if querynum is greater than middle index
        elif numlist[middleindex] < querynum:
            #call binarysearch on second half of list
            return binarysearch(numlist[middleindex:len(numlist)], querynum, startindex + middleindex)


#regular test
print(binarysearch([1,2,3,4,5,6,7,8,9,10], 5, 0))

#edge case tests
print(binarysearch([1,2,3,4,5,6,7,8,9,10], 1, 0))
print(binarysearch([1,2,3,4,5,6,7,8,9,10], 10, 0))
#not found tests
print(binarysearch([1,2,3,4,5,6,7,8,9,10], 0, 0))
print(binarysearch([1,2,3,4,5,6,7,8,9,10], 11, 0))


    
#Binary Search's average time complexity is O(logn)
#because it repeatedly divides the list in half
#until it reaches its base case, or the querynum

#Binary Search's best case is O(1), because
#the querynum is at the middle index, which is checked first

#Binary Search's worst case is also O(logn), because
#the querynum is not in the list, so it must divide the list
#in half logn times before it reaches its base case

#Binary Search's space complexity is O(1), because
#it simply recurses over the same list, and does not
#use any additional space (this implementation uses a
#middleindex variable for readability, but it is not
#necessary for functionality)