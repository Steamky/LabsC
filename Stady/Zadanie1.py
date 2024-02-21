# # задача 1
a = [1,2,3,4,5,5,5,6,7,7,8,9,9,9]
b = []
for h in a:
    if h not in b:
        b.append(h)
b.sort()       
for i in b:
    k = 0
    for n in range (len(a)):
        if i == a[n]:
            k += 1

    print(i, k) 
# Задача 2
print('x y z w')
for x in 0,1:
    for y in 0,1:
        for z in 0,1:
            for w in 0,1:
                if ((x and y) or (y and z)) == ((not(x) or w) and (not(w) or z)):
                    print(x,y,z,w)
#   x,y,z,w
#1  0 0 0 1         X W Z Y
#2  0 1 0 1     #4  0 1 1 1
#3  0 1 1 0     #1  0 1 0 0
#4  0 1 1 1     #2  0 1 0 1
#5  1 0 0 0
#6  1 0 0 1
#7  1 0 1 0
#8  1 1 1 1
# Задача 3
print('[O, L, A, I]')
import itertools
places= [1,2,3,4]
def Nina  (O,L): return (O==1) != (L==2)
def Tanya (O,A): return (O==2) != (A==3)
def Dasha (A,I): return (A==4) != (I==2)
def proverka(mesto):
    O, L, A, I = mesto
    return Nina(O,L) and Tanya(O,A) and Dasha(A,I)
def refresh():
    for mesto in itertools.permutations(places):
        if proverka(mesto): print(mesto)
refresh()
                    