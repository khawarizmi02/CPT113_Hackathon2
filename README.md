# CPT113_Hackathon2 Group 3

## Game Title: Card Dungeon

### Group Member:

#### Muhammad Khawarizmi Bin Jefri 158520
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
The gameplay is quite simple where when the player decide to start the game, the system will automatically set player to fight the monster from the first level. Player has to defeat the monster in order to go to the next level.
 
Before the fight begin the program will shuffle player's deck. Then, during the fight,at the early turn player will be drawn 5 cards to his hand. After that, each turn the player has to decide to choose a card that is available in hand to either use it for himself or to the monster. This turn will iteratively be made until either monster or player health drop down to zero.

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
Stack type data structure is use in the game mainly to manage the player’s deck in during their gameplay. The principal that the stack follows is the (LIFO) or Last-in-First-Out, so that the card can be added or removed from the top of the deck.
Usage:

1.	The Stack class is used to represent the player’s current deck during the game.

2.	Push(T) function is used to add card in the deck that allow players to pick new card during the gameplay.

3.	Furthermore, the pop(T) function is used to draw a card from the top of the deck. This happen when one of the 5 visible card is picked from the player’s   current hand during their fight against the monster. This is because after a card is picked they will leave their current node empty and a card will be drawn from the deck to replace the card.
   
### Screensshot
![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/start%20game.png)
Figure 1.1

Figure 1.1 screenshot show the main menu for the game that give option to the player whether they want to start the game, check their deck or exit the program.

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/my%20deck%20option.png)
Figure 1.2

Figure 1.2 show the page when the player choose my deck option. The player can see the deck that they will use during their gameplay and they can also choose to edit their deck or show all card that is  available.

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/edit%20card.png)
Figure 1.3

If they choose to edit their deck the system will give them the choice to add or remove card from their deck just like in figure 1.3. 

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/show%20all%20card.png)
Figure 1.4

The player can see all the card using the show card option.

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/monster%20fight.png)
Figure 1.5

Figure 1.5 show the gameplay  where the player need to use the card to fight the generated monster.

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/you%20win.png)
Figure 1.6

If the player win the system will give them choice to continue to the next level or not.

![alt text](https://github.com/khawarizmi02/CPT113_Hackathon2/blob/arepkimi-patch-4/ss%20gameplay%20image/you%20lose.png)
Figure 1.7

If they lose the system will send them to main menu.


### Gameplay Demo Video Link
CPT113 - Card Dungeon - Game Demo - Group 3

[YouTube Link](https://youtu.be/jpAiUn7k7XE)

### Requirement
Download [MinGW](https://sourceforge.net/projects/mingw/files/)
### CMD
```bash
g++ main.cpp StartGame.cpp Deck.cpp Deck.h Player.h Game.cpp Game.h Player.cpp Monster.h Monster.cpp LinkedList.h Stack.h -o main.elf
./main.elf
```
