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

def is_valid_bracket(s):
    st = Stack()
    for c in s:
        if c == "(":
            print(c, "여는 괄호 일때는 push")
            st.push(c)
        else:
            if st.empty():
                return False
            print(c, "닫는 괄호일때는 pop")
            st.pop()
    return st.empty()

st = Stack()
print()
tmp = is_valid_bracket(')((()))')
print(tmp)
print()
tmp = is_valid_bracket('((()))')
print(tmp)