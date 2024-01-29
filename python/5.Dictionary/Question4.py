# Write a program to merge two dictionaries using update() method.

my_dict_1 = dict()
my_dict_1["a"] = 1
my_dict_1["b"] = 2

my_dict_2 = dict()
my_dict_2["c"] = 3
my_dict_2["d"] = 4

print("Dictionary 1: ", my_dict_1)
print("Dictionary 2: ", my_dict_2)
my_dict_1.update(my_dict_2)
print("Dictionary 1: ", my_dict_1)
print("Dictionary 2: ", my_dict_2)