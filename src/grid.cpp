#include "grid.h"

void Grid::setupPixel(const int& x, const int& y)
{
	pixelSize = calculatePixelSize();
	setState();
	ofDrawRectangle(pixelSize.x * x, pixelSize.y * y, pixelSize.x, pixelSize.y);
	setPixelLocation(x, y);
}

void Grid::setState () const
{
	if ( m_isClicked ) { setStyle (2); }
	else if ( isInBounds() && !m_isClicked ) { setStyle (1); }
	else { setStyle (0); }
}

void Grid::setStyle (int state) const
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

Point<float> Grid::calculatePixelSize()
{
	Point <float> output{
		static_cast <float> (ofGetWidth()) / gridSize.x,
		static_cast <float> (ofGetHeight()) / gridSize.y
	};

	return output;
}

void Grid::setPixelLocation(const int& x, const int& y) 
{
	pixelLocation = { pixelSize.x * x , pixelSize.y * y };
}

bool Grid::isInBounds () const
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
