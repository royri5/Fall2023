class bstNode:
  def __init__(self, x):
    self.data = x
    self.left_child = None
    self.right_child = None
    self.parent = None
    

class myBST:
  def __init__(self):
    self.root = None

  def insert(self, root, key):
    # If the tree is empty, return a new node
    if root is None:
        return bstNode(key)
    # Otherwise, recur down the tree
    if key < root.data:
        root.left_child = self.insert(root.left_child, key)
        root.left_child = self.insert(root.left_child, key)
    else:
        root.right_child = self.insert(root.right_child, key)
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

  # function to help in complex deletion
  def find_min(self, root):
    # enter your code here
    # base case: empty tree
    if root is None:
      return None
    # base case (return case): no left child
    if root.left_child is None:
      return root
    # recurse case: left child exists
    else:
      return self.find_min(root.left_child)
  
  
  
  def delete(self, root, key):
    # base case: empty tree (also triggers if key is not found)
    if root is None:
      return
  
  
    # recurse case: (root is not the node to be deleted)
    
    # recurse case 1: key is less than root.data
    if key < root.data:
        # recurse on left subtree until key is found
      return self.delete(root.left_child, key)
    # recurse case 2: key is greater than root.data
    elif key > root.data:
        # recurse on right subtree until key is found
      return self.delete(root.right_child, key)
  
  
  
    # from here, key is equal to root.data 
    # (^^recurse case found key)
    
    
    # case 1: no children
    if root.left_child is None and root.right_child is None:
      #case 1a: subtree root is self.root
      if root == self.root:
        self.root = None
        return
      #case 1b: subtree root is not self.root
      elif root.left_child is None and root.right_child is None:
        # root is a right child
        if root.parent.right_child == root:
            root.parent.right_child = None
        # root is a left child
        else:
            root.parent.left_child = None 
        return
    
    
    
    # case 2: one child
    
    # case 2a: left child
    elif root.right_child is None:
        # case 2a1: subtree root is self.root
        if root == self.root:
            self.root = root.left_child
            root.left_child.parent = None
            return
        # case 2a2: subtree root is not self.root
        else:
            # left child takes the place of root
            root.left_child.parent = root.parent
            # updating parent-child relationship
            # root is a right child
            if root.parent.right_child == root:
                root.parent.right_child = root.left_child
                return 
            # root is a left child
            else:
                root.parent.left_child = root.left_child
                return
    # case 2b: right child
    elif root.left_child is None:
        # case 2b1: subtree root is self.root
        if root == self.root:
            self.root = root.right_child
            root.right_child.parent = None
            return
        # case 2b2: subtree root is not self.root
        else:
            # right child takes the place of root
            root.right_child.parent = root.parent
            # updating parent-child relationship
            # root is a right child
            if root.parent.right_child == root:
                root.parent.right_child = root.right_child
                return
            # root is a left child
            else:
                root.parent.left_child = root.right_child
                return
            
            
            
    # case 3: two children
    
    # case 3a: root is self.root
    if root == self.root:
        # finds the smallest value in the right subtree
        # and makes it the new root
        # then deletes it from previous location
        temp = self.find_min(root.right_child)
        self.root.data = temp.data
        self.delete(root.right_child, temp.data)
        return
    # case 3b: root is not self.root
    else:
        # same concept as above
        temp = self.find_min(root.right_child)
        root.data = temp.data
        self.delete(root.right_child, temp.data)
        return