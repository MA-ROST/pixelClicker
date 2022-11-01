#pragma once

#include "grid.h"
#include "ofMain.h"

/**
 * initialize at a specific size
 */
class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void mousePressed(int x, int y, int button);

	const string TITLE = "Pixel Clicker";
	array<array<Grid, Grid::gridSize.x>, Grid::gridSize.y> grid;
	
	Point<int> screenSize = { 600, 600 };
};
