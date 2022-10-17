#include "grid.h"

void Grid::setupDrawing(const int& x, const int& y, ofColor color, bool isFilled)
{
	setFilled(isFilled);
	drawRectangle(x, y);
}

void Grid::drawRectangle(const int& x, const int& y) const
{
	/*ofDrawRectangle(pixelSize.x * x, pixelSize.y * y, pixelSize.x, pixelSize.y);*/
	ofDrawRectangle(PIXEL_SIZE * x, PIXEL_SIZE * y, PIXEL_SIZE, PIXEL_SIZE);
}


void Grid::setFilled(bool isFilled)
{
	m_isFilled = isFilled;
	switch (m_isFilled)
	{
	case true:
		ofFill();
		ofSetColor(ofColor::black);
		break;
	case false:
		ofNoFill();
		ofSetColor(ofColor::gray);
		ofSetLineWidth(1);
		break;
	}
}

int Grid::calculateScreenSize()
{
	return PIXEL_SIZE * GRID_SIZE;
}

void calculatePixelSize()
{
	Grid::pixelSize.x = ofGetWidth() / Grid::grid_size.x;
	Grid::pixelSize.y = ofGetHeight() / Grid::grid_size.y;
}