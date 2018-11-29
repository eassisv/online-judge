while True:
    s = ''
    try:
        s = input()
    except EOFError:
        break;
    if len(s):
        if s[0] == 'e': print("ingles")
        if s[0] == 'd': print("frances")
        if s[0] == 'n': print("portugues")
        if s[0] == 'a': print("caiu")


