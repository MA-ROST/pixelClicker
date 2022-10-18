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

void Grid::setupDrawing(const int& x, const int& y, ofColor color, bool isFilled)
{
	setFilled(isFilled);
	drawRectangle(x, y);
}

void Grid::drawRectangle(const int& x, const int& y) const
{
	/*ofDrawRectangle(pixelSize.x * x, pixelSize.y * y, pixelSize.x, pixelSize.y);*/
	ofDrawRectangle(pixelSize.x * x, pixelSize.y * y, pixelSize.x, pixelSize.y);
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