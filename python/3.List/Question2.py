# Read a list of numbers and print the sum of odd integers and even integers from the list.(Ex: [23, 10, 15, 14, 63], odd numbers sum =  101, even numbers sum =  24)

lst = []
n = int(input("Enter the number of elements: "))
for i in range (0, n):
    ele = int(input(f"Enter the element at index {i+1}: "))
    lst.append(ele)