import copy

# display states of jugs through @
def show_jugs(jug):
    if jug == None:
        return

    for i in range(2):
        print("jug {0:d}: ".format(i+3), end="")
        for i in range(jug[i]):
            print("@  ", sep=' ', end='')
        print()
    print("\n")
    return

# When the state of jug is same with goal, it returns true
def jugs_goal_fct(jug,goal):
    if jug == goal:
        return True
    return False
    
# it just returns 0 always in this problem
def jugs_eval_fct(jug,goal):
    score = 0
    return score

# it includes all ways to act by jugs, it can be added to succs 
# if it can do that action
def jugs_successor_fct(jug):
    succs = []
    actions = [jugs_fill3(jug),
               jugs_fill4(jug),
               jugs_empty3(jug),
               jugs_empty4(jug),
               jugs_pour3to4(jug),
               jugs_pour4to3(jug)]
    
    for x in actions:
        if not x == None:
            succs.append(x)
    return succs

# fill 3-liter jug
def jugs_fill3(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] != 0:
        return None
    newjug[0] = 3
    return newjug

# fill 4-liter jug  
def jugs_fill4(jug):
    newjug = copy.deepcopy(jug)
    if newjug[1] != 0:
        return None
    newjug[0] = 4
    return newjug
    
# empty 3-liter jug
def jugs_empty3(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] != 3 or newjug[0] == 0:
        return None
    elif newjug[0] == 3:
        newjug[0] = 0

    return newjug

# empty 4-liter jug
def jugs_empty4(jug):
    newjug = copy.deepcopy(jug)
    if newjug[1] != 4 or newjug[1] == 0:
        return None
    elif newjug[1] == 4:
        newjug[1] = 0

    return newjug

# pour from 3-liter jug to 4-liter jug
def jugs_pour3to4(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] == 0 or newjug[1] == 4:
        return None
    newjug[1] += newjug[0]
    newjug[0] = 0
    if newjug[1] >4:
        newjug[0] = newjug[1] - 4
        newjug[1] = 4
    return newjug

# pour from 4-liter jug to 3-liter jug
def jugs_pour4to3(jug):
    newjug = copy.deepcopy(jug)
    if newjug[1] == 0 or newjug[0] == 3:
        return None
    newjug[0] += newjug[1]
    newjug[1] = 0
    if newjug[0] >3:
        newjug[1] = newjug[0] - 3
        newjug[0] = 3
    return newjug
     
