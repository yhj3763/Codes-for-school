# astar_search.py
# by Kersin Voigt, June 2020, for 5120

import random
from puzz8 import *
import operator


class Node:
    def __init__(self, state = None, path = [],
                 depth = 0, evalue = None):
        self.thestate = state
        self.thepath = path
        self.thedepth = depth
        self.theeval = evalue


    def __eq__(self, other):
        return self.thestate == other.thestate


def puzz8_astar(start, target):
    open = [Node(start,[start], 0, puzz8_eval_fct(start,target))]
    closed = []
    steps = 0
    while open != []:
        nxt = open[0]
        open = open[1:]

        nxtstate = nxt.thestate
        nxtpath = nxt.thepath
        nxteval = nxt.theeval
        nxtdpth = nxt.thedepth

        
        if puzz8_goal_fct(nxtstate, target):
            print ("GOAL FOUND:")
            print ("State: %s" % nxtstate)
            print ("PathL:  %d" % len(nxtpath))
            print ("Steps:  %d\n" % steps)
            return [nxtstate, nxtpath]

        if nxt in closed:
            countinue
        closed.append(nxt)

        succ = puzz8_successor_fct(nxtstate)
        random.shuffle(succ)
        for x in succ:
            xcost = puzz8_eval_fct(x,target)
            newnode = Node(x,addpath(nxtpath,x),
                           nxtdpth+1, xcost+nxtdpth+1)

            keeper = True
            for c in closed:
                if newnode.thestate == c.thestate and len(newnode.thepath) >= len(c.thepath):
                    keeper = False
                    break
            if not keeper:
                continue

            for op in open:
                if newnode.thestate == op.thestate and len(newnode.thepath) >= len(op.thepath):
                    keeper = False
                    break

            if keeper:
                open.append(newnode)

        open.sort(key= operator.attrgetter('theeval'))

        steps += 1

    return None
        
                

def addpath(path,x):
    newpath = path[:]
    newpath.append(x)
    return newpath

if __name__ == '__main__':

    random.seed()

 

    solnA = puzz8_astar(puzzE, GOAL)
    i = 0
    for p in solnA[1]:
        print ("\n%d. move yields: " % i)
        show_puzz8(p)
        i+=1
 
            
