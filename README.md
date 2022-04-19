# Hall of Glory:
1. Amir Ahmed Hassan Mohamed
2. Ahmed Sayed Bakry
3. Omnia Ehab

# Kotshena
we had the idea to create Kotshena then add the Egyptian spice and
involve not only foreign game modes but also Egyptian games
------------------------------------------------------------------------------------------------------------
1. Egyptian Basra
2. Feloos		(Money Game)
3. The 21		(BlackJack)
------------------------------------------------------------------------------------------------------------
# General Code Flow:
1. Global Constants/Parameters definition
2. Utility Functions that were used in other complex functions definition
3. Data Structures Definition (AVL, Linked List, Doubly Linked List)
4. Game Objects Classes based on the pre-defined data structures
5. Each Game Class with all needed Game Objects
6. Playing the game at main by calling Basra.play() for example

### Time Complexity Studying:
1. measuring processor clocks using counts and clocks
2. measuring elapsed time in each part of code
3. comparing different data structures in terms of access and search speed
	to optimize code before implementation
	example: array complexity to search for 4 numbers that sums up to 10 is O(n^4)
			whereas same functionality can be achieved in a hash table with O(1)!!!

----------------------------------------------------------------------------------------------------------------------------
## Rules:
### Egyptian Basra:
1.1. randomly generated cards from Deck (max cards parameter = 52 or 104 or ...) where numbers (1->10) and Literals (J,Q,K)
1.2. in the starting round, each player draws 4 random cards and field has 4 random cards too.
1.3. in your turn you play a card to field, you take all field cards that have
	 same card number as yours or those who sums up to it and bank them as a score.
1.4. the "J" card is called "Jack" -El Wallad- has the ability to take
	 all cards on field as score, in case field is not empty.
1.5. when you steal the only card on field it is considered a "Basra" with a 10 points score
	example: 10 = 4+3+2+1 = 5+4+1 = 5+3+2 = 6+3+1 = 7+2+1 = 8+2 =....
1.7. When deck cards end, player with most score wins

parameters needed:	Deck Size (52 or 104)
this size can be controlled by a parameter N , cards = N*13, N by default is 4
N is the parameter that if we changed the complexity of code will increase

Classes needed:
Class Basra
	1.1. Card_Deck
	1.2. Playing_Field
	1.3. Playing_Hand
	1.4. Basra_Player
------------------------------------------------------------------------------------------------------------
### Egyptian Feloos (Money Game):
2.1. randomly generated cards from Deck (max cards parameter = 52) where numbers (1->10) and Literals (J,Q,K)
2.2. each player has Coins "parameter"
2.3. each player draws cards equally from deck in a -queue-like- structure
2.4. field is a stack like structure (only top most card appears)
2.5. in your turn you play your front most card to floor (push to stack)
2.6. when your front most card is by luck equal to the top most floor card, you win all cards and Coins on floor
2.7. when player cards end he has to borrow cards by paying money either to floor to another player (1 card = "Parameter = Amount of Coins")
2.8. when player turn comes and he has no more Coins or cards to play he loses

parameters needed:	Deck Size (52 or 104 or ...)
this size can be controlled by a parameter N , cards = N*13, N by default is 4
N is the parameter that if we changed the complexity of code will increase

Classes needed:
Class Money
	2.1. Card_Deck
	2.2. CardStack
	2.3. CardQueue
	2.4. Money_Player
------------------------------------------------------------------------------------------------------------
### The 21 (BlackJack Game):
3.1. Randomly generated cards from Deck (max cards parameter = 52) where numbers (1->10) and Literals (J,Q,K)
3.2. Each Player has 100 Coins
3.3. Each Player is allowed to draw random cards using "Draw" or "Hold"
3.4. Player aims to make the sum of cards in his hand approaches 21
3.5. if the sum of numbers surpassed 21, the player loses 10 coins
3.6. the player whose sum is near 21 wins 10 coins
3.7. player with zero coins loses the game at the end

parameters needed:	Deck Size (52 or 104 or ...)
this size can be controlled by a parameter N , cards = N*13, N by default is 4
N is the parameter that if we changed the complexity of code will increase

Classes needed:
Class BlackJack
	1.1. Card_Deck
	1.2. Playing_Hand
	1.3. BlackJack_Player
-------------------------------------------------------------------------------------
