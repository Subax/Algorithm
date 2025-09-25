while 1:
    a, b = input().split()

    index = a in b
    if index != False:
        print("Yes")
    else:
        print("No")
