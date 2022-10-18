// Oct 16 10:27 PM
#pragma once

#include "ofMain.h"
#include "point.h"

/**
 * point<int> grid_size {x, y} - the count of rows and columns
 * bool isFilled - if the pixel is currently clicked or not (black or white)
 *
 * void drawRectangle(const int& x, const int& y, const int& w, const int& h);
 * void setFilled();
 *	- runs on click
 * void setPixelSize()
 *	- get window height and width
 *	- divide by the row and column count
 *	- apply the new sizes to each pixel (redraw)
 *	- applied on start and resize
 */

 /**
  * @breif creates a grid and its incidences
  */
class Grid
{
	bool m_isClicked = false;

	Point<float> pixelSize, pixelLocation;

	enum stateColor {
		inactive	= 200,
		hover		= 220,
		active		= 0
	};

public:
	
	static constexpr Point<int> gridSize{ 20,20 };

	void setupDrawing(const int& x, const int& y, ofColor color);

	void clickEvent();
private:
	/**
	 * @brief Draws a rectangle based on the given pixel size,
	 *		using the x & y values for the location
	 *
	 * @param x The x index of the vector
	 * @param y The y index of the vector
	 */
	void drawRectangle(const int& x, const int& y) const;
	/**
	 * @brief Changes a pixel to either be white or black
	 *		based on if isFilled is true or not
	 *
	 * @param isFilled A boolean to indicate weather the pixel is filled or not
	 */
	void setFilled(bool isFilled);

	void setState() const;
	void setState(int state) const;

	static Point<float> calculatePixelSize();
	void setPixelLocation(const int& x, const int& y);

	bool isInBounds() const;
};


