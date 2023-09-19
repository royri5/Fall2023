#start block
class Node:
    def __init__(self, val):
        self.data = val
        #mycode
        self.subchildren = []
#end block

#defining tree class
class Tree:

    #constructor
    def __init__(self):
        self.root = None
    
    #inserting a node into the tree
    #as a child of parent tree
    def insert(self, val):
        #initializing node to be inserted
        newnode = Node(val)

        #checks if the tree is empty
        if self == None:
            #if so, sets the new node as the root
            self.root = newnode

        #otherwise, if the tree is not empty
        else:
            #sets the new node as a child of the
            #current node
            self.subchildren.append(newnode)

            #sets the parent of the new node
            #to the current node
            newnode.parent = self

            #iffy on all above code (insert), check later
    
    #traverse through a subtree
    def traverse_subtree(self, subtree):
        #checks if the subtree is empty
        if subtree == None:
            print("Subtree is empty")
            return
        else:
            #prints the data of the current subtree
            #being traversed
            #as well as which parent tree it is a child of
            print("Current subtree: " + subtree.data)
            print("Parent tree: " + self.root.data)
            #recursively calls traverse_subtree
            #on each child of each subtree
            for child in subtree.subchildren:
                self.traverse_subtree(child)
        print("End of subtree")
    
    #deletes entire subtree
    def delete_subtree(self, subtree):
        #checks if the subtree is empty
        if subtree == None:
            print("Subtree is empty")
            return
        else:
            #recursively calls delete_subtree
            #on each child of each subtree
            for child in subtree.subchildren:
                self.delete_subtree(child)
            #deletes the current subtree
            del subtree