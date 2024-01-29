# Create a new file (Hello.txt) and copy the text to other file called target.txt.
# The target.txt file should store only lower case alphabets and display the
# number of lines copied. 
with open("text.txt", "r") as file:
    data = file.read().lower()
    lines = len(data.split("\n"))
    print("Number of lines copied is: ", lines)
with open("hello.txt", "w") as file:
    file.write(data)
    