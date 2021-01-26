import linked_list as ll

def split_list(head):
  if head == None:
    return None
  if head.next == None:
    return head
  mid = getMiddleNode(head)
  rhead = mid.next
  mid.next = None
  #printNodes(head)
  #printNodes(rhead)
  lhead = split_list(head)
  rhead = split_list(rhead)
  merged_head = merge_lists(lhead, rhead)
  #printNodes(merged_head)
  return merged_head

def printNodes(head):
  while head != None:
    print(head.val, end=' ')
    head = head.next
  print('')

def merge_lists(lhead, rhead):
  if lhead == None:
    return rhead
  if rhead == None:
    return lhead
  lnode = lhead
  rnode = rhead
  lprev = None
  while lnode != None and rnode != None:
    if lnode.val >= rnode.val:
      temp = rnode.next
      rnode.next = lnode
      if lprev != None:
        lprev.next = rnode
        lprev = lprev.next
      else:
        lprev = rnode
        lhead = rnode
      rnode = temp
    else:
      lprev = lnode
      lnode = lnode.next
  if lnode == None and lprev != None:
    lprev.next = rnode
  return lhead  

    
def getMiddleNode(head):
  if head == None:
    return None
  node_fast = head
  node_slow = head
  while node_fast.next != None and node_fast.next.next != None:
    node_fast = node_fast.next.next
    node_slow = node_slow.next
  return node_slow


def mergesort(s_list):
  s_list.Head = split_list(s_list.Head)
