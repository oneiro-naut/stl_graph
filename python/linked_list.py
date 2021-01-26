class ListNode:
 def __init__(self, val=0, next=None):
  self.val = val
  self.next = next

class SLinkedList:
  def __init__(self):
    self.Head = None
    #self.Tail = None
    self.size = 0

  def __init__(self, list_initializer):
    self.Head = None
    self.size = 0
    curr_node = None
    for i in list_initializer:
      newnode = ListNode(i)
      if curr_node != None:
        curr_node.next = newnode
        curr_node = curr_node.next
      else:
        self.Head = newnode
        curr_node = self.Head
      self.size += 1

  def appendTail(self, val):
    newnode = ListNode(val)
    if self.Head == None:
      self.Head = newnode
      return
    curr_node = self.Head
    while curr_node.next != None:
      curr_node = curr_node.next
    curr_node.next = newnode
    self.size += 1

  def appendHead(self, val):
    newnode = ListNode(val, self.Head)
    self.Head = newnode
    self.size += 1

  def deleteHead(self):
    if self.Head != None:
      self.Head = self.Head.next
      self.size -= 1 

  def deleteTail(self): #can use a tail reference to make it constant time
    if self.Head == None:
      return
    if self.Head.next == None:
      self.Head = None
      self.size -= 1
      return
    curr_node = self.Head
    while curr_node.next.next != None:
      curr_node = curr_node.next
    curr_node.next = None
    self.size -= 1

  def getMiddleNode(self):
    if self.Head == None:
      return None
    node_fast = self.Head
    node_slow = self.Head
    while node_fast.next != None and node_fast.next.next != None:
      node_fast = node_fast.next.next
      node_slow = node_slow.next
    return node_slow
    
  # def getMiddleNode(self, head, tail):
  #   if head == None:
  #     return None
  #   node_fast = head
  #   node_slow = head
  #   while node_fast.next != tail and node_fast.next.next != tail:
  #     node_fast = node_fast.next.next
  #     node_slow = node_slow.next
  #   return node_slow
  
  def printList(self):
    curr_node = self.Head
    while curr_node != None:
      print(curr_node.val, end="-> ")
      curr_node = curr_node.next
    print("None")