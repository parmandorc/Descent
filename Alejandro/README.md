Alejandro Garzón Pascual
Programmer

#Main contributions:

## Pick up, drop and throw objects controls
	
This feature was the base for picking up/dropping/throwing any object that was simulating physics.
It was mainly based on doing a LineTraceByChannel from the player camera position and adding the proper logic when pressing/releasing mouse buttons.
It was also the start for the Pick up to Inventory feature.
How to throw rays and evaluate the hit result has been the main outcome from this feature.

##Blocking door trap

This trap was intended to block a door by falling rocks from the ceiling.
It was approached by adding a box trigger that when the player overlapped it, an event was dispatched to spawn rocks simulating physics. 
The rock spawners were placed in the environment. They were coded with some editable properties for the artists so they could change the spawning cadence, number of rocks to spawn and spawning start delay.
A considerable amount of time was needed for tweeking the spawners in order to achieve a good result. 
However, taking into account that the result wasn't deterministic and sometimes not very ideal, it suggests the a different approach might be needed that doesn´t rely on spawning rocks. 
For example, moving a group of static meshes(without physics) could have been much easier to implement and maybe with a better good looking result. 
All in all, how to spawn dynamic actors and using the event dispatcher has been the main outcome from this feature.

##Skulls puzzle

This puzzle consisted on collecting skulls from the environment with the purpose to place them in a balance. Each time an skull was placed,a door was opened slightly.
The puzzle was set up editable so artist could add the number of skulls needed. The skulls were using the inventory item template so they could be kept in the inventory.
Whenever an skull was colliding with a box placed in the balance, the actual skull was destroyed and an invisible static one that was already placed on the balance was made visible.

##Reviewed features

Eye AI: Simple behaviour tree and eye patrolling in the environment using waypoints.
Pick up to inventory + UI: Usefull so I could applied the item template to the skulls in order to collect them.
9 tile puzzle & Altar puzzle: Good to see how this puzzle and Altar puzzle was using cameras that probably could be applied to the skulls puzzle too.
Day night/switch puzzle : Usefull how it work as I needed to place some skulls only during the day.


#TEAM EVALUATION
##What didn't work and needs to improve:

###Lack of main features specifications from a design point of view

It took around two weeks to start coding something game specific, because the specs weren't clear at all, not defined puzzle, etc.
In part, programmers fault expecting artist to work on the design of the game too. Probably programmers should have got more input on the design of the game. Also, as a team, we should have done an accesible document about the different puzzle and mechanics of the game.

###Scrum board 
	
I personally set up a board in github so we could add all the tickets (stories and bugs). The main goal was to track progress and have visibility about the state of the project. Programmers start using it but not the artist. It was hard to check how the art was going for example. 
Clearly, a communication problem on not emphasizing the usefulness of the scrum board.

###Work integration process
	At the end of the project, many features needed to come and merge into the map. The map was a binary file that didn´t merge well and always was
	creating conflicts. We end up many times redoing some work because of this issue. At the end of the project, having 3 programmers was more a trouble than 
	a solution, where some programmers were idle and waiting for others to finish in order to avoid conflicts. Definitely, something to improve and take into account in the future.

##What went well

###Feature based branches
	We split all the features between programmers, created different branches for them so we could work separately. We focus first on making it work, later merge and start integrating
	the feature into the map(quite problematic at the end), fix bugs and polish the feature.

###Different communication channels (whatsapp group, skype programming meeting)
	Definitely they help with any unclear design issue or programming problem


##Team member recommendation: Pablo Armando Rodríguez Codes
###Reasons:
-He dealt with different puzzles that added nice camera transitions plus the AI of the game. 
-He gave nice review comments on some of the pull requests. 
-He took the responsibility the final days to make sure that all the features were coming and merging properly.


