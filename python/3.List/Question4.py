# Read a list of numbers and remove the duplicate numbers from it. (Ex: Enter
# a list with duplicate elements: 10 20 40 10 50 30 20 10 80, The unique list is:
# [10, 20, 30, 40, 50, 80])

lst = []
unique_lst = []
n = int(input("Enter the number of elements: "))
for i in range (0, n):
    ele = int(input(f"Enter the element at index {i+1}: "))
    lst.append(ele)
for ele in lst:
    if(ele not in unique_lst):
        unique_lst.append(ele)
print("List: ", lst)
print("Unique: ", unique_lst)