lst = input("Enter the list (space-separated integers): ")
x = 4
y = 5

lst = list(map(int, lst.split()))

for ele in lst:
    if ele % x == 0 and ele % y != 0:
        print(ele)
