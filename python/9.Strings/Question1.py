# Given a string, write a program to check if the string is symmetrical and
# palindrome or not. A string is said to be symmetrical if both the halves of the
# string are the same and a string is said to be a palindrome string if one half
# of the string is the reverse of the other half or if a string appears same when
# read forward or backward. 

str = "racecr"
str_to_compare = str[::-1]
if(str == str_to_compare):
    print("Palindrome")
else:
    print("Not palindrome")
