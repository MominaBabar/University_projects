global x
global y
global z
global k 
global j
global ID 
global level
global sub
global rewards
global saved 
global users
global password
global balance
global ac_list
global ad_ist
global ar_list
global bo_list
global ca_list
global cas_list
global cas_rlist
global s_rlist
global s_plist
global lo
def login():
    f = True
    while(f==True):
        y = input("enter email.")
        z = input("enter password")
        j = len(z)*13
        ID = x[0:5]+str(j)
        for i in range(len(users)):
            if((users[i]==y)and(password[i]==z)):
                choice = input("login?y/n")
                return choice
            else:
                print("invalid email or password")
                print("please login again \n")
            
def signup():
    global x
    x = input("enter full name.")
    global y
    y = input("enter email.")
    global z
    z = input("enter password")
    global j
    j = (len(z)*13)
    global ID
    ID = x[0:5]+str(j)
    print("id is:", ID)
    global level
    level = 0
    global sub
    sub = 'none'
    global rewards
    rewards = 'none'
    cre = input("want to add payment method?y/n")
    if(cre=='y'):
        x = input("enter credit card no.")
        global balance
        balance = input("enter balance")
    choice = input("confirm membership?y/n")
    
    return choice

def adminlogin():
    global category_list
    name=input('enter username')
    passw=input('enter password')
    if name=='qw123':
        if passw=='123qw':
            choice='y'
            while(choice=='y'):
                fo= input("want to add games to \n 1. games or \n 2. categories\n")
                if(fo=='1'):
                    u = input("enter name of game\n")
                    print("categories are: ")
                    print(category_list)
                    answer=input("to which category do you want to add this game?enter no.\n")
                    if answer==1:
                        global ac_list
                        ac_list=ac_list+[u]
                    elif answer==2:
                        global ad_list
                        ad_ist=ad_list+[u]
                    elif answer==3:
                        global ar_list
                        ar_list =ar_list+[u]
                    elif answer==4:
                        global bo_list
                        bo_list=bo_list+[u]
                    elif answer==5:
                        global ca_list
                        ca_list=ca_list+[u]
                    elif answer==6:
                        global cas_list
                        cas_list= cas_list+[u]
                    elif answer==7:
                        global cas_rlist
                        cas_rlist=cas_rlist+[u]
                    elif answer==8:
                        global s_rlist
                        s_rlist = s_rlist+[u]
                    elif answer==9:
                        global s_plist
                        s_plist=s_plist+[u]
                    print("game has been added.\n\n")
                else:
                    u = input("enter categroy\n")
                    category_list = category_list+[u]
                    print("category has been added")
                choice =input("want to make any more updates?press y or press n to logout.")
    else:print('invalid password')
def settings(): 
   choice='y' 
   while(choice=='y'):
       z=input('Do you want to change the settings? \n Press 1 for brightness \n Press 2 for audio \n Press 3 for notifications \n Press 4 for history\n ')
       z=(int)(z)
       if(z==1):
           b=input('Adjust brightness level from 1-10\n')
           b=(int)(b)
           brightness=b
       elif(z==2):
           a=input ('Adjust audio level from 1-10\n')
           a=(int)(a)
           audio=a
       elif(z==3):
           n=input('Do you want to view notifications?y/n')
           notify=n
       elif(z==4):
           h=input('Do you want yo view history?y/n')
           history=h 
       else:
           print("invalid option")
       s = input("do you want to save settings?y/n")
       if(s=='y'):
           print("settings are saved")
       else:
           print("settings not saved")
       choice = input("want to change more settings?y/n")
def wishlist():
    n = input("enter name of game you want to add to wishlist\n")
    global saved
    saved=saved+[n]
    print('Your game has been added to wishlist \n\n')

def help1():
    choice='y'
    while(choice=='y'):
        x=input('Do you want any help? \n Press 1 for settings \n Press 2 for account \n Press 3 for games \n Press 4 for credit \n Press 5 for wishlist \n Press 6 for online games \n Press 7 for any other help\n')
        x=(int)(x)
        if x==1:
            print('1.Brightness option is used to set brightness')
            print('2.Audio option is used to set volume')
            print('3.Notification allows you to see notifiations about your game')
            print('4.History option is used to view about your payments')
        elif(x==2):
            print('Change password')
            print('Change email')
            print('Change Username')
            print('Delete account')
        elif(x==3):
            print('You can buy games from your account using your credit card')
            print('Each game has its own control buttons')
            print('If you cannot play game,email us about it')
        elif(x==4):
            print('If you have any issue regarding the privacy of your credit card,email us on our website')
        elif(x==5):
            print('Wishlist allows you to reserve games which you want to buy later')
        elif(x==6):
            print('You can play games online with your friends anywhere in the world')
        else:
            y=input('If you have any other issue with the game please enter it')
            print('We will contact you regarding this issue later.Thank You')
        choice=input('Do you want more help?y/n')

def updatecategory(old name ,new name):
    global categorylist
    for i in range(len(categorylist)):
        categorylist[old name]= print new name 
        
def categories():
    global category_list
    category_list=['Action','Adventure','Arcade','Board','Card','Casino','Casual and Role Playing','Sports and Racing','Puzzle and Strategy'] 
    for i in range (len(category_list)):
        print(str(i+1) + '  ' + category_list[i])
    answer=input('press the number of the category you want to choose\n')
    answer=int(answer)
    if answer==1:
        action()
    elif answer==2:
        adventure()
    elif answer==3:
        arcade()
    elif answer==4:
        board()
    elif answer==5:
        card()
    elif answer==6:
        casino()
    elif answer==7:
        casual_roleplaying()
    elif answer==8:
        sports_racing()
    elif answer==9:
        puzzle_strategy()
    
def action():
    global ac_list
    for i in range (len(ac_list)):
        print(str(i+1)+ '  ' + ac_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.210"\n')
    option=int(option)
    if option==1:
        for i in range (len(ac_list)):
            if answer==(i+1):
                print('Trial version of ',ac_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.210')
        for i in range(len(ac_list)):
            if answer==(i+1):
                print('Full game  ',ac_list[i]), print('is downloading')
       


def adventure():
    global ad_list
    for i in range (len(ad_list)):
        print(str(i+1)+ '  ' + ad_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.210"\n')
    option=int(option)
    if option==1:
        for i in range (len(ad_list)):
            if answer==(i+1):
                print('Trial version of ',ad_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.210')
        for i in range(len(ad_list)):
            if answer==(i+1):
                print('Full game  ',ad_list[i]), print('is downloading')
       

def arcade():
    global ar_list
    for i in range (len(ar_list)):
        print(str(i+1)+ '  ' + ar_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.310"\n')
    option=int(option)
    if option==1:
        for i in range (len(ar_list)):
            if answer==(i+1):
                print('Trial version of ',ar_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.310')
        for i in range(len(ar_list)):
            if answer==(i+1):
                print('Full game  ',ar_list[i]), print('is downloading')
       
def board():
    global bo_list
    for i in range (len(bo_list)):
        print(str(i+1)+ '  ' + bo_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.190"\n')
    option=int(option)
    if option==1:
        for i in range (len(bo_list)):
            if answer==(i+1):
                print('Trial version of ',bo_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.190')
        for i in range(len(bo_list)):
            if answer==(i+1):
                print('Full game  ',bo_list[i]), print('is downloading')
       

def card():
    global ca_list
    for i in range (len(ca_list)):
        print(str(i+1)+ '  ' + ca_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.250"\n')
    option=int(option)
    if option==1:
        for i in range (len(ca_list)):
            if answer==(i+1):
                print('Trial version of ',ca_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.250')
        for i in range(len(ca_list)):
            if answer==(i+1):
                print('Full game  ',ca_list[i]), print('is downloading')
       


def casino():
    global cas_list
    for i in range (len(cas_list)):
        print(str(i+1)+ '  ' + cas_list[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.250"\n')
    option=int(option)
    if option==1:
        for i in range (len(cas_list)):
            if answer==(i+1):
                print('Trial version of ',cas_list[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.250')
        for i in range(len(cas_list)):
            if answer==(i+1):
                print('Full game  ',cas_list[i]), print('is downloading')
       
    
def casual_roleplaying():
    global cas_rlist
    for i in range (len(cas_rlist)):
        print(str(i+1)+ '  ' + cas_rlist[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.510"\n')
    option=int(option)
    if option==1:
        for i in range (len(cas_rlist)):
            if answer==(i+1):
                print('Trial version of ',cas_rlist[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.510')
        for i in range(len(cas_rlist)):
            if answer==(i+1):
                print('Full game  ',cas_rlist[i]), print('is downloading')


def sports_racing():
    global s_rlist
    for i in range (len(s_rlist)):
        print(str(i+1)+ '  ' + s_rlist[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.210"\n')
    option=int(option)
    if option==1:
        for i in range (len(s_rlist)):
            if answer==(i+1):
                print('Trial version of ',s_rlist[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.210')
        for i in range(len(s_rlist)):
            if answer==(i+1):
                print('Full game  ',s_rlist[i]), print('is downloading')


def puzzle_strategy():
    global s_plist
    for i in range (len(s_plist)):
        print(str(i+1)+ '  ' + s_plist[i])
    answer=input('press the number of the game you want to choose\n')
    answer=int(answer)
    option=input('do you want to play the trial version or buy the full game?\npress 1 for free trial\npress 2 for buying full version "all games in the category are available for Rs.350"\n')
    option=int(option)
    if option==1:
        for i in range (len(s_plist)):
            if answer==(i+1):
                print('Trial version of ',s_plist[i]), print('is downloading')
    if option==2:
        print('you bought the game for Rs.350')
        for i in range(len(s_plist)):
            if answer==(i+1):
                print('Full game  ',s_plist[i]), print('is downloading')



def account():
    account_list=['see/ change settings','add to wishlist','get help','online','see categories of games','update category']
    choice='y'
    while choice=='y':
        print("\n\n\n")
        for i in range (len(account_list)):
            print(str(i+1) + '  ' + account_list[i])
        answer=input('press the number, where you want to go\n')
        answer=int(answer)
        if answer==1:
            settings()
        elif answer==2:
            wishlist()
        elif answer==3:
            help1()
        elif answer==4:
            online()
        elif(answer==5):
            categories()
        elif(answer==6):
            updatecategory():
        else:
            print("chose valid option")
        choice=input('press y if you want to go back to your account\npress n to logout\n')    
        
def online():
    cr = input("want to play 1 for single player or 2 for multilayer?")
    print("\n\n\n")
    if(cr=='1'):
        yi =  ['Adventure Quest','WHITE WALKERS', 'ADD ME','pick me up','killer escape','titans','Vampire beast','Witches 3','Final FANTASY IV','UTOPIA']
        
        for i in range(len(yi)):
            print(i+1,".",yi[i])
        o = (int)(input("which game do you want to play?enter serial no."))
        print("playing game",yi[o-1] )
    elif(cr=='2'):
        yi = ['ASSASINS CREED','Watchdogs','SLEEPING DOGS','GTA 6','Skyrim','Counter strike','Callofduty','Strong hold legends','Command conquer genrals']
        for i in range(len(yi)):
            print(i+1,".",yi[i])
        o = (int)(input("which game do you want to play?enter serial no."))
        print("playing game",yi[o-1] )
    else:
        print("error. check your network connection and try again.")

def gamestore():
    print("FINAL PROJECT PRESENTED BY: \n MOMINA BABAR(085), RABEETA BASSHIR(057), YUSRA FATIMA(063)")
    print("\n \n \n")
    print("---------------------------------")
    print("|                               |")
    print("|  Welcome To MRY games store.  |")
    print("|                               |")
    print("---------------------------------")
    global x
    x = 'x'
    global y
    y = 'x'
    global z
    z = 'x'
    global k
    k = 'x'
    global j
    j = 'x'
    global ID
    ID  = 'x'
    global level
    level = 0
    global sub
    sub = 'none'
    global rewards
    rewards = 'none'
    global users
    users=[ ]
    global password
    password = [ ]
    global balance
    balance = 0.0
    global saved
    saved = []
    global lo
    global ac_list
    ac_list=['Temple Run 2','Monster Hero City Battle','Bus Rush','Bottle Shoot 3D','Color Switch','Shadow Fight 2','Metal Soldiers','Gun Shoot Fire War','Injustice 2','Fighting Tiger-Liberal','From The Sea','Subway Rush']
    global ad_ist
    ad_list=['Motu Patlu Game','Run Jan','Criminal Case',"diggy's Adventure",'Bounce Classic Game','Pokemon GO','Seekers Notes',"Pearl's Peril",'Terraria','Crashlands','LIMBO','Faces Of Illusion','Spoiler Alert']
    global ar_list
    ar_list=['Subway Surfer','Temple Run','Fruit Ninja','Angry Birds','Knock Down','PAC-MAN','Cooking Fever','Grand Theft Auto: Vice City','Vector','Worms 3','Granny Smith',"THE KING OF FIGHTERS'98",'METAL SLUG']
    global bo_list
    bo_list=['Ludo Neo-Classic','Carrom 3D','Dots and Boxes-Squares','Chess','Rolling Sky','Checkers','Really Bad Chess','Dr.Dominoes','Snakers and Ladders King','Tic Tac Toe Free','Pictionary','Catan','Cluedo','Tailsman']
    global ca_list
    ca_list=['Solitaire','Plato','UNO &Friends','Spider Solitaire','Yu-Gi-Oh! Duel Links','Shadowverse CCG','Pokerist','Phase 10','ANYCARD','TylersTarot','Halli Galli','Blackbird','Spades','6 Takes!']
    global cas_list
    cas_list=['Teen Patti Gold','Big Fish Casino','BINGO','DoubleU Casino','Haunted House','Slot Machine+','Card Counter','Spin Poker','Roulette','Aqua Slots','Extra Draw Keno','Blackjack SG PRO']
    global cas_rlist
    cas_rlist=['My Talking Tom','Candy Crush Saga','Angry Birds 2','Princess Makeup Salon','Gardenscapes-New Arcs','Hay Day','Island Experiment','Covet Fashion','StarDoll',"Let's Create! Pottery",'To The Moon','Hyper Heroes','Summoners War','A Dark Room','Attack the Light']
    global s_rlist
    s_rlist=['8 Ball Pool','FIFA Football','OK Golf','WWE 2K','Dude Perfect','TOP ELEVEN 2017','Real Racing 3','Traffic Rider','Earn to Die','Rush Rally','Riptide GP:Renegade','Repulze','Crash of Cars']
    global s_plist
    s_plist=['Flow Free','Cut the Rope',"Where's My Water?2",'Fishdom','Hook','You Lose','The Room','Zenge','CELL 13','klocki','Dark Echo','Isoland','Prune','sugar,sugar']
    global category_list
    category_list=['Action','Adventure','Arcade','Board','Card','Casino','Casual and Role Playing','Sports and Racing','Puzzle and Strategy'] 

    lo = False
    while(lo==False):
        print("\n \n \n")
        print("*******************")
        print("\n\n")
        print("    MAIN SCREEN    ")
        print("\n\n")
        print("*******************")
        member = input("already a member?\n 1.Press y to login \n 2.If not a memeber, press n to signup for free.\n 3.For admin login press a \n 4.press q to quit \n\n")
        
        if(member=='y'):
            print("\n LOGIN \n")
            c=login()
            if(c=='y'):
                print("\n\n\n")
                print("ACCOUNT")
                print("\n\n\n")
                print("you are logged in")
                print("WELCOME:", ID)
                print("level:", level)
                print("sub:", sub)
                print("rewards are:", rewards)
                print("available balance is", balance)
                print("games in wishlist are", saved)
                account() 
            else:
                    print("error")
        elif(member=='n'):
            print("\n SIGN UP! \n")
            c = signup()
            if(c=='y'):
                
                users = users+[y]
                
                password = password+[z]
                print("signed up. WELCOME TO THE COMMUNITY!")
                print(" \n returning back to main \n\n\n")
            else:
                print("signup failed")
                print("going back to main screen")
        elif(member=='a'):
                print("\n ADMIN LOGIN \n")
                adminlogin()
        elif(member=='q'):
            break
        else:
            print("error try again \n")
            
                

gamestore()
