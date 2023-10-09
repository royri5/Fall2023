
class bstNode:
  def __init__(self, x):
    self.data = x
    self.left_child = None
    self.right_child = None
    # adding parent
    self.parent = None


class myBST:
  def __init__(self): self.root = None
  def insert(self, root, key):
    # If the tree is empty, return a new node
    if root is None:
        return bstNode(key)
    # Otherwise, recur down the tree
    if key < root.data:
        root.left_child = self.insert(root.left_child, key)
        # adding parent
        root.left_child.parent = root
    else:
        root.right_child = self.insert(root.right_child, key)
        # adding parent
        root.right_child.parent = root
    # return the (unchanged) root pointer
    return root

  def pre_order(self, root):
    if root:
      print(root.data)
      self.pre_order(root.left_child)
      self.pre_order(root.right_child)

  def in_order(self, root):
    if root:
      self.in_order(root.left_child)
      print(root.data)
      self.in_order(root.right_child)

  def post_order(self, root):
    if root:
      self.post_order(root.left_child)
      self.post_order(root.right_child)
      print(root.data)

    #find min value in binary search tree
  def find_min(self, root):
        #base case
        if root.left_child is None:
            return root
        #recursive case
        else:
            return self.find_min(root.left_child)

    #delete node from binary search tree
    #cases: node has no children, node has one child, node has two children
  def delete(self, root, key):
    #base case
    if root is None:
        return root

    #if key is less than root, go left
    if key < root.data:
        root.left_child = self.delete(root.left_child, key)
    #if key is greater than root, go right
    elif key > root.data:
        root.right_child = self.delete(root.right_child, key)
    #if key is equal to root, delete root
    else:
        #case 1: no children
        if root.left_child is None and root.right_child is None:
            #checks parent to see if root is bst root
            if root.parent is None:
                self.root = None
                return
        #case 2: one child
        elif root.left_child is None:
            #checks parent to see if root is bst root
            if root.parent is None:
                self.root = root.right_child
                return
            else:
                root.right_child.parent = root.parent
                root.parent.right_child = root.right_child
                return
        elif root.right_child is None:
            #checks parent to see if root is bst root
            if root.parent is None:
                self.root = root.left_child
                return
            else:
                root.left_child.parent = root.parent
                root.parent.left_child = root.left_child
                return
        #case 3: two children
        else:
            #finds min value in right subtree
            min_node = self.find_min(root.right_child)
            #replaces root with min value
            root.data = min_node.data
            #deletes min value from right subtree
            root.right_child = self.delete(root.right_child, min_node.data)
            
    return root



    

    


my_tree = myBST()
my_tree.root = my_tree.insert(my_tree.root, 6)
my_tree.root = my_tree.insert(my_tree.root, 4)
my_tree.root = my_tree.insert(my_tree.root, 100)



my_tree.insert(None, 6)
my_tree
     

my_tree.root.data



my_tree.pre_order(my_tree.root)


my_tree.in_order(my_tree.root)


my_tree.post_order(my_tree.root)
     

my_tree.delete(my_tree.root, 4)
     

my_tree.pre_order(my_tree.root)
     

my_tree.root = my_tree.insert(my_tree.root, 8)
my_tree.root = my_tree.insert(my_tree.root, 3)


my_tree.pre_order(my_tree.root)
     

my_tree.delete(my_tree.root, 6)


my_tree.pre_order(my_tree.root)


my_tree.delete(my_tree.root, 100)
     
    
my_tree.pre_order(my_tree.root)