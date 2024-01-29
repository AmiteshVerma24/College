# Write python program class TIME member hour, minute, second
# add two TIME object by using operator overloading [by using __add__ () magic method]
# Subtract add two TIME object by using operator overloading [by using __sub__ ()
# magic method.

class Time:
    def __init__(self, h, m, s):
        self.h = h
        self.m = m
        self.s = s
    def __add__(self,other):
        t =Time(self.h+other.h, self.m+other.m, self.s+other.s)
        return t
    def __sub__(self,other):
        t = Time(self.h-other.h, self.m-other.m, self.s-other.s)
        return t
    def display(self):
        print("Hour: ", self.h)
        print("Minute: ", self.m)
        print("Second: ",self.s)
t1 = Time(1,1,1)
t2 = Time(3,2,2)
t3 = t1 + t2
t4 = t2- t1
t3.display()
t4.display()
# print(t3.h)
