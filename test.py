# import sys
# inputArr = []
# count=0
# n=None
# while 1:
#     line = sys.stdin.readline().strip('\n')
#     if n==None:
#     	n=int(line)
#     	continue
#     count+=1
#     inputArr.append(line)
#     if n==count:
#     	break;
# for i in inputArr:
# 	a=i.split(' ')
# 	a.reverse()
# 	print ' '.join(a)

# -*- coding: utf-8 -*- 

import sys

def fn(n):
    if n == 1 or n == 2:
      return 1
    else :
        i = 3
        pre = 1
        cur = 1
        sum = 0
    while i <= n:
        sum = cur + pre
        pre = cur
        cur = sum
        i += 1
    return sum



def main(argv):
    line = sys.stdin.readline()
    print(fn(int(line)))

if __name__ == "__main__":
    main(sys.argv)
import sys

def fn(n):
	if n==1 or n==2:
		return 1
	else:
		i=3
        pre=1
        cur=1
        sum=0
        while i<=n:
            sum=cur+pre
            pre=cur
            cur=sum
            i+=1
        return sum
		
  
  
def main(argv):
      line = sys.stdin.readline()
      print(fn(int(line)))
 
if __name__ == "__main__":
   main(sys.argv)