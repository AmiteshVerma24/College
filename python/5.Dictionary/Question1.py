# Write a program to do the following operations:
# o Create a empty dictionary with dict() method
# o Add elements one at a time
# o Update existing key‟s value
# o Access an element using a key and also get() method
# o Deleting a key value using del() method 

# Create an empty dictionary
my_dict = dict()

# Add elements one at a time
my_dict['a'] = 1
my_dict['b'] = 2
my_dict['c'] = 3

# Update existing key's value
my_dict['b'] = 5  # Updating value for key 'b'

# Access an element using a key
key_to_access = 'a'
if key_to_access in my_dict:
    value = my_dict[key_to_access]
    print(f"The value associated with key '{key_to_access}' is {value}")
else:
    print(f"Key '{key_to_access}' not found in the dictionary.")

# Using get() method to access an element
value = my_dict.get('c')
if value is not None:
    print(f"The value associated with key 'c' using get() method is {value}")
else:
    print("Key 'c' not found in the dictionary.")

# Deleting a key-value pair using del() method
key_to_delete = 'b'
if key_to_delete in my_dict:
    del(my_dict[key_to_delete])
    print(f"Key '{key_to_delete}' and its value have been deleted from the dictionary.")
else:
    print(f"Key '{key_to_delete}' not found in the dictionary.")

print("Updated Dictionary:", my_dict)
