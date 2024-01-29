# Write a program to read a string and count the number of vowel letters and
# print all letters except 'e' and 's'. 

str = "Amitesh verma"
vowel = 0
for ch in str.lower():
    if(ch in "aeiou"):
        vowel += 1
    if(not(ch == "e" or ch == "s")):
        print(ch)