# Given a dictionary, write a program to find the sum of all items in the
# dictionary. 

my_dict = dict()
my_dict["a"] = 1
my_dict["b"] = 2
my_dict["c"] = 3
my_dict["d"] = 4
sum = 0
print("Original dictionary: ", my_dict)
for key in my_dict:
    sum += my_dict[key]
print("The sum is: ", sum)