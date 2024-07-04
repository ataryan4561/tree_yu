class Node:
    def __init__(self,val):
        self.val = val
        self.leftChild = None
        self.rightChild = None
    
    def insert(self, val):
        if val < self.val:
            if self.leftChild:
                self.leftChild.insert(val)
            else:
                self.leftChild = Node(val)
                return
        else:
            if self.rightChild:
                self.rightChild.insert(val)
            else:
                self.rightChild = Node(val)
                return
    
    def search(self,val):
        if val<self.val:
            if self.leftChild:
                self.leftChild.search(val)
            else:
                return False
        elif val>self.val:
            if self.rightChild:
                self.rightChild.search(val)
            else:
                return False 
        else:
            return True
        return False
    
    def delete(self,val):
        if val<self.val:
            if self.leftChild:
                self.leftChild.delete(val)
            else:
                print("The value is not found")
                return False
        elif val>self.val:
            if self.rightChild:
                self.rightChild.delete(val)
            else:
                print("The value is not found")
                return False
        else:
            if self.leftChild is None and self.rightChild is None:
                self = None
                return  None
            elif self.leftChild is None:
                temp = self.rightChild
                self = None
                return temp
            elif self.rightChild is None:
                temp = self.leftChild
                self  = temp
                return temp
            else:
                current  =  self.rightChild
                while(current.leftChild is not None):
                    current = current.leftChild
                self.val = current.val
                self.rightChild = self.rightChild.delete(current.val)
        return self

class BinarySeachTree:
    def __init__(self,val):
        self.root = Node(val)

    def insert(self,val):
        if self.root:
            return self.root.insert(val)
        else:
            self.root = Node(val)
            return True 
        
    def search(self,val):
        if self.root:
            return  self.root.search(val)
        else:
            return False

    def delete(self,val):
        if self.root:
            return  self.root.search(val)
        else:
            return False
        
def pre_order(node):
    while node is not None:
        print(node.val)
        pre_order(node.leftChild)
        pre_order(node.rightChild)

def find_min(root):
    if root.left is None and root.right is None:
        return root.data
    elif root.right is None:
        while root.left is not None:
            root=root.left
        return root.data
    elif root.left is None:
        return root.data
    else:
        while root.left is not None:
            root = root.left
        return root.data

lst = list()
def sorti(root):
    if root is None:
        return None
    sorti(root.left)
    lst.append(root.data)
    sorti(root.right)
def find_kth_max(root, k):
    sorti(root)
    return lst[len(lst)-k]

def helper(root,k,res):
    if root is None:
        return  False
    elif root.data == k:
        return True
    leftans = helper(root.left,k,res)
    if leftans:
        res.append(root.data)
        return  True
    rightans = helper(root.right,k,res)
    if rightans:
        res.append(root.data)
        return True
    
    return False
        
def find_ancestors(root, k):
    res = []
    helper(root,k,res)
    return res

def find_height(root):
    if root is None:
        return 0
    lefthe  = find_height(root.left)
    righthe = find_height(root.right)
    return max(lefthe,righthe)+1

def find_k_nodes(root, k):
    res = []
    helper(root,k,res)
    return res

def helper(root,k,res):
    if root is None:
        return
    if k==0:
        res.append(root.data)
        return
    else:
        helper(root.left,k-1,res)
        helper(root.right,k-1,res)