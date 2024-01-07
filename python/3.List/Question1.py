# Read a list of numbers and print the numbers divisible by x but not by y (Assume x = 4 and y = 5).
x = 4
y = 5
lst = []
n = int(input("Enter the number of elements: "))
for i in range (0, n):
    ele = int(input(f"Enter the element at index {i+1}: "))
    lst.append(ele)
for i in range (0 , n):
    if(lst[i] % x == 0 and lst[i] % y != 0):
        print(lst[i])