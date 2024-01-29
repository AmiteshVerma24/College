# Given a list of tuples. Write a program to filter all uppercase characters’
# tuples from given list of tuples. (Input: test_list = [(“GFG”, “IS”, “BEST”),
# (“GFg”, “AVERAGE”), (“GfG”,), (“Gfg”, “CS”)], Output: [(„GFG‟, „IS‟,BEST‟)]). 

test_list = [("GFG", "IS", "BEST"), ("GFg","AVERAGE"), ("GfG"), ("Gfg", "CS")]
lst = []
for tup in test_list:
    f = True
    for word in tup:
        if(not word.isupper()):
            f = False
    if f:
        lst.append(tup)
print(lst)