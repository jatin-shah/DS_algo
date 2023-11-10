class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_LL(head: Node):
    n = head
    size = 0
    while n != None:
        print(n.data, "->", end="")
        size += 1
        n = n.next
    print("NULL (", size, ")")
    
def insert_at_head(head: Node, val: int) -> Node:
    nn = Node(val)
    nn.next = head
    return nn

def insert_at_end(head: Node, val: int) -> Node:
    nn = Node(val)
    n = head
    while n.next != None:
        n = n.next
    n.next = nn
    return head

def insert_at(head: Node, val: int, pos: int) -> Node:
    nn = Node(val)
    n = head
    index = 0
    prevn = None
    nextn = head
    while index < pos:
        if n == None:
            raise "Insert position out of range!!"
        prevn = n
        n = n.next
        nextn = n
        index += 1

    if pos > 0:
        prevn.next = nn
    nn.next = nextn
    if pos == 0:
        return nn
    else:
        return head

def find_value(head: Node, val: int) -> bool:
    n = head
    while n != None:
        if n.data == val:
            return True
        n = n.next
    return False

def remove_at(head: Node, pos: int) -> Node:
    if head == None:
        raise "No Linked list provided to remove from!!"
    index = 0
    prevn = None
    currn = head
    while index < pos:
        if currn == None:
            raise "Remove position out of range!!"
        prevn = currn
        currn = currn.next
        index += 1

    if pos > 0:
        prevn.next = currn.next
        return head
    elif pos == 0:
        return currn.next
    else:
        return None

def kth_from_end(head: Node, k: int) -> Node:
    n = head
    curidx = 0
    prev = None
    while n != None:
        if prev == None:
            prev = n
            previdx = 0
        if curidx - previdx == k:
            if n.next == None:
                return prev
            prev = prev.next
            previdx += 1
        n = n.next
        curidx += 1
    return None

def middle_node(head: Node) -> Node:
    if head == None:
        return None
    middle = head
    last = head
    while last != None and last.next != None:
        middle = middle.next
        last = last.next.next
    return middle

def has_loop(head: Node) -> bool:
    if head == None: 
        return None
    fast = head
    slow = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
    
def loop_first_node(head: Node) -> Node:
    if head == None: 
        return None
    fast = head
    slow = head
    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break
    if slow != fast:
        return None
    
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    return fast
    
    

print_LL(None)
n = Node(5)
print_LL(n)
n = insert_at_end(n, 8)
print_LL(n)
n = insert_at_head(n, 0)
print_LL(n)
n = insert_at(n,3, 1)
print_LL(n)
n = insert_at(n, 2, 0)
print_LL(n)
n = insert_at(n, 9, 4)
print_LL(n)
n = insert_at(n, 15, 6)
print_LL(n)
n = insert_at(n, 12, 7)
print_LL(n)
n = insert_at(n, 27, 0)
print_LL(n)
n = remove_at(n, 1)
print_LL(n)
print('{} present in LL: {}'.format(12, find_value(n, 12)))
n = remove_at(n, 7)
print_LL(n)
print('{} present in LL: {}'.format(12, find_value(n, 12)))
n = remove_at(n, 0)
print_LL(n)
print(f'node 2 from end has value {kth_from_end(n, 2).data}')
print(f'node 1 from end has value {kth_from_end(n, 1).data}')
#print(f'node 4 from end has value {kth_from_end(n, 4).data}')
#print(f'node 0 from end has value {kth_from_end(n, 0).data}')
#print(f'node 5 from end has value {kth_from_end(n, 5).data}')
print(f'middle node has value {middle_node(n).data}')
n = insert_at_end(n, 55)
print_LL(n)
print(f'middle node has value {middle_node(n).data}')
n = insert_at_end(n, 22)
print_LL(n)
print(f'middle node has value {middle_node(n).data}')
print(f'LL n has loop: {has_loop(n)}')

n0 = Node(0)
n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)
n5 = Node(5)
n6 = Node(6)
n7 = Node(7)
n8 = Node(8)
n0.next = n1
n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6
n6.next = n7
n7.next = n8
n8.next = n7
# print_LL(n0)
print(f'LL n0 has loop: {has_loop(n0)}')
a = loop_first_node(n0)
if a == None:
    print("n0 LL does not have a loop")
else:
    print("n0 LL has a loop which begins at node with value - ", a.data)

