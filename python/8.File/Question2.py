with open("./text.txt") as file:
    data = file.read().lower()
with open("./hello.txt", "w+") as file:
    file.write(data)
    