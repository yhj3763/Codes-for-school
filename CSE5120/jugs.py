import copy

start = [0,0]
goal = [0,2]

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

def jugs_goal_fct(jug,goal):
    if jug == goal:
        return True
    return False
    


def jugs_eval_fct(jug,goal):
    score = 0
    return score

def jugs_successor_fct(jug):
    succs = []
    actions = [jugs_fill(jug),
               jugs_empty(jug),
               jugs_pour(jug)]
    for x in actions:
        if not x == None:
            succs.append(x)
    return succs


def jugs_fill(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] == 3:
        return None
    newjug[0] = 3
    return newjug
    


def jugs_empty(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] == 0 and newjug[1] == 0:
        return None
    elif newjug[0] == 3:
        newjug[0] = 0
    elif newjug[1] == 4:
        newjug[1] = 0

    return newjug

def jugs_pour(jug):
    newjug = copy.deepcopy(jug)
    if newjug[0] == 0:
        return None
    newjug[1] += newjug[0]
    newjug[0] = 0
    if newjug[1] >4:
        newjug[0] = newjug[1] - 4
        newjug[1] = 4
    return newjug
     
