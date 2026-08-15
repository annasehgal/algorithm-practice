class MyHashSet:

    def __init__(self):
        self.value = {} # dict

    def add(self, key: int) -> None:
        self.value[key] = key

    def remove(self, key: int) -> None:
        if key in self.value:
            del self.value[key]

    def contains(self, key: int) -> bool:
        if key in self.value:
            return True
        else:
            return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
