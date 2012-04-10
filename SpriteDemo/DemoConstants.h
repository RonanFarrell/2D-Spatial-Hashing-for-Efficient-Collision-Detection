#ifndef CONSTANTS_H
#define CONSTANTS_H

class DemoConstants {
public:
	static int const SCREEN_WIDTH = 800;
	static int const SCREEN_HEIGHT = 800;
	static int const CELLSIZE = 200;	// 200x200 cells
	static int const COLUMNS = SCREEN_WIDTH / CELLSIZE;
	static int const ROWS = SCREEN_HEIGHT / CELLSIZE;
	static int const NUM_SPRITES = 20;   // How many sprites we want on-screen.
};


#endif
