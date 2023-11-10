class node():
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

'''
        1
       / \
      2   3
     /   / \
    4   5   6
     \
      7

Inorder traversal:      4 7 2 1 5 3 6
Preorder traversal:     1 2 4 7 3 5 6
Postorder traversal:    7 4 2 5 6 3 1 
'''

# Depth First Search 
def inorder(root: node):
    if root == None:
        return
    inorder(root.left)
    print(root.data, end="")
    inorder(root.right)

def inorderStack(root: node):
    stack = []
    curr = root
    while curr != None or len(stack) > 0:
        while curr != None:
            stack.insert(0, curr)
            curr = curr.left
        curr = stack.pop(0)
        print(curr.data, end="")
        curr = curr.right

def preorder(root: node):
    if root == None:
        return
    print(root.data, end="")
    preorder(root.left)
    preorder(root.right)

def postorder(root: node):
    if root == None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end="")

# Breadth First Search
def levelorder(root: node):
    if root == None:
        return
    Q = [root]
    while Q:
        n = Q.pop(0)
        print(n.data, end="")
        if n.left:
            Q.append(n.left)
        if n.right:
            Q.append(n.right)

# Compute and return sum of all tree nodes
# that lie in the range low -> high (inclusive)
# Use PreOrder traversal to search through tree
def findSum(root, low:int, high:int) -> int:
    result = 0
    if root != None:
        if root.data >= low and root.data <= high:
            result += root.data
        result += findSum(root.left, low, high)
        result += findSum(root.right, low, high)
    return result

# Determine if a path to any leaf of the tree adds up to given value
def pathSum(root: node, targetSum: int) -> bool:
    if root == None:
        return False
    if root.left == None and root.right == None:
        return root.data == targetSum
    if root.left != None and pathSum(root.left, targetSum - root.data):
        return True
    if root.right != None and pathSum(root.right, targetSum - root.data):
        return True
    return False
    


n1 = node(1)
n2 = node(2)
n3 = node(3)
n4 = node(4)
n5 = node(5)
n6 = node(6)
n7 = node(7)

root = n1
n1.left = n2
n1.right = n3
n2.left = n4
n4.right = n7
n3.left = n5
n3.right = n6

# Depth First Search - DFS
print("inorder: ", end="")
inorder(root)
print()
print("inorder stack: ", end="")
inorderStack(root)
print()
print("preorder: ", end="")
preorder(root)
print()
print("postorder: ", end="")
postorder(root)
print()
# Breadth First Search - BFS
print("levelorder: ", end="")
levelorder(root)
print()

# print("Sum of tree: ", findSum(root, 1, 10))

# print("Sum path: ", pathSum(root, 18))


