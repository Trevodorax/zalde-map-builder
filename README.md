# The project
This is a map builder for zelda-like games.

It features an interface to choose which tile to put in each place, and lets you export it as a map file.

It also allows you to modify existing map files.

# Making the app work
## Get the project and dependencies
### Ubuntu / Debian
`sudo apt-get install gcc git make libsdl2-dev libsdl2-ttf-dev`
### Windows and Mac
![Good luck](https://media.giphy.com/media/pDgHg2Lcju3Ty/giphy.gif)

## Clone the project
`git clone https://github.com/Trevodorax/zalde-map-builder.git`

## Compile the project
### Go in the project
`cd zalde-map-builder`
### Compile using make
If on Window or Mac, update the Makefile (the part where we use sdl and sdl-ttf) to make sdl work.

If it doesn't work, just use a good OS and it should be just fine !

Then, run make to generate the executable file :

`make`

### Run the executable
`./bin/index`

# Using the app
## Creating maps
When the app is open, you can see multiple things :
- On the left, a list of textures that you can add to your map
- On the right, the map itself (it should be a grey rectangle at the beginning)
- Additionnal widgets on the right of it (to delete, see your currently selected texure, and save your map)

To create a map, just start adding textures to the map by clicking on a texture and clicking on a tile of the map.

If you misclick or change your mind, click the cross icon and then click on the tiles you want to erase.

If at any point, you want to know which texture you are using, it is displayed in a box on the right of the map.

## Saving a map
To save the map, you must give it a name. Just type any name and it will appear at the bottom of the window.

When you are done, don't forget to save it by clicking the save icon on the right of the map ;)

**BE CAREFUL** If you give it a name that already exists in the maps folder of zalde, it will erase the previous file !

## Updating existing maps
If you have a map from someone else that you wish to modify, or you saved a map and want to edit it, you can simply open it in the app by giving the path to the map in parameter.

The path must be given relatively to the root of the project.

For example : `./bin/index maps/myMap.zalde`

The previous map file won't be deleted as long as you don't name it the same as it was before ;)

# Map files
Map files must follow a very specific pattern.
It is described in the image below :

![zalde-map-format](https://user-images.githubusercontent.com/73560235/211220525-5a5f7a4b-c4eb-45a9-90be-ce8fc86c6149.jpeg)

# Technologies
## Graphical user interface
We used SDL2 for the GUI.

We also used sdl-ttf to display text in the input box.

## Compilation
We used make, and its wonderful wildcards to have a good, dynamic makefile.

You can therefore add any .c file, as long as there is a .h file with the same name in the `include` folder.

# Collaboration on the project
## Git good practices
The branch and commit naming we use are described in the git-practices.md file in the root of the project.

## Communication tools
We use discord as primary communication tool.

We also have a Trello board in which our tasks are described, backlogged, and organized in a kanban.

## Collaborators
### The core
The core functionnality and setup of the project was done by Paul Gaudeaux.

### Product
The textures were extracted and organized by Johan Ribeiro.

The design and functionnalities were decided by Johan and Paul.

### Features
The features were shared between Paul and Johan.

For more information about who did which parts, you can look at the git history.
