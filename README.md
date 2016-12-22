# Descent

## How to download the project and edit it in Unreal ##
Pre-requirements:
- Unreal (4.14.0 version)
- GitHub Desktop app

Initial steps (only needed one time):
- In the GitHub project's website, click the green button to the right named _Clone or Download_.
- Then, click the option to _Open in Desktop_. This will open the GitHub Desktop app and prompt you to select where in your computer to save the project.
- Wait until the project is downloaded (it will probably take a lot of time if there are big asset files).

Working steps:
- At the top of the GitHub Desktop app, left to the Commited Changes tab (at first it will probably say '_No uncommited changes_'), there is the branch dropdown (at first it will say '_master_'). You can change the branch you are working on here. **NEVER** WORK ON MASTER!
- To create a branch, click the button to the left of the branch dropdown. Try to name your branch something significant, like the name of the feature you are going to work on.
- Once you are in your branch, open the folder in your computer that contains the project.
- Right click on the Descent.uproject file, and select Open with > Unreal Editor (4.14.10).
- Make the changes you want.
- Whenever you have made a significant change, and you made sure the game is working (by running it in the Unreal Editor), you can create a commit in the GitHub Desktop app. To do so, go to the Committed Changes tab at the top, write the name of the commit in the Summary field, and optionally give a longer description to the commit. Try giving signficant names, so other people can know what you worked on in the commit.

Final steps:
- Once you finished your work, it's time to merge your branch to master. To do so, while in your branch, click the _Pull Request_ button to the right, give a name and description, and click _Send Pull Request_.
- Your branch will be reviewed by someone else at this point.
- If any changes need to be made, just make the commits you need to. (No need to make a new pull request again)
- If everything is OK, your work will be merged to master.
