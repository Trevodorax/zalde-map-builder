# zalde-map-builder
## Project
This is a map builder for zelda-like games.
It features an interface to choose which tile to put in each place, and lets you export it as a map file.
It also lets you modify existing map files.

## Using the app
### Get the project and dependencies
#### Ubuntu / Debian
`sudo apt-get install gcc git make libsdl2-dev libsdl2-ttf-dev`
#### Windows and Mac
![Good luck](https://media.giphy.com/media/pDgHg2Lcju3Ty/giphy.gif)

### Clone the project
`git clone https://github.com/Trevodorax/zalde-map-builder.git`

### Compile the project
#### Go in the project
`cd zalde-map-builder`
#### Compile using make
If on Window or Mac, update the Makefile (the part where we use sdl and sdl-ttf) to make sdl work

`make`

#### Run the executable
`./bin/index`

## Map files
Map files must follow a very specific pattern.
It is described in the image below :

![zalde-map-format](https://user-images.githubusercontent.com/73560235/211220525-5a5f7a4b-c4eb-45a9-90be-ce8fc86c6149.jpeg)

## Technologies
We used SDL2 for the GUI.
