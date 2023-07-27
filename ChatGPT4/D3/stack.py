

class Stack:
    arr = None
    top = 0

    def __init__(self, size = 10):
        self.arr = [0] * size

    def pop(self):
        tmp = self.arr[self.top - 1]
        self.top -= 1
        return tmp

    def push(self, data):
        self.arr[self.top] = data
        self.top += 1

    def empty(self):
        return self.top == 0

    def peek(self):
        if self.empty():
            raise Exception("Empty Stack")
        return self.arr[self.top -1]
    

st = Stack()
st.push(10)
st.push(20)
tmp = st.pop()
print(tmp)
tmp = st.pop()
print(tmp)
st.push(30)
print()
print('pop & push ->')
print(st.arr)
#pop & push

st.arr[-1] = 1
print(st.arr[-1]) #arr[-1] : 배열의 마지막s
print()
print('arr[-1] = 1 ->')


print(st.arr)
st.peek()
print(st.empty())
st.pop()
#st.peek() #top == 0 일시 에러
