#following code is based on the 
#linked list we made in class
class Node:
  def __init__(self, val):
    self.data = val
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None
    self.tail = None
    #donejls

  # adding a data item
  def insert(self, val):
    newnode = Node(val)
    newnode.next = self.head
    self.head = newnode
    if self.tail == None:
      self.tail = newnode
    #node_x = MyNode(x)
    #node_x.next_node = self.start
    #self.start = node_x
    #done

  # Traversing over the linked list
  def traverse(self):
    currentnode = self.head
    while currentnode != None:
      print(currentnode.data)
      currentnode = currentnode.next
    #ptr = self.start
    #while ptr != None:
    #  print(ptr.data)
    #  ptr = ptr.next_node
    #

  # Remove from list
  def pop(self):
    #self.head = self.next
    #self.start = self.start.next_node
    nodetoremove = self.head
    if nodetoremove.data != None:
      while nodetoremove.next != None:
        nodetoremove = nodetoremove.next
      nodetoremove
    