import tkinter as tk
import random

class Lifes:
    def __init__(self, rows=36, cols=36):
        self.row = rows+2
        self.col = cols+2
        self.items = [[0]*self.col for _ in range(self.row)]
        self.histroy = []
        self.histroySize = 30
        self.running = False
        self.runningSpeed = 100

    def rndinit(self, rate=0.1):
        self.histroy = []
        for i in range(self.row):
            for j in range(self.col):
                rnd = random.random()
                if rnd > 1-rate:
                    self.items[i][j]=1
 
    def reproduce(self):
        new = [[0]*self.col for _ in range(self.row)]
        self.add_histroy()
        if len(self.histroy) > self.histroySize:
            self.histroy.pop(0)
        for i in range(self.row):
            for j in range(self.col):
                if i*j==0 or i==self.row-1 or j==self.col-1:
                    new[i][j]=0
                else:
                    lifes=0
                    for m in range(i-1,i+2):
                        for n in range(j-1,j+2):
                            if m==i and n==j:
                                continue
                            lifes += self.items[m][n]
                    if self.items[i][j]:
                        if lifes==2 or lifes==3:
                            new[i][j]=1
                        else:
                            new[i][j]=0
                    else:
                        if lifes==3:
                            new[i][j]=1
        for idx,narray in enumerate(new):
            self.items[idx] = narray
 
    



# def on_resize(event):
    
    # width = event.width
    # height = event.height
    # xx = width - 300
    # yy = height - 60
    # numi = (yy-40)//15
    # numj = (xx-40)//15
    # for i in range(numi):
    #     coord = 40, 40+15*i, xx, 40+15*i
    #     tv.create_line(coord, fill='white')
    # for j in range(numj):    
    #     coord = 40+15*j, 40, 40+15*j, yy
    #     tv.create_line(coord, fill='white')
    # tv.create_rectangle(40, 40, xx, yy, width= 4)
    # R,XY = 8,[50+i*20 for i in range(36)]
    # rect = [[0]*36 for _ in range(36)]
    # for i,x in enumerate(XY):
    #     for j,y in enumerate(XY):
    #         rect[i][j] = tv.create_rectangle(x-R,y-R,x+R,y+R,tags=('imgButton1'))
    #         tv.itemconfig(rect[i][j],fill='lightgray',outline='lightgray')
    # tv.tag_bind('imgButton1','<Button-1>',on_press)
    

        
def on_move(event):
    global leftButton
    x = event.x
    y = event.y
    if leftButton:
        tv.create_oval (x-2, y-2, x+2, y+2, fill="black")

def on_press(event):
    global leftButton
    leftButton = True

def on_release(event):
    global leftButton
    leftButton = False
    
def drawCanvas():
    global tv, xx, yy
    tv = tk.Canvas(win)
    tv.pack(fill='both', expand='yes')
    width = win.winfo_width
    height = win.winfo_height
    xx = width - 300
    yy = height - 60
    numi = (yy-40)//15
    numj = (xx-40)//15
    for i in range(numi):
        coord = 40, 40+15*i, xx, 40+15*i
        tv.create_line(coord, fill='white')
    for j in range(numj):    
        coord = 40+15*j, 40, 40+15*j, yy
        tv.create_line(coord, fill='white')
    tv.create_rectangle(40, 40, xx, yy, width= 4)
    R,XY = 8,[40+i*15 for i in range(36)]
    rect = [[0]*36 for _ in range(36)]
    for i,x in enumerate(XY):
        for j,y in enumerate(XY):
            rect[i][j] = tv.create_rectangle(x-R,y-R,x+R,y+R,tags=('imgButton1'))
            tv.itemconfig(rect[i][j],fill='lightgray',outline='lightgray')
    tv.tag_bind('imgButton1','<Button-1>',on_press)
    




def showInfo():
    tLabel = tk.Label(win, width=30, height=20, background='lightgray')
    tLabel.place(anchor='ne', relx=1.0, x=-40, y=40)

def drawButton():
    tButton = [None]*4
    bX,bY,dY = 835, 458, 50
    txt = ['1','2','3','4']
    for i in range(4):
        tButton[i] = tk.Button(win, text=txt[i], background="lightgray")
        tButton[i].place(x=bX, y=bY+dY*i, width=120, height=40)     
 



if __name__ == '__main__':
    
    win = tk.Tk()
    win.title("LifeGame")
    win.geometry("1024x800")

    # win.bind ("<Configure>", on_resize)
    drawCanvas()
    showInfo()
    drawButton()
    tv.bind ("<Motion>", on_move) 
    tv.bind ("<Button-1>", on_press) 
    tv.bind ("<ButtonRelease-1>", on_release)
    
    win.mainloop()
    