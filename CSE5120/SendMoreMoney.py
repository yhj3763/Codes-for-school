# send_more_money
# by KV for CSE 512, Winter 2018
# generate next number (as listof digits) that has
# k unique digits 0..9
# updated for CSE 5120, Fall 2020

#LETTERS = ['0','M','Y','E','N','D','R','S'] # (01)256789
LETTERS = ['S','E','N','D','R','Y']
CODE = {'O':0,'M':1} # set these to cut down on effort

SEND = ['S','E','N','D']
MORE = ['M','O','R','E']
MONEY = ['M','O','N','E','Y']

def next_unique_digits(k,num):
    nxt = next_digits(k,num)
    #print nxt
    while len(set(nxt)) != k and len(set(nxt)) <= k or\
          set(nxt).intersection(set([0,1])) != set([]):
        num += 1
        nxt = next_digits(k,num)
        #print nxt
    nextnum = int(''.join(map(lambda x: str(x), nxt)))
    if nextnum >= pow(10, k):
        return ([],-1)
    return (nxt, nextnum)

# given a integer k ("number of digits") and a number
# produces a list of digits that represents the number
def next_digits(k, num):
    digs = []
    x = k-1
    while x >= 0:
        m = num // pow(10, x)
        digs.append(m)
        if m != 0:
            num = num - m * pow(10, x)
        x -= 1
    return digs

# [S,E,N,D] Sval * 10^3 + Eval * 10^2 + Nval * 10^1 + Dval * 10^0
# i = 0..3
def word_value(wdlst,code):
    val = 0;
    for i in range(len(wdlst)):
        val += code[wdlst[i]] * pow(10,len(wdlst)-1 -i)

    return val

def solve():
    global CODE
    k = 6 # bec of preset CODE, 8 - 2 letters to encode ...
    n = 0
    count = 1
    for i in range(pow(10,k)):
        (n1,n2) = next_unique_digits(k,n)
        if n2 == -1:
            return []
        print ("{0:d}. {1}".format(count,n1)) #,n2
        count += 1
        j = 0
        for x in LETTERS:
            if x != 'O' and x != 'M':
                CODE[x] = n1[j]
                j+=1
        if word_value(SEND,CODE) + word_value(MORE,CODE) == \
            word_value(MONEY,CODE):
            return CODE
        n = n2+1
    return []

if __name__ == '__main__':
    solve()
    input("Any key to quit")
        
