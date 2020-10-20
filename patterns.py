def pyramid(max):
    count=0
    line=1
    if(max%2==0):
        max+=1
    for m in range(1,max):
        if(m%2==1):
            count=count+1
    for i in range(0,count+1):
            for j in range(0,count):
                print(" ",end=" ")
            for k in range(0,line):
                print("*",end=" ")
            print("\n")
            line+=2
            count-=1

def pyramid2(max):
    count=0
    line=1
    if(max%2==0):
        max+=1
    for m in range(1,max):
        if(m%2==1):
            count=count+1
    for i in range(0,count+1):
            if(line==max):
                for b in range(0,max):
                    print("*",end=" ")
            else:
                for j in range(0,count):
                    print(" ",end=" ")
                for k in range(1,line):
                    if(k==1):
                        print("*",end=" ")
                    else:
                        print(" ",end=" ")
                print("*",end=" ")
            print("\n")
            line+=2
            count-=1
def tri(max):
    for j in range(1,max+1):
        for f in range(0,j):
                print("*",end=" ")
        print("\n")

def reverse_tri(max):
    for j in range(max,0,-1):
        for f in range(0,j):
                print("*",end=" ")
        print("\n")
def diamond(max):
    count=0
    line=1
    sp=0
    if(max%2==0):
        max+=1
    for m in range(1,max):
        if(m%2==1):
            count=count+1
    count+=1
    for i in range(0,count):
        for j in range(1,count):
            print(" ",end=" ")
        for k in range(0,line):
            print("*",end=" ")
        print("\n")
        line+=2
        count-=1
        sp+=1
    line-=4
    for r in range(1,sp):
        for j in range(0,count+1):
             print(" ",end=" ")
        for k in range(0,line):
            print("*",end=" ")
        print("\n")
        line-=2
        count+=1
            
def hollow_left_arrow(max):
    sp=max
    line=1
    for i in range(max,0,-1):
        for j in range(1,sp):
            print(" ",end=" ")
        for k in range(1,line):
            if(k==1):
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print("*",end=" ")
        print("\n")
        line+=1
        sp-=1
    sp+=1
    line=max-1
    for u in range(max,1,-1):
        for j in range(0,sp):
            print(" ",end=" ")
        for k in range(1,line):
            if(k==1):
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print("*",end=" ")
        print("\n")
        line-=1
        sp+=1
def left_bisected_arrow(max):
    sp=max
    line=1
    for i in range(max,1,-1):
        for j in range(1,sp):
            print(" ",end=" ")
        for k in range(1,line):
            if(k==1):
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print("*",end=" ")
        print("\n")
        line+=1
        sp-=1
    for o in range(0,max):
        print("*",end=" ")
    print("\n")
    line-=1
    for u in range(max,1,-1):
        for j in range(0,sp):
            print(" ",end=" ")
        for k in range(1,line):
            if(k==1):
                print("*",end=" ")
            else:
                print(" ",end=" ")
        print("*",end=" ")
        print("\n")
        line-=1
        sp+=1
def christmas_tree(max):
    
    if(max%2==0):
        max+=1
    for h in range(0,max):
        count=0
        line=1
        for m in range(1,max):
            if(m%2==1):
                count=count+1
        for i in range(0,count+1):
            for j in range(0,count):
                print(" ",end=" ")
            for k in range(0,line):
                print("*",end=" ")
            print("\n")
            line+=2
            count-=1
    line-=5
    for s in range(0,max):
        for a in range(0,2):
            
            print(" ",end=" ")
        for j in range(1,line):
            print("*",end=" ")

        
        print("\n")
def star_of_david(max):
    if(max%2==0):
        max+=1
    
    mid=int(round(((max-(max/4))/4)+1))
    line=1
    for i in range(0,mid):
        for j in range(1,int(((max+1)/2)-i)):
            print(" ",end=" ")
        for k in range(0,line):
                print("*",end=" ")
        line+=2
        sta=line
        print("\n")
    line-=2
    star=max-line
    stars=int((max-line)/2)
    st=max
    for r in range(0,stars):
        for p in range(0,r):
            print(" ",end=" ")
        for e in range(st,0,-1):
            print("*",end=" ")
        for o in range(0,r):
                print(" ",end=" ")
        print("\n")
        st-=2
    st+=2
    for t  in range(stars,1,-1):
        for s in range(1,t):
            print(" ",end=" ")
        for b in range(0,st):
            print("*",end=" ")
        for c in range(1,t):
                print(" ",end=" ")
        print("\n")
        st+=2
    sta-=2
    for i in range(mid,0,-1):
        for j in range(int(((max+1)/2)-i),0,-1):
            print(" ",end=" ")
        for k in range(0,sta):
                print("*",end=" ")
        for v in range(int(((max+1)/2)-i),0,-1):
            print(" ",end=" ")
        sta-=2
        print("\n")
        


    
def hollow_bisected_pyramid(max):
    count=0
    line=1
    if(max%2==0):
        max+=1
    for m in range(1,max):
        if(m%2==1):
            count=count+1
    for i in range(0,count+1):
            for j in range(0,count):
                print(" ",end=" ")
            if(i==0):
                print("*",end=" ")
            else:
                if(line==max):
                    for t in range(0,line):
                        print("*",end=" ")
                else:
                    print("*",end=" ")
                    f=int(line/2)
                    for k in range(1,f):
                        print(" ",end=" ")
                    print("*",end=" ")
                    for n in range(1,f):
                        print(" ",end=" ")
                    print("*",end=" ")
            print("\n")
            line+=2
            count-=1  
                
def star(max):
    if(max%2==0):
        max+=1
    
    mid=int(round(((max-(max/4))/4)+1))
    print(mid)
    print(max)
    line=1
    for i in range(0,mid):
        for j in range(1,int(((max+1)/2)-i)):
            print(" ",end=" ")
        for k in range(0,line):
                print("*",end=" ")
        line+=2
        print("\n")
    line-=2
    star=max-line
    stars=int((max-line)/2)
    st=max
    for r in range(0,stars):
        for p in range(0,r):
            print(" ",end=" ")
        for e in range(st,0,-1):
            print("*",end=" ")
        for o in range(0,r):
                print(" ",end=" ")
        print("\n")
        st-=2
    st+=2
    for t  in range(stars,1,-1):
        for s in range(1,t):
            print(" ",end=" ")
        for b in range(0,st):
            print("*",end=" ")
        for c in range(1,t):
                print(" ",end=" ")
        print("\n")
        st+=2
    
answer='yes'
while(answer=='yes'):
    print(" Select option for printing")
    inn=int(input(" Enter 1 for pyramid\n Enter 2 for diamond\n Enter 3 for hollow left arrow\n Enter 4 for hollow left arrow\n Enter 5 for christmas tree\n Enter 6 for star of david\n Enter 7 for hollow_bisected_pyramid\n Enter 8 for star\n"))
    if(inn==1):
        max=int(input("Enter max num of stars /n"))
        pyramid(max)
    elif(inn==2):
        max=int(input("Enter max num of stars /n"))
        diamond(max)
    elif(inn==3):
        max=int(input("Enter max num of stars /n"))
        hollow_left_arrow(max)
    elif(inn==4):
        max=int(input("Enter max num of stars /n"))
        left_bisected_arrow(max)
    elif(inn==5):
        max=int(input("Enter max num of stars /n"))
        christmas_tree(max)
    elif(inn==6):
        ans=True
        while(ans):
            max=int(input("Enter max num of stars.Num of stars should be greater than 14 /n"))
            if(max>14):
                star_of_david(max)
                ans=False
    elif(inn==7):
        max=int(input("Enter max num of stars /n"))
        hollow_bisected_pyramid(max)
    elif(inn==8):
        ans=True
        while(ans):
            max=int(input("Enter max num of stars.Num of stars should be greater than 14 /n"))
            if(max>14):
                star(max)
                ans=False
    else:
        print("Wrong Input")
    answer=input("Do You want have another run (yes/no): ")
