with open("text.txt", "r+") as f:
    data = f.read()
    data = data.split("\n")
    print(data.__len__())
    x = 0
    y = 0
    for l in data:
        y += l.__len__()
        x += l.split().__len__()
    print(x)
    print(y)
