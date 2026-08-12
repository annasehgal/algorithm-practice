n = int(input())
for i in range(n):
    string = str(input())
    stringlen = len(string)
    if stringlen > 10:
    # reference: https://www.geeksforgeeks.org/python/string-slicing-in-python/
    # basically string slicing technique, so firstly s[0:number], it does not print the last string already so i think we start from index 1
        firstchar = string[0]
        lastchar = string[-1]
        middlestr = string[1:-1]
        converter = str(len(middlestr))
        # now just add it
        abbrstr = firstchar + converter + lastchar
        print(abbrstr)

    else:
        print(string)
