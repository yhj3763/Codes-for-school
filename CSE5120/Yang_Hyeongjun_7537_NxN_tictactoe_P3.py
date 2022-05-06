# NxN_ tictactoe_P3.py
# Python 3 version of NxN_tictactoe.py

# to be used with CSE 5120 HW3

# Student Completer:Hyeongjun Yang SID:005897537

import random
import copy

abc = 'abcdefghijklmnpqrstuvwxyz'

class TN():
    def __init__(self, dim, tn = None):
        self.size = dim
        
        if tn == None:
##            self.ttt = {'a': 0, 'b': 0, 'c':0, 'd': 0,'e': 0, 'f':0,\
##                        'g': 0, 'h': 0, 'i': 0}
            self.ttt = {}
            for i in range(1,(dim*dim)+1):
                label = abc[i-1]
                self.ttt[label] = 0
        else:
            self.ttt = tn
    
        self.rows = []
        for i in range(dim):
            nextrow = []
            for j in range(1,dim+1):
                nextrow.append(abc[dim*i+j - 1])
            self.rows.append(nextrow)
        self.cols = []
        for i in range(1,dim+1):
            nextcol = []
            for j in range(dim):
                nextcol.append(abc[j*dim+i - 1])
            self.cols.append(nextcol)
        self.dia1 = []
        self.dia2 = []
        for i in range(dim):
            self.dia1.append(abc[i*(dim+1)+1 - 1])
            self.dia2.append(abc[dim*dim-(i+1)*(dim-1) - 1])

    def reset(self):
        self.ttt = {}
        for i in range(1,self.size*self.size + 1):
            label = abc[i-1]
            self.ttt[label] = 0
            
    # row, col, or diag values
    def rcd_values(self,rcd):
        return [self.ttt[x] for x in rcd]

    def __str__(self):
        ttt_str = ""
        for r in self.rows:
            ttt_str += ("%s " % self.rcd_values(r))
        return ttt_str
    
    # a way to display the board
    def present(self):
        for r in self.rows:
            self.present_row(r)
        print("\n")

    def present_row(self,row):
        for i in range(self.size):
            if self.ttt[row[i]] == 0:
                if i < self.size-1:
                    print("{} ".format(row[i]),end="")
                else:
                    print("{} ".format(row[i]))
            else:
                if i < self.size-1:
                    print("{} ".format(self.ttt[row[i]]),end="")
                else:
                    print("{} ".format(self.ttt[row[i]]))
        

    # prompt for and put X
    def put_X(self):
        self.present()
        while(True):
            pick = input('Choose place for X: ')
            if self.ttt[pick] == 0:
                self.ttt[pick] = 'X'
                break
            else:
                print("Can't do; choose again:")

    # place O
    def put_O(self,place):
        self.ttt[place] = '@'

   # True if there is a full row of symbol 'symb'    
    def full_row(self,symb):
        rs = list(self.size*symb)
        for r in self.rows:
            if rs == self.rcd_values(r):
                return True
        return False

    # True if there is a full col of symbol 'symb'
    def full_col(self,symb):
        rs = list(self.size*symb)
        for c in self.cols:
            if rs == self.rcd_values(c):
                return True
        return False
    

    # True if there is a full diag of symbol 'symb'
    def full_diag(self,symb):
        rs = list(self.size*symb)
        return rs==self.rcd_values(self.dia1) or\
               rs==self.rcd_values(self.dia2)

    # True if X wins
    def winX(self):
        return self.full_row('X') or\
               self.full_col('X') or\
               self.full_diag('X')

    # True if O wins
    def winO(self):
        return self.full_row('@') or\
               self.full_col('@') or\
               self.full_diag('@')

    def tie(self):
        vals = list(self.ttt.values())
        if vals.count(0) == 0:
            return not self.winO() and not self.winX()
        return False

    # possible rows,cols,diags for X -
    # possible rows,cols,diagas for O
    def eval_fct(self):
        if self.winX():
            return 10000
        if self.winO():
            return -10000
        
        countX = 0
        countO = 0
        for r in self.rows:
            tr = list(map(lambda x: self.ttt[x],r))
            trc = tr[:]
            kX = trc.count('X')
            kO = trc.count('@')
            if kO == 0:
                countX += 1
            if kX == 0:
                countO += 1
        for c  in self.cols:
            tc = list(map(lambda x: self.ttt[x],c))
            tcc = tc[:]
            kX = tcc.count('X')
            kO = tcc.count('@')
            if kO == 0:
                countX += 1
            if kX == 0:
                countO += 1
        for d  in [self.dia1,self.dia2]:
            td = list(map(lambda x: self.ttt[x],d))
            tdc = td[:]
            kX = tdc.count('X')
            kO = tdc.count('@')
            if kO == 0:
                countX += 1
            if kX == 0:
                countO += 1
        #print "eval = %d" % (countX - countO)
        return countX - countO 

    # the game loop
    def play(self):
        self.reset()
        print ("\n\n")
        print ("Starting a new game of tictactoe. X begins ...\n")
        turn = 'X'
        while True:
            if turn == 'X':
                self.put_X()
                turn = 'O'
            else:
                plO = self.maximin_O()
                # HW3: replace above with: plO = self.maximin_O()
                self.put_O(plO)
                turn = 'X'
            
            if self.winX():
                self.present()
                print("X, you WIN  :-))\n\n")
                return
            if self.tie():
                self.present()
                print ("You TIE :-|\n")
                return
            if self.winO():
                self.present()
                print ("O wins, you LOSE  :-((\n\n")
                return

    # place a random O (the games current response)
    # TO BE REPLACED IN HOMEWORK 3!!
    #****
    
    def random_O(self):
        self.present()
        print("Playing an @ ...")
        rest=[]
        for k in self.ttt.keys():
            if self.ttt[k] == 0:
                rest.append(k)
        pick = random.choice(rest)
        self.ttt[pick] = '@'
    #***

    def maximin_O(self):
        # ... complete for hw3 ...
        places_for_O = []
        for k in self.ttt.keys():
            if self.ttt[k] == 0:
                places_for_O.append(k)

        hypo_Oboards = []
        for k in places_for_O:
            hypo_ttt = copy.deepcopy(self.ttt)
            hypo_ttt[k] = '@'
            hypo_Oboards.append([k,hypo_ttt])

        evaled_Oboards = []
        for (k,ob) in hypo_Oboards:
            maxeval = self.get_maxeval_among_Xboards(ob)
            evaled_Oboards.append([maxeval,k])

        bestO = min(evaled_Oboards)

        best_place_for_O = bestO[1]
                                

        # finish with:
        self.ttt[best_place_for_O] = '@'
        return
            
    # helper fct for maximin_O()
    def get_maxeval_among_Xboards(self,ob):
        # ... complete for hw3
        maxeval = -100000

        places_for_X = []
        for k in ob.keys():
            if ob[k] == 0:
                places_for_X.append(k)

        for k in places_for_X:
            hypo_ttt = copy.deepcopy(ob)
            hypo_ttt[k] = 'X'
            hypo_t3 = TN(self.size, hypo_ttt)
            xeval = hypo_t3.eval_fct()
            if xeval > maxeval:
                maxeval = xeval
        return maxeval
    
if __name__ == "__main__":
    howbig = 0
    while not howbig in [3,4,5]:
        howbig = int(input("Which TicTacToe size [3,4,5]? "))
    print("\n")
    myttt = TN(howbig)
    myttt.play()
    

    
               
   
                                   
