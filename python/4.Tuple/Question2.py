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