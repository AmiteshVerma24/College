class Time:
    def __init__(self, h, m, s):
        self.h = h
        self.m = m
        self.s = s
    def __add__(self,other):
        t =Time(self.h+other.h, self.m+other.m, self.s+other.s)
        return t
t1 = Time(1,1,1)
t2 = Time(2,2,2)
t3 = t1+t2
print(t3.h)