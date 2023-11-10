class node():
    def __init__(self, data:int):
        self.val = data
        self.left = None
        self.right = None

    def print_inorder(self, n = None):
        cur = self
        if n:
            cur = n
        if cur:
            if cur.left:
                self.print_inorder(cur.left)
            print(cur.val, "\t", end="")
            if cur.right:
                self.print_inorder(cur.right)

    def print_inorder_stack(self, n = None):
        Stk = []
        cur = self
        if n:
            cur = n
        while cur or len(Stk) > 0:
            while cur:
                Stk.insert(0, cur)
                cur = cur.left
            cur = Stk.pop(0)
            print(cur.val, "\t", end="")
            cur = cur.right

'''
            1 (root)
           / \
          2   3
         /   / \
        4   5   6
         \
          7

    Inorder: 4 7 2 1 5 3 6 
'''

root = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)
n6 = node(6)
n7 = node(7)

root.left = n2
root.right = n3
n2.left = n4
n4.right = n7
n3.left = n5
n3.right = n6

print("root.print_inorder()")
root.print_inorder()
print("\nroot.print_inorder_stack()")
root.print_inorder_stack()
print()