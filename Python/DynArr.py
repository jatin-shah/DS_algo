class DynamicArray:
    def __init__(self, size: int):
        self.incrementsize = size
        self.size = size
        self.arr = []
        self.len = 0
    
    def size(self):
        return self.len
    
    def add(self, val: int):
        if len == self.size:
            self.size += self.incrementsize
        self.arr[self.len] = val
        self.len += 1

    def insert(self, val: int, pos: int):
        if pos > self.len:
            return -1
        elif pos == self.len:
            if pos == self.size:
                self.size += self.incrementsize
            self.arr[pos] = val
            self.len += 1
        else:
            if pos == self.size:
                self.size += self.incrementsize
            for index, insval in zip(range(self.len, pos, -1), self.arr[self.len: pos: -1]):
                self.arr[index + 1] = insval
            self.arr[pos] = val

    def pop(self, pos:int = len):
        for index, val in zip(range(pos + 1, self.len, 1), self.arr[pos + 1: self.len: 1]):
            self.arr[index - 1] = val
