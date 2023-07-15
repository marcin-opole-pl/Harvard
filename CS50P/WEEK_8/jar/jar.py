class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return '🍪' * self.size

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError('Not enought room')
        self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError('Not enough cookis in the jar')
        self.size -= n

    @property
    def size(self):
        return self._size
    
    @size.setter
    def size(self, size):
        if size > self.capacity:
            raise ValueError('Wrong size')
        self._size = size

    @property
    def capacity(self):
        return self._capacity
    
    @capacity.setter
    def capacity(self, capacity):
        if not capacity >= 0:
            raise ValueError('Wrong number of cookies')
        self._capacity = capacity

def main():
    jar = Jar()
    jar.deposit(8)
    print(jar)
    jar.withdraw(1)
    print(jar)

if __name__ == "__main__":
    main()