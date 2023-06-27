# CPT113_Hackathon2 Group 3

## Game Title: Card Dungeon

### Group Member:

#### Muhammad Khawarizmi Bin Jefri
#### Muhamad Hazim Bin Azman
#### Muhammad Arif Hakimi Bin Shamsul Hisham 155462

### Description

### Game Features

#### Ability Type
The game implemented various ability type into the program to add more depth and strategic planning when the player experiencing the gameplay.
For the example the ability type that exist in the game is:
1.	Weapon
Weapon card represent normal attack type that player can use to deal damage to the monster. There is various kind of weapon type card that the player can choose to add into their deck. Adding more weapon type card can increase the players offensive ability to fight the generated monster.
2.	Spell 
Spell is a versatile card type that allow the user to have various effect from its incantation. For example, there are spell that allow user to heal, attack and also providing buff to the players. The downside of using spell is that there exists monster that immune to spell type card.
3.	Armor
Armor type card is a defensive ability card to improve the players endurance from monster attack. Having an armor type card is a must since it prevents the player from dying.
4.	Potion
Potion is a support type card that help the player recover their health that has been      decrease from monster attack. The player can use this card with the armor type card to keep attacking the monster without worrying about monster attack.

#### Monster Level and Type
To make the game more interesting, the gameplay allow the player to beat various level of monster with different type of skill. For example:
1.	Monster Level
The monster that are generated in the are categorized into 5 different level which is Level 1, Level 2, Level 3, Level 4, and Level 5. The higher the level of monster the stronger the monster is. For example, Level 5 has the highest amount of health and attack compared to other monster from the lower levels.
2.	Monster type
There are three type of monster that exist in the game which is Normal type, Spell type and Attack type. The type of the monster indicate their trait that the player can use to find the monster’s strength and weakness. For example spell type offensive card is less effective toward spell type monster.

#### Edit Deck	
There is also feature that give players the ability to edit their deck. Using this feature the player can customize and modify the deck so they can strategize their plan when fighting the monster. For example, edit deck features allow players to:
1)	Add card

 Player can add the card that they prefer into their deck based on the strategy that they want to use to defeat the monster in the gameplay.

2)	Remove card

 The player can remove one of the card that is less effective during the gameplay In the deck so they can add new card that is more usable.

3)	Clear deck

 The player can delete the whole deck of card in the deck storage. This allow player to fully modify the whole deck based on their strategy to defeat the monster in the gameplay.

4)	Show all card
This choice allow the players to check their current deck so they can decided whether they want to use it against the monster or edit the deck to their preference.

#### Shuffle Deck
To increase the game depth and uniqueness of the game the order of cards in the player deck is randomize.For example, at the start of the game or in another monster's level, player’s deck will automatically shuffle by itself. This  will allow the player to use different card in every game making the gameplay more interesting.	


### Gameplay

### Object Oriented Implementation

### LinkedList and Stack Queue Implementation
#### Linked List
The linked list method is implemented into the game to represent player’s deck. The usage of linked list allow the player to manipulate the deck efficiently based on their strategy. The implementation can be seen in the LinkedList class from the code.

Usage:
1.	The Player class uses the LinkedList<int> to hold the player's deck of cards. Every node in the linked list represents a card, and each node's value corresponds to the card ID.

2.	The player's deck is manipulated via linked list operations such as append, remove, and retrieve. In the Player class the operation is execute using method such as setDeck(), deletePlayerCard(), addPlayerCard(), and clearPlayerDeck().

For example:
a)	deletePlayerCard(int value) function is use in the Player class to allow the player deleting a card from the given deck. The function delete the card by calling the deleteNode(value) function to remove a node based on their identity which is the Card ID.

b)	Next, addPlayerCard(int value) function is used to enable new card to be added into the deck. The function call the appendNode(value) function to add new node based on the Card ID to the tail of the linked list. After that, the new deck will be update into the playerDeck.txt file using setdeck() function.

c)	Beside, there is also the clearPlayerDeck() function that can delete the entire deck based on the player’s request. The function calls the destroylist() function from the linked list to remove all the node from the linked list. Then the current empty deck will be update into playerDeck.txt file by the setdeck() function.

#### Stack
Stack type data structure is use in the game mainly to manage the player’s card in their current hand. The principal that the stack follows is the (LIFO) or Last-in-First-Out, so that the card can be added or removed from the top of the stack.

Usage:
1.	The Stack class is used to represent the player’s current usable card during the game.

2.	Push(T) function is used to add card on top of the stack that allow players to pick new card during the gameplay.

3.	Furthermore, the pop(T) function is use to remove a card from the top of the stack. This function is used when the player apply a card  in their current hand during fight against the monster.

#### Queue
If stack represent the player’s current card in their hand, queue represent the deck of card that the player use during the fight against the monster. The queue use First-In-First-Out(FIFO) principal that allow the cards to be added to the rear or tail of the queue and removed from the front.

Usage:
1.	Firstly the card deck in the game is mange using Queue method.

2.	To add card to the bottom of the deck, the system use enqueue(T) function  so the data can be added to the tail of the used queue.

3.	Next, dequeue(T) function is implemented to make a system that can remove card from the top of the deck. This action happens when the player draw a card from the deck during the gameplay.





### Screensshot

### Gameplay Demo Video Link
CPT113 - Card Dungeon - Game Demo - Group 3
https://youtu.be/jpAiUn7k7XE

### Requirement
Download [MinGW](https://sourceforge.net/projects/mingw/files/)
### CMD
```bash
g++ main.cpp StartGame.cpp Deck.cpp Deck.h Player.h Game.cpp Game.h Player.cpp Monster.h Monster.cpp LinkedList.h Stack.h -o main.elf
./main.elf
```
