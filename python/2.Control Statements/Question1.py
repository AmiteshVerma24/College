# Read your email id and write a program to display the no of vowels,
# consonants, digits and white spaces in it using if…elif…else statement. 

email = input("Enter your email address:- ")
vowel, consonent, digits, space = 0, 0, 0, 0
for ch in email:
    if(ch.isdigit()):
        digits += 1
    elif(ch in "aeiou"):
        vowel += 1
    elif(ch.isalpha()):
        consonent += 1
    else:
        space += 1
print("Number of vowel: ", vowel)
print("Number of consonent: ", consonent)
print("Number of digit: ", digits)
print("Number of special: ", space)