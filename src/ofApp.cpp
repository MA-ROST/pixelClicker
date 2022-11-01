#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColor(ofColor::white);
    ofSetWindowTitle(TITLE); // Set the window title
    ofSetWindowShape(screenSize.x, screenSize.y);
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int x = 0; x < Grid::gridSize.x; ++x) {
        for (int y = 0; y < Grid::gridSize.y; ++y) {
            grid[x][y].setupPixel(x, y);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    for (int x = 0; x < Grid::gridSize.x; ++x) {
        for (int y = 0; y < Grid::gridSize.y; ++y) {
            grid[x][y].clickEvent();
        }
    }
}