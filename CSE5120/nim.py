# nim.py
# game of Nim, CSE 5120, Fall 2021
# programmer: Hyeongjun Yang

import random

# create a game of nim with 3 piles of k stones
def nim_setup(k):
    mynim = [k,k,k]
    return mynim

# display the state of the nim game
def show_nim(nim):
    for i in range(3):
        print("pile {0:d}: ".format(i+1), end="")
        for i in range(nim[i]):
              print("@  ", sep=' ', end='')
        print()
    print("\n")
              

# display the game of nim  by using previous functions and for loop until game is over.
def play_nim(k):
    game = nim_setup(k)
    print("Three piles of {0:d}stones ... Start the Game!".format(k))
    print("\n")
    show_nim(game)
    

    while game != [0,0,0]:
        player_moves(game)
        print("These pile of stones remain ... Continue to play!")
        print("\n")        
        show_nim(game)
        if game == [0,0,0]:
            print("Player took the last stone -- Computer WINS :-")
            break 
        computer_moves(game)
        print("These pile of stones remain ... Continue to play!")
        print("\n")
        show_nim(game)
        if game == [0,0,0]:
            print("Computer took the last stone -- Player WINS :-")
            break

    
        
# display the player move like pile and stone number by player
def player_moves(nim):
    npile = 0
    nstone = 0
    while npile < 1 or npile > 3 or nim[npile-1] == 0:
        npile= int(input("Choose pile [1-3]: "))
        if(npile > 1 and npile <3):
            if(nim[npile-1]==0):
                print("You cannot select empty pile, select other pile")
    
    while nstone < 1 or nstone > nim[npile-1]:
        nstone = int(input("You take how many stones from pile {0:d} pile? ".format(npile)))    
        if(nstone > nim[npile-1]):
            print("Pick the number of stones that have less number than current number")
    nim[npile-1]= nim[npile-1]-nstone
    print("You took {0:d} stones(s) from pile {1:d}".format(nstone,npile))
    print("\n")
   
    
    
# display the computer move based on random value for pile and stone   
def computer_moves(nim):

    npile = random.randint(1,3)
    while(nim[npile-1]==0):
        npile = random.randint(1,3)

    nstone = random.randint(1,nim[npile-1])
    nim[npile-1]= nim[npile-1]-nstone
    print("Computer took {0:d} stones(s) from pile {1:d}".format(nstone,npile))

        


        
                                                  
