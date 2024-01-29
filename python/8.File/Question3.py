# Write a Python program to store N student‟s records containing name, roll
# number and branch. Print the given branch student‟s details only.
with open ("File_Question3.txt", "a+") as file:
    while True:
        ch = input(">>> ")
        if(ch):
            file.write(ch + "\n")
        else:
            break

