# Write a program to read a line of text and remove the initial word from given
# text. (Hint: Use split() method, Input : India is my country. Output : is my
# country)

str = "India is my country"
final_str = ""
str_as_lst = str.split()
print(str_as_lst)
for i in range (1, len(str_as_lst)):
    final_str = final_str + str_as_lst[i] + " "
print(final_str)