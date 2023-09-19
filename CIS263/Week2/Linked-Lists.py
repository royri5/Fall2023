#following code is based on the 
#linked list we made in class
class Node:
  def __init__(self, val):
    self.data = val
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None

  # adding a data item
  def insert(self, val):
    newnode = Node(val)
    newnode.next = self.head
    self.head = newnode

  # Traversing over the linked list
  def traverse(self):
    currentnode = self.head
    while currentnode != None:
      print(currentnode.data)
      currentnode = currentnode.next

  # Remove from list
  def delete(self):
    self.head = self.head.next