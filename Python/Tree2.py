class node():
    def __init__(self, val: int):
        self.data = val
        self.left = None
        self.right = None

    def print_inorder(self, n = None):
        cur = None
        if n != None:
            cur = n
        else:
            cur = self
        if cur.left:
            self.print_inorder(cur.left)
        print(cur.data, " ", end="")
        if cur.right:
            self.print_inorder(cur.right)

    def print_inorder_stack(self):
        cur = self
        stack = []
        while cur or len(stack) > 0:
            while cur:
                stack.insert(0, cur)
                cur = cur.left
            cur = stack.pop(0)
            print(cur.data, " ", end="")
            cur = cur.right

    def print_preorder(self, n = None):
        cur = None
        if n != None:
            cur = n
        else:
            cur = self
        print(cur.data, " ", end="")
        if cur.left:
            self.print_preorder(cur.left)
        if cur.right:
            self.print_preorder(cur.right)

    def print_postorder(self, n = None):
        cur = None
        if n != None:
            cur = n
        else:
            cur = self
        if cur.left:
            self.print_postorder(cur.left)
        if cur.right:
            self.print_postorder(cur.right)
        print(cur.data, " ", end="")

    def print_levelorder(self):
        cur = self
        Q = []
        Q.append(cur)
        while len(Q) > 0:
            cur = Q.pop(0)
            print(cur.data," ", end="")
            if cur.left != None:
                Q.append(cur.left)
            if cur.right != None:
                Q.append(cur.right)
        
    def insert_level_order(self, val = None):
        Q = []
        Q.append(self)

        while len(Q) > 0:
            cur = Q.pop(0)
            if cur.left == None:
                cur.left = node(val)
                return
            elif cur.right == None:
                cur.right = node(val)
                return
            else:
                Q.append(cur.left)
                Q.append(cur.right)

    def find_sum(self, low, high, n = None)->int:
        result = 0
        cur = None
        if n != None:
            cur = n
        else:
            cur = self
        if cur:
            if cur.data >= low and cur.data <= high:
                result += cur.data
            if cur.left and cur.data > low:
                result += self.find_sum(low, high, cur.left)
            if cur.right and cur.data < high:
                result += self.find_sum(low, high, cur.right)
        return result


# Main loop
'''
            1
           / \
          2   3
             /
            4
        
Inorder:   2 1 4 3
'''
'''
n1 = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)

root = n1
n1.left = n2
n1.right = n3
n3.left = n4

root.print_inorder()
'''
'''
            10 (root)
           /  \
         20    30
        / \      \
       40 50     70

Inorder:   40 20 50 10 30 70 
'''
'''
root = node(10)
n20 = node(20)
n30 = node(30)
n40 = node(40)
n50 = node(50)
n70 = node(70)

root.left = n20
root.right = n30
n20.left = n40
n20.right = n50
n30.right = n70

root.print_inorder()
print()

root.insert_level_order(60)
root.print_inorder()
print()
'''
'''
            1 (root)
           /  \
          2    3
         /    /
        4    5
         \
          6

Inorder:    4 6 2 1 5 3 
Preorder:   1 2 4 6 3 5
Postorder:  6 4 2 5 3 1
'''
'''
root = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)
n6 = node(6)

root.left = n2
root.right = n3
n2.left = n4
n3.left = n5
n4.right = n6

print("Inorder:\t", end="")
root.print_inorder()
print("\nInorder stack:\t", end="")
root.print_inorder_stack()
print("\nPreorder:\t", end="")
root.print_preorder()
print("\nPostorder:\t", end="")
root.print_postorder()
print("\nLevelorder:\t", end="")
root.print_levelorder()
print()
'''
'''
            10 (root)
           /  \
          5    15
         / \    \   
        3   7    18 
        

Inorder:    3 5 7 10 15 18 
Preorder:   10 5 3 7 15 18
Postorder:  3 7 5 18 15 10
Levelorder: 10 5 15 3 7 18
'''
root = node(10)
n5 = node(5)
n3 = node(3)
n7 = node(7)
n15 = node(15)
n18 = node(18)

root.left = n5
root.right = n15
n5.left = n3
n5.right = n7
n15.right = n18

print("Inorder:\t", end="")
root.print_inorder()
print("\nInorder Stack:\t", end="")
root.print_inorder_stack()
print("\nPreorder:\t", end="")
root.print_preorder()
print("\nPostorder:\t", end="")
root.print_postorder()
print("\nLevelorder:\t", end="")
root.print_levelorder()
print("\nFind Sum [4, 15]:\t", end="")
print(root.find_sum(4, 15))
print()

