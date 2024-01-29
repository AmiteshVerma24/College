# Read a list of numbers and print the numbers divisible by x but not by y (Assume x = 4 and y = 5).
x, y = 4, 5
num_of_elements = int(input("Enter number of elements: "))
lst = []
for i in range(0, num_of_elements):
    ele = int(input("Enter the element at index "+ str(i+1)+": "))
    lst.append(ele)
print("The list is: ", lst)
for num in lst:
    if(num % x == 0 and num % y != 0):
        print(num)