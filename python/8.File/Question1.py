# Write a program to read a filename from the user, open the file (say
# firstFile.txt) and then perform the following operations: 
# • Count the sentences in the file. 
# • Count the words in the file. 
# • Count the characters in the file. 

with open("Question1.txt", "r") as f:
    data = f.read()
    print(data)
    data = data.split("\n")
    print(data)
    characters = 0
    words = 0
    for sentence in data:
        for word in sentence.split():
            characters += len(word)
    for sentence in data:
        words += len(sentence.split())
    print("Sentence in file: ",len(data))
    print("Words in file: ",words)
    print("Character in file: ",characters)