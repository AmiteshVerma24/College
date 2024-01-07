with open("students.txt", "a+") as f:
    while True:
        ch = input(">>> ")
        if ch:
            f.write(ch + "\n")
        else:
            break

