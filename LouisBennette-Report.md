Introduction to Programming assignment 2
----------------------------------------

**Overview:**
For this assignment the group was tasked with making a egyptian survival horror game inspired by Amnesia. The game would incorporate puzzles and an elusive eyeball opponent that creeps up on the player. 
The team was originally made up of 7 people, 3 programmers and 4 artists. 
One of our artists either dropped out or was removed from out group during development.
The programmers had the required features of the game described to us. We created a short task list and split some core tasks amongst each other. When our first tasks were completed we needed a context in which to merge them. We couldn't implement any of the puzzle tasks reliably without a map. Because of this, development of the project really started after christmas when a map was delivered. In the remaining time we managed to create a good resemblance to the original concept. We achieved all of our key programming features. 


**My tasks:**
My principal task was handling the inventory system. This is a task that muted and changed through the development, it was an interesting challenge for me. 
I was also tasked with creating torches that light up when in range of the player's projectiles. As well as most pickup item related features. 


**Implementation:**
I tasked myself with learning the unreal blueprint and cpp system. I did this in my spare time by following tutorials and creating small features in the default unreal test world. 
Early work I did on the game was in cpp but I quickly changed over to the blueprint system as it has much more documentation online.

![enter image description here](http://i614.photobucket.com/albums/tt226/Horza_Krasus/BP_2.png)

I started to build the inventory with very simple commands 'E' would pickup an item and 'I' would show the inventory. The items were implemented by making every pickup item a child of a pickup item blueprint. I used a struct to store all information about the item, the struct is a variable of the items. This means when an item is picked up the actor can be despawned and the struct can be saved in an inventory array in the player blueprint. When an item is dropped from the inventory, the class reference to that item is looked up in the struct and used to spawn that item in the scene. Additionally the struct used to spawn the item is removed from the inventory array. When the inventory is open, the control state changes and stops the user from walking around, it also displays the mouse and enables mouse events.

![Add Item](http://i614.photobucket.com/albums/tt226/Horza_Krasus/BP_3.png)

![Toggle Mouse control](http://i614.photobucket.com/albums/tt226/Horza_Krasus/BP_1.png)

The game has clues in the form of notes scattered around the map. The player can pick these up but the behavior of these items is different. When clicked instead of spawning the item back in the scene the note message is displayed. This is done by rendering a texture on a UI image widget.

I worked on other small tasks implementing small pieces of code such as torches that light up when in range of a projectile and moving the sarcophagus lid. 

The development cycle for this project was made quite difficult because unreal operates using binary files. This mean’t that resolving merge conflicts required either the new file to overwrite the old or to simply keep the old. This made some parts of the development difficult because I ended up losing work if another programmer had made a change between my pull and push. 
Because of this and mainly with work involving the map, I lost a few hours of work placing objects, etc.  In future I would possibly use a different versioning system that allows the user to lock files out or I would look into using unreal ascii file formats.  




