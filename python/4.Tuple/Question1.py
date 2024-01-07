lst = [(6, 24, 12), (60, 12, 6), (12, 18, 21)]
k = 6
new_lst=[]
for tup in lst:
    f = True
    for ele in tup:
        if(ele % k != 0):
            f = False
    if f:
        new_lst.append(tup)
print(new_lst)