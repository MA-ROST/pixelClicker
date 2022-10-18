#include "grid.h"

Point<float> Grid::calculatePixelSize()
{
	Point<float> output{ static_cast<float>(ofGetWidth()) / gridSize.x,
		static_cast<float>(ofGetHeight()) / gridSize.y };


	return output;
}

void Grid::setPixelSize()
{
	pixelSize = calculatePixelSize();
}

void Grid::setupDrawing(const int& x, const int& y, ofColor color)
{
	setState();
	drawRectangle(x, y);
	setPixelLocation(x, y);
}

void Grid::drawRectangle(const int& x, const int& y) const
{
	ofDrawRectangle(pixelSize.x * x, pixelSize.y * y, pixelSize.x, pixelSize.y);
}

void Grid::setState ()
{
	if ( m_isClicked ) { setState (2); }
	else if ( isInBounds() && !m_isClicked ) { setState (1); }
	else { setState (0); }
}

void Grid::setState (int state)
{
	ofFill();
	switch ( state ) {
		case 1: ofSetColor (hover);
			break;
		case 2: ofSetColor (active);
			break;
		default: 
			ofNoFill();
			ofSetColor (inactive);
			break;
	}
}

void Grid::setPixelLocation(const int& x, const int& y) 
{
	pixelLocation = { pixelSize.x * x , pixelSize.y * y };
}

bool Grid::isInBounds ()
{
	return static_cast<float>(ofGetMouseX()) >= pixelLocation.x && 
	       static_cast<float>(ofGetMouseX()) <= pixelLocation.x + pixelSize.x &&
	       static_cast<float>(ofGetMouseY()) >= pixelLocation.y && 
	       static_cast<float>(ofGetMouseY()) <= pixelLocation.y + pixelSize.y ? true : false;
}

void Grid::clickEvent ()
{
	if (isInBounds()) {
		m_isClicked = m_isClicked ? false : true;
	}
}
