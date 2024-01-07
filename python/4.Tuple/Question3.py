tup = ("a","a","c","b","d")
lst = ["a","b"]
count = 0
for ele in lst:
    for tup_ele in tup:
        if tup_ele == ele:
            count = count + 1
print(count)
