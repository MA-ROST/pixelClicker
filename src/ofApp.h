#pragma once

#include "grid.h"
#include "ofMain.h"

/**
 * - initialize at a specific size
 */
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	const string TITLE = "Pixel Clicker";
	array<array<Grid, Grid::gridSize.x>, Grid::gridSize.y> grid;
	
	Point<int> screenSize = { 600, 600 };

};
