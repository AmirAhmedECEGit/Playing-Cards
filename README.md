# Kotshena
Data Structure Project of EECE 2024 that contains some local egyptian card games in addition to foreign games like:
1. **الكومي**
2. **فلوس**
3. **الشايب**
4. **BlackJack/21**
5. **Solitaire**
---
## Members:
- Amir Ahmed Hassan
- Ahmed Sayed Bakry
- Omnia Ehab
---
# Algorithm and description: 
cards: 
0 = Joker ,               Unicode = 1F0BF

1 to 10 = numbers ,       Unicode = 1F0B1 - 1F0BA

11 = Queen ,              Unicode = 1F0BB

12 = Jack ,               Unicode = 1F0BD

13 = King ,               Unicode =1F0BE

global functions needed : 

- function generating random number between 0 and 12 (1 to 13 in some games)

- function that takes number as input and returns a character unicode of the card

----------------------------------------

# game 1 =  كومي

## classes:

### 1. playing hand DS :

BST / (edit) AVL  tree 
contains all cards in user hand

functions:

bool:

emptyhand: check if hand is empty

fullhand: check if hand is full

exists: check if card is in hand

integer:

drawcard: adds a card from deck to hand (takes integer and stores in BST createnode) 
 
setcard: removes card from hand and throws it to field , (searches and deletes a node) with the required number then returns it if found and display error if not found

displayhand: shows the content of hand (tree traversal)

throwshand: throw all hand cards to score when game ends

### 2. Field 
DS type : Hash table of size 14 (0 to 13) 

functions:

bool:

emptyfield : check if field is empty

exist(int) : check if number exists

removecard(int): removes a number from hash table

fieldset: sets a card to field (pushs a number into hash table) 

fieldstart : adds 4 random different numbers to field 

fieldremove(player*): removes all numbers from hash table and stores them in player score


### 3. playing deck
DS: 

HashTable with linked list collision managing, size = 13, linked list initial size = 4

contains 13*4 cards = 52 

functions:

void

isempty() -> check if set is empty

exists(int) -> check if a num is in table.

integer

pullcard()

checks that set is not empty then

checks if a random card is in the hash table, if yes, pulls it(aka deletes and returns it), if no generates another number




## class player :
### members:

name

hand

score list

score int


### functions:

reset

## class pc :

### members:

hand 

score list

score int

### function

reset

AI (plays card that makes most benefit)

---
## class game :

### members:

player player[3]

deck

pc

number_of_players

turn

field

gamover flag




### functions:

void

play()

while(gameover) 

turn = number of players

{

while (turn) 

turn(){


if turn == 1 //pc turn 

player[number-turn]

player[]handdraw

fieldexist () ? 

yes? field delete -> score++

no? field add 

Jack? field empty -> score++ 

turn--

} 


checks hands

checks deck

sets gameoverflag

}

gameover()

{

score display for players and pc

deciding winner

ending game 

}


- [x] Determine Plan
- [ ] Create AVL tree DS
- [ ] Create Playing Hand
- [ ] Create Hash Table DS of size 13
- [ ] Create Field
- [ ] Create Hash Table DS of size 13 and linked list collision management
- [ ] Create Deck
- [ ] Create human player turn
- [ ] Create AI player turn 
---




