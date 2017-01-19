Pablo Armando Rodríguez Codes

Role: AI/gameplay programmer

This document describes the work I have done in the project and the features I have contributed with.

# AI

As the AI programmer in the team, one of the main tasks has been the development of the AI system of the game. Because of the limited time of the project, it was difficult for artists to create humanoid-type models for the enemies in the game. Therefore, we settled on one only enemy that would have the shape of an eye, who would chase the player to try to kill them.

The AI of the eye uses a behaviour tree that controls two basic states of the AI. 

![BehaviourTree](./BlueprintScreenshots/AI_BehaviourTree.png?raw=true)

The lowest priority state (the right part of the tree) is dedicated to the patrolling behaviour. In this state, the eye will patrol cyclically through a set of waypoints.

The highest priority state (the left part of the tree) controls the chasing behaviour, and could be defined as the following:

- The eye will chase the player whenever it has vision of them.
- The eye will see the player if they are at a certain distance from the eye and inside a certain angle range in front of the eye.
- The eye will see the player if they are at a certain distance (smaller than the previous one), regardless of what the relative position is (even if they are behind the eye, if close enough).

This tests are performed with a simple distance and angle check.

![DistanceCheck](./BlueprintScreenshots/AI_VisionRange.png?raw=true)

- The eye will not see the player if there are obstacles that block vision of them.

This test is performed with a line trace over the Visibility channel that goes from the eye to the player.

![VisibilityTest](./BlueprintScreenshots/AI_VisibilityTrace.png?raw=true)

- When the eye loses vision (described in the previous terms) of the player, they will go to their last known location. Once there, the eye will wait for a certain amount of time, and if they haven’t found the player, the patrolling behaviour will be resumed. If at any point, the eye regains vision of the player, it will start chasing them directly.


Even if the behaviour tree is rather simplistic, it has served to gain familiarity with several features of Unreal’s AI systems, such as the actual behaviour trees, including blackboard assets, tasks, decorators and services. However, a lot of work has been devoted to the navigation system (NavMesh), and tweaking the different settings so that the navigation is performed correctly through the whole pyramid, being narrow corridors and specially stairs (due to their high slope) the bigger challenge.

![NavMesh](./BlueprintScreenshots/AI_NavMesh.png?raw=true)

# Gameplay

However time-consuming and challenging the development of the AI has been, a big amount of work has also been done in general gameplay programming, specifically related to puzzles in the game. The puzzles I have developed entirely have been the 9-tile puzzle, the day/night switch and the main altar puzzle (heart & feather).

All of these have required a lot of experimentation with collision settings, camera animations, object management, and even some level streaming (used for day and night scenarios).

The following are two examples of the programming that has done in this area:

### Blueprint of the PiecePlacingSocket class

![PiecePlacingSocket](./BlueprintScreenshots/Puzzle_PieceSocket.png?raw=true)

This is used in several puzzles (day/night switch and main altar puzzle, and although it is not used directly, also influenced the implementation of the skulls puzzle).

How it works is by having a reference to a static object that has the same class (thus the same mesh) of the piece that would have to be placed. At BeginPlay, the static objects is disabled (invisible, no collision, no ticking). Whenever an actor overlaps the collider of the blueprint, if it is of the same class of the referenced piece, it will get destroyed and the static piece will be enabled. At this point, the puzzle manager receives an input event.

Whenever the player interacts with the socket (by right clicking, handled in the FirstPersonCharacter blueprint) after the piece has been placed, and only if the piece is set to be detachable (or retrievable), the static piece will be disabled again, and a new actor of the same class will be spawned in the scene. At this point again, the puzzle manager receives an input event.

At first, an alternative was tried out in which the reference the socket has is just a dummy object, and so the overlapping actor would be snapped to the position and orientation of said dummy object. However, force setting location and rotation of an actor that is simulating physics in Unreal has proven to be very tricky and buggy. Hence, this solution was discarded.

### Day / night switch

This puzzle is very interesting because the solution that has been implemented involves Unreal's Level Streaming. By having two sublevels or scenarios (which work like parallel dimensions if you will), it is very easy to, not only toggle between both, but also to set up objects in the scene that will only appear during day or night. To achieve this, one only has to place the objects in the scene while one of the streaming levels is opened, as oppossed to adding to the so called 'Persistent Level'. 

Furthermore, an addition to the new version of Unreal, 4.14, makes this solution even more elegant, since they added the possibility to set this streaming levels as lighting scenarios. This enables separate _\<MapName>\_BuiltData.uasset_ files for each scenario, each of which contains the lighting build for each level, so each seperate level can have its own baked lighting.

The puzzle's blueprint consists of three parts:

- Initial animation

![DayNightSwitch_PreAnimation](./BlueprintScreenshots/DayNight_PreAnimation.png?raw=true)

Here we perform a camera animation to switch to a camera that has a global view of the map, from which the day/night switch is better appreciated. We also disable input from the player, as well as the HUD, and start a fade to white so the scenario switch happens seamlessly and smoothly.

- Toggle scenario

![DayNightSwitch](./BlueprintScreenshots/DayNight_ToggleMap.png?raw=true)

Here we perform the actual switch of the scenarios, by unloading one and loading the other. Notice the delay after the switch, due to the need to load the files from disk, which stutters the engine and slows the game down for a bit. This way, the screen is kept white during the process and no stutter is seen.

- Final animation

![DayNightSwitch_PostAnimation](./BlueprintScreenshots/DayNight_PostAnimation.png?raw=true)

Finally, here we perform the inverse of the initial animation, fading back from white, switching back to the player's camera and reenabling input and HUD.

# Team

Part of the challenges of the projec has been the communication between the different parts of the team, specially between artists and programmers, which turned out to be even more significant due to the lack of experience by the former with the git workflow. For that reason, I decided to create a set of step-by-step instructions in the main [README.md](https://github.com/parmandorc/Descent/blob/master/README.md) file in order for artists to know how to clone the repository and make changes to it.

The workflow between programmer has been using branches for all changes, and pull request reviews from at least one other programmer. However, another big difficulty has been the resolution of conflicts between branches due to the binary files in Unreal, but with a little practice (and the ability to copy-paste most of the changes from asset to asset) this problem has been reduced over time.

# Future work

Part of the group has already declared their intentions to keep working on the project after the deadline, and maybe even publishing the game, which is really exciting, and would allow for building and even better game that would look great in all of our portfolios.

Part of the changes that I see I would make in the future stages of the project is doing some research on Unreal’s Environment Query System and how it could be introduced to the game’s AI system. The EQS allows for complex tests on different variables on the environment, to create very complex behaviours.

However, probably the most immediate change would be porting all of the work done to C++ code, since everything was done in Blueprint due to the limited time.
