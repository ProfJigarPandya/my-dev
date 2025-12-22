class EvenStream(object):
    def __init__(self):
        self.current = 0

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return

class OddStream(object):
    def __init__(self):
        self.current = 1

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return

def print_from_stream(n,stream=None):
    '''
    The Danger of Mutable Default Arguments 
    A crucial point in Python is that default arguments are evaluated only once, when the function is defined, not each time it is called. This leads to unexpected behavior when using mutable data types (like lists or dictionaries) as default values. The Correct Way (Use None): To avoid this, use None as the default value and create a new mutable object inside the function if None is passed. 
    '''
    if stream is None:
        stream = EvenStream()
    for _ in range(n):
        try:
            print(stream.get_next())
        except:
            print("Error occurred")
        finally:
            pass           

queries = int(input())
for _ in range(queries):
    stream_name, n = input().split()
    n = int(n)
    if stream_name == "even":
        print_from_stream(n)
    else:
        print_from_stream(n, OddStream())

