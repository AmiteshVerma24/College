# Read a list of numbers and print numbers present in odd index position. (Ex:
# [10, 25, 30, 47, 56, 84, 96], The numbers in odd index position: 25 47 84).

lst = []
n = int(input("Enter the number of elements: "))
for i in range (0, n):
    ele = int(input(f"Enter the element at index {i+1}: "))
    lst.append(ele)
for i in range(0, len(lst)):
    if(i % 2 != 0):
        print(lst[i])