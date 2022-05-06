CLS = [['notP', 'notQ', 'R'], ['P', 'R'], ['Q', 'R'], ['notR']]

CHEM = [['notCO2', 'notH2O', 'H2CO3'], ['notC', 'notO2', 'CO2'],
        ['notMgO', 'notH2', 'Mg'], ['notMgO', 'notH2', 'H2O'],
        ['MgO'], ['H2'], ['O2'], ['C'], ['notH2CO3']]

GOV = [['T', 'notE', 'D'], ['notT', 'C'], ['E', 'notD', 'I'],
       ['notG', 'notD', 'I'], ['T', 'C', 'notD', 'G'], ['notC'],
       ['notI', 'notG'], ['D'], ['E']]

def try_resolvent(count, c1, c2):
    res = None
    for lit1 in c1:
        for lit2 in c2:
            if is_complement(lit1, lit2):
                print("\n[%d.] Resolving %s and %s ..." % (count, c1, c2))
                print("... found compl lits (%s, %s)" % (lit1, lit2))
                res = c1[:]
                res.remove(lit1)
                for x in c2:
                    if not x in res and x != lit2:
                        if complement(x) in res:
                            return True
                        else:
                            res.append(x)
                return res
    print("No resolvent")
    return res

def is_complement(x,y):
    if len(x) >= 4 and x[:3] == 'not':
        return x[3:] == y
    elif len(y) >= 4 and y[:3] == 'not':
        return x == y[3:]
    else:
        return False


def complement(x):
    if len(x) >=4 and x[:3] == 'not':
        return x[3:]
    else:
        return 'not'+x


# c1 same as c2, if both contain the same elements, but possibly
# in a different order; iterate over one and test whether it is
# present in the other;

def same_clause(c1, c2):
    if not len(c1) == len(c2):
        return False
    for x in c1:
        if not x in c2:
            return False
    return True


# It is a function that displays the list of cls only.
def show(cls):
    print("\n")

    for n in range(len(cls)):
        print("%d. %s" %(n+1,cls[n]))


# It is a function that makes user pick two clause.
def select():
    print("\n")
    print("Pick two clauses by their number ...")
    first = int(input("First clause: "))
    second = int(input("Second clause: "))
    return (first, second)


# It is a function that checks existing same clause and adds new clause
def new_clause(cls, res):

    for i in range(len(cls)):
        if same_clause(cls[i], res):
            print("There is same clause already...")
            return False

    
    cls.append(res)
    print("... new clause %s added" %res)
    return cls

# It is a function that prints message when the empty clause comes out
def empty_clause(res):
    if res == []:
        print("... it gives empty new clause!")
        print("\n")
        print("UNSATISFIABLE :-)")
        print("'UNSAT'")

# It is a combination of functions above and interacts with user
def interact_resolve(cls):
    print("\n")
    count = 1

    while count <= 100:
        show(cls)
        pick = select()

        c1 = cls[pick[0]-1]
        c2 = cls[pick[1]-1]

        res = try_resolvent(count, c1, c2)

        if res == None:
            continue

        if new_clause(cls, res) == False:
            continue

        empty_clause(res)

        if res == []:
            break

        count+=1


    if count > 100:
        print ("100 resolutions tried without Contradiction")
        print ("We have no answer :-|")
    return

        
    

    
   
