# Write a program to create a dictionary and apply the following methods:
# o pop() method
# o popitem() method
# o clear() method 


my_dict = dict()
my_dict["a"] = 1
my_dict["b"] = 2
my_dict["c"] = 3
my_dict["d"] = 4
print("Original dictionary: ", my_dict)

key_to_pop = "a"
if key_to_pop in my_dict:
    my_dict.pop(key_to_pop)
print("After popping: ", my_dict)

my_dict.popitem()
print("After pop item: ", my_dict)

my_dict.clear()
print("After clear: ", my_dict)