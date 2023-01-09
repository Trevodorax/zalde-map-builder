#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define WINDOW_SIZE_X 2000
#define WINDOW_SIZE_Y 900

#define TILE_SECTION_POS_X 50
#define TILE_SECTION_POS_Y 50
#define TEXTURE_PICKER_SIZE 800
#define TEXTURE_PICKER_TILES_PER_ROW 10
#define TEXTURE_PICKER_TILE_SPACING 5
#define TEXTURE_PICKER_TILE_SIZE TEXTURE_PICKER_SIZE / TEXTURE_PICKER_TILES_PER_ROW

#define NAVIGATION_BUTTON_SIZE 50

#define BUTTON_TYPE_TEXTURE_PICKER 't'
#define BUTTON_TYPE_NAVIGATION 'n'
#define BUTTON_TYPE_MAP_TILE 'm'
#define BUTTON_TYPE_ERASE_BUTTON 'e'

#define PATH_TO_TILESET "assets/tileset/"

#define MAP_SECTION_POS_X 950
#define MAP_SECTION_POS_Y 50
#define MAP_SECTION_SIZE 800
#define MAP_SIZE 16
#define MAP_TILE_SIZE MAP_SECTION_SIZE / MAP_SIZE

#define EMPTY_TEXTURE_CHAR 'A'
#define EMPTY_TEXTURE_NUMBER 0

#define ERASER_POS_X MAP_SECTION_POS_X + MAP_SECTION_SIZE + 30
#define ERASER_POS_Y 50
#define ERASER_BTN_SIZE 50

#define CURRENT_TEXTURE_INFO_POS_X MAP_SECTION_POS_X + MAP_SECTION_SIZE + 50
#define CURRENT_TEXTURE_INFO_POS_Y 130
#define CURRENT_TEXTURE_INFO_SIZE 80

#endif