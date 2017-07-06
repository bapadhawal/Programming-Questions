import pygame as pg
import time
import random as rd
pg.init()
white=(255,255,255)
black=(0,0,0)
red=(255,0,0)
darkgreen=(34,139,34)
green=(0,255,0)
blue=(0,191,255)
darkblue=(0,0,255)
orange=(255,140,0)
darkorange=(255,69,0)
width=800;height=500;B=10;speed=10;ini=15;prog=100;period=6000;move=7;high=0
gamedisplay = pg.display.set_mode((width,height+prog))
pg.display.set_caption('Snakegame with Static Object')
pg.display.update()
img = pg.image.load('snakeimg.png')
def textobject(msg,color,size):
    font = pg.font.SysFont("comicsansms",size)
    textsurface=font.render(msg,True,color)
    return textsurface,textsurface.get_rect()
def msg_screen(msg,color,displace,size):
    textsurf,textrect = textobject(msg,color,size)
    textrect.center=(width/2,(prog+height)/2-displace)
    gamedisplay.blit(textsurf,textrect)
def showscore(msg,color,a,b,size):
    font = pg.font.SysFont("comicsansms",size)
    screen_text=font.render(msg,True,color)
    gamedisplay.blit(screen_text,[a,b])
def button(msg,startx,starty,widthx,widthy,color,pcolor,cur):
    ans=0
    if cur[0] >= startx and cur[0]<startx+widthx and cur[1] >= starty and cur[1]<starty+widthy:
        pg.draw.rect(gamedisplay,pcolor,[startx,starty,widthx,widthy]);ans=1
    else :
        pg.draw.rect(gamedisplay,color,[startx,starty,widthx,widthy])
    textsurf,textrect = textobject(msg,black,20)
    textrect.center=(startx+(widthx/2),starty+(widthy/2))
    gamedisplay.blit(textsurf,textrect)
    return ans
def snake(snakelist,xc,yc,score,life,pause,oneup):
    if xc == B:
        head = img
    elif xc == -B:
        head = pg.transform.rotate(img,180)
    elif yc == -B:
        head = pg.transform.rotate(img,90)
    elif yc == B:
        head = pg.transform.rotate(img,270)
    gamedisplay.fill(white)
    pg.draw.line(gamedisplay,red,(0,prog-3),(width,prog-3),3)
    msg="Your Score : "+str(score)
    showscore(msg,black,600,10,25)
    if pause == True:
        if life== period and score ==0:
            msg_screen("Press Spacebar To Start Game",black,240,30)
        else :
            msg_screen("Press Spacebar To Resume Game",black,240,30)
    if pause == False:
        pg.draw.rect(gamedisplay,black,((80,50),(640,30)),2)
        per=640.0*life/period
        rem=round(per)
        age=100.0*rem/640.0;roundage=round(age)
        pg.draw.rect(gamedisplay,green,[80,50,rem,30])
        pg.draw.rect(gamedisplay,red,[80+rem,50,640-rem,30])
        msg="Remaining Life : "+str(roundage)
        msg_screen(msg[:-2]+"%",red,270,20)
        showscore("Extra Life : "+str(oneup),darkblue,50,10,25)
    gamedisplay.blit(head,(snakelist[-1][0],snakelist[-1][1]))
    for xny in snakelist[:-1]:
        pg.draw.rect(gamedisplay,green,[xny[0],xny[1],B,B])
def instruct():
    gamedisplay.fill(white)
    msg_screen("Use Arrow key to move Snake",darkblue,150,30)
    msg_screen("Objective of Game to eat black insect",darkblue,110,30)
    msg_screen("More you eat Insect More will be Your Score",darkblue,80,20)
    msg_screen("If you try to cross boundary. You Die!",darkblue,40,20)
    msg_screen("If head of snake will touch body of snake. You Die!",darkblue,10,20)
    msg_screen("After every 4 insect there will extra life for snake",darkblue,-20,20)
    msg_screen("Extra Life can save snake only if life reduced to 0%",darkblue,-50,20)
    click = False
    while not click:
        cur = pg.mouse.get_pos()
        press= pg.mouse.get_pressed()
        i1=button("Play",150,450,100,50,green,darkgreen,cur)
        i2=button("Quit",550,450,100,50,blue,darkblue,cur)
        pg.display.update()
        if press[0]==1:
            if i1==1:
                again=False;click=True
            if i2==1:
                again =True;click= True
        for event in pg.event.get():
            if event.type == pg.QUIT:
                again =True;click= True
    return again
def gameintro():
    intro = True;play=False
    while intro:
        cur = pg.mouse.get_pos()
        press= pg.mouse.get_pressed()
        gamedisplay.fill(white)
        msg_screen("Welcome to SnakeGame",red,50,70)
        p1=button("Play",150,400,100,50,green,darkgreen,cur)
        p2=button("Control",350,400,100,50,orange,darkorange,cur)
        p3=button("Quit",550,400,100,50,blue,darkblue,cur)
        pg.display.update()
        if press[0]==1:
            if p1==1:
                intro= False
            if p2==1:
                play=instruct();intro = False
            if p3==1:
                intro =False;play=True
        for event in pg.event.get():
            if event.type == pg.QUIT:
                intro= False;play=True
    return play
def level():
    choose=False;hua=False
    gamedisplay.fill(white)
    msg_screen("Game Levels",red,0,70)
    pg.display.update()
    time.sleep(1)
    while not choose:
        cur = pg.mouse.get_pos()
        press= pg.mouse.get_pressed()
        gamedisplay.fill(white)
        l1=button("Level 1",150,100,100,50,orange,darkorange,cur)
        l2=button("Level 2",350,100,100,50,orange,darkorange,cur)
        l3=button("Level 3",550,100,100,50,orange,darkorange,cur)
        l4=button("Level 4",150,250,100,50,orange,darkorange,cur)
        l5=button("Level 5",350,250,100,50,orange,darkorange,cur)
        l6=button("Level 6",550,250,100,50,orange,darkorange,cur)
        pg.display.update()
        if press[0]==1:
            if l1==1:
                choose=True;move=3;speed=5
            if l2==1:
                choose=True;move=5;speed=5
            if l3==1:
                choose=True;move=7;speed=5
            if l4==1:
                choose=True;move=3;speed=10;
            if l5==1:
                choose=True;move=5;speed=10
            if l6==1:
                choose=True;move=7;speed=10
        for event in pg.event.get():
            if event.type == pg.QUIT:
                choose=True;hua=True
    return (hua,speed,move)
clock= pg.time.Clock()
gameexit = gameintro()
if not gameexit:
    (gameexit,speed,move)=level()
while not gameexit:
    if not gameexit:
        pause=True
        gameover = False
        life=period;oneup=0
        x=width/2-100;y=prog+height/2
        xc=B;yc=0;rxc=move;ryc=0
        snakelength=0;sz=ini
        snakelist=[]
        while snakelength < ini:
            x+=B;snakehead=[x,y];snakelist.append(snakehead);snakelength+=1
        rx=B*rd.randrange(1,width/B-2)
        ry=prog+B*rd.randrange(1,height/B-2)
        snake(snakelist,xc,yc,snakelength-ini,life,pause,oneup)
        pg.draw.rect(gamedisplay,black,[rx,ry,B,B])
        pg.display.update()
        while pause:
            for event in pg.event.get():
                if event.type == pg.KEYDOWN:
                    if event.key== pg.K_SPACE:
                        pause = False
        while not gameover:
            get=0
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    gameover = True; gameexit= True
                if event.type == pg.KEYDOWN and get==0:
                    if event.key == pg.K_LEFT and xc==0 and pause == False:
                        xc=-B;yc=0;get=1;
                    elif event.key == pg.K_RIGHT and xc==0 and pause == False:
                        xc=B;yc=0;get=1
                    elif event.key == pg.K_DOWN and yc==0 and pause == False:
                        yc=B;xc=0;get=1
                    elif event.key == pg.K_UP and yc==0 and pause == False:
                        yc=-B;xc=0;get=1
                    elif event.key == pg.K_ESCAPE:
                        gameover = True
                    elif event.key == pg.K_SPACE and pause == False:
                        pause = True
                    elif event.key == pg.K_SPACE and pause == True:
                        pause = False
                    r=rd.randrange(1,5)
                    if r==1 and rx+B<width: 
                        rxc=move;ryc=0
                    elif r==2 and rx>0:
                        rxc=-move;ryc=0
                    elif r==3 and ry+B<height+prog:
                        ryc=move;rxc=0
                    elif r==4 and ry>prog:
                        ryc=-move;rxc=0
            if pause == True:
                snake(snakelist,xc,yc,snakelength-ini,life,pause,oneup)
                pg.display.update()
            elif pause == False:
                x+=xc;y+=yc;life-=B
                if x+B>width or x<0 or y+B>height+prog or y<prog:
                    gameover=True
                elif life<0:
                    if oneup >0:
                        life=period;oneup-=1
                    elif oneup ==0:
                        gameover = True
                else:
                    if green == gamedisplay.get_at((x+B/2,y+B/2)):
                        gameover = True
                rx+=rxc;ry+=ryc
                if rx+B>width or rx<0:
                    rxc=-rxc;rx+=rxc
                if ry+B>height+prog or ry<prog:
                    ryc=-ryc;ry+=ryc
                snakehead=[x,y]
                snakelist.append(snakehead);sz+=1
                if abs(x-rx)<B and abs(y-ry)<B:
                    rx=B*rd.randrange(1,width/B-2)
                    ry=prog+B*rd.randrange(1,height/B-2)
                    snakelength+=1;life=period
                    if (snakelength-ini)%5 ==0:
                        oneup+=1
                if sz > snakelength:
                    sz-=1;del snakelist[0]
                snake(snakelist,xc,yc,snakelength-ini,life,pause,oneup)
                if (snakelength-ini)%5 ==4:
                    pg.draw.rect(gamedisplay,darkblue,[rx,ry,B,B])
                if (snakelength-ini)%5 !=4:
                    pg.draw.rect(gamedisplay,black,[rx,ry,B,B])
                pg.display.update();
                clock.tick(speed+snakelength);get=0
    if not gameexit:
        loop = True;high=max(high,snakelength-ini)
        while loop:  
            gamedisplay.fill(white)
            msg_screen("Game Over",black,0,40)
            score="Your Score : "+str(snakelength-ini)
            msg_screen(score,red,150,50)
            msg_screen("Highest Score : "+str(high),red,80,50)
            cur = pg.mouse.get_pos()
            press= pg.mouse.get_pressed()
            p1=button("Play Again",100,400,150,50,green,darkgreen,cur)
            p2=button("Control",350,400,100,50,orange,darkorange,cur)
            p3=button("Quit",550,400,100,50,blue,darkblue,cur)
            pg.display.update()
            if press[0]==1:
                if p1==1:
                    loop= False
                if p2==1:
                    play=instruct();loop = False
                if p3==1:
                    loop =False;gameexit=True
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    gameexit=True;loop = False
pg.quit()
quit()
