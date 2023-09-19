#divide and conquer sorting
def mergesort(numlist):
    #defining holder lists
    holderlist1 = []
    holderlist2 = []
    
    #check if list is empty or has one element(return case)
    if len(numlist) <= 1:
        return numlist
    else:
        #initialize counter variables
        i=0

        #j starts counting from the middle of the list
        j=(int)(len(numlist)/2)

        #populating holderlist1 with the first half of the list
        while i < (int)(len(numlist)/2):
            holderlist1.insert(i, numlist[i])
            i+=1

        #populating holderlist2 with the second half of the list
        while j < len(numlist):
            holderlist2.insert(j, numlist[j])
            j+=1
        
        #recursion calls for the "divide" part
        sortedholder1 = mergesort(holderlist1)
        sortedholder2 = mergesort(holderlist2)

        #setting the return list to the first sorted list
        #to merge the second sorted list into it
        retlist = sortedholder1

        #resetting counter variables
        i = 0
        j = 0

        #the merge part:
        #count through the second sorted list
        while i < len(sortedholder2):
            
            #resetting the counter variable for the first sorted list
            #so that it can be counted through again
            #for each element in the second sorted list
            j = 0

            #variable to check if the current element
            #in the second sorted list has been inserted
            #into the return list
            inserted = False

            #count through the return list
            #that may now be longer than the first sorted list
            #as it is may now have elements from both lists
            while j < len(retlist):

                #check if the current element in the second sorted list
                #is less than the current element in the return list
                #and if so, insert it into the return list
                #at the correct position
                if sortedholder2[i] < retlist[j]:
                    
                    #inserting the element from the second list
                    #into the return list at the correct position
                    retlist.insert(j,sortedholder2[i])

                    #since the element has been inserted
                    #sets the inserted variable to true
                    inserted = True
                    break

                #if the current element in the second sorted list
                #was not inserted into the return list
                #move to the next element in the return list
                #and check again
                j+=1

            #check if the element from the second sorted list
            #was not inserted into the return list 
            #after the entire return list has been cycled through
            #either from a break, in the case that the element
            #from the second sorted list was inserted,
            #or from the end of the return list, in the case that
            #the element from the second sorted list was not inserted
            if inserted == False:

                #in the case that the element from the second sorted list
                #was not inserted into the return list
                #append it to the end of the return list
                retlist.append(sortedholder2[i])
            #now that the current element from the second sorted list
            #has been inserted into the return list
            #at the correct position
            #move to the next element in the second sorted list
            i+=1
        return retlist


#mergesort's complexity is:
#O(nlogn) for best, average, and worst cases
#because it always divides the list in half
#and then merges the two halves together
#in a linear fashion
#and the number of times it divides the list in half
#is logn
#and the number of times it merges the two halves together
#is n
#so the complexity is O(nlogn)

#mergesort's space complexity is:
#O(n) for best, average, and worst cases
#because it 

print(mergesort([5,4,3,2,1]))
print(mergesort([1,2,3,4,5]))
print(mergesort([1,6,2,8,3,89,3,9,32]))

#merge sort's time complexity is O(nlogn) in all cases,
#this is because the time it takes to divide all the lists
#down to their return cases is O(logn) since it divides
#the list in half each time
#and the time it takes to merge all the lists back together
#is O(n) since it merges the lists together linearly
#thus when you merge n lists together after dividing them