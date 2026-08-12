# given w - kilos scale
# fans of even numbers, divide watermelon in a way that each of two parts weighs even number of kilos, at the same time it isnot obligaotry that the parts are equal

w = int(input()) #take input
if(w % 2 ==0 and w != 2):
    print('YES')
else:
    print('NO')
