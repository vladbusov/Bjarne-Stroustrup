import sys
if __name__ == "__main__":
    if param in sys.argv:
        fn = param
f = open(fn,"r")
cnt = 0
for line in f:
    cnt+=1
print (cnt)
f.close()
