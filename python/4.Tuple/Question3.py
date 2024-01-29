# Given a tuple and a list as input, write a program to count the occurrences of
# all items of the list in the tuple. (Input : tuple = ('a', 'a', 'c', 'b', 'd'), list = ['a',
# 'b'], Output : 3)

tup = ("a","a","c","b","d")
lst = ["a","b"]
count = 0
for ele in lst:
    for tup_ele in tup:
        if tup_ele == ele:
            count = count + 1
print(count)
