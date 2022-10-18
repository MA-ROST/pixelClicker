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
	
	static constexpr Point<int> gridSize{ 9,9 };

	/**
	 * @brief sets up the pixel for drawing, and then draws it
	 *
	 * @param x The x index of the vector
	 * @param y The y index of the vector
	 */
	void setupPixel(const int& x, const int& y);

	/**
	 * @brief runs when the user clicks within
	 * the bounds of a pixel, toggling m_isClicked
	 */
	void clickEvent();
private:
	/**
	 * @brief Depending on certain conditions (m_isClicked & isInBounds()),
	 * the pixel changes colors
	 */
	void setState() const;

	/**
	 * @brief Determines the visual look of a pixel based on a given number
	 * @param state changes the color of a pixel between stateColors
	 */
	void setStyle(int state) const;

	/**
	 * @brief through the amount of pixels and size of the window,
	 * the height and width of a pixel is determined
	 *
	 * @return The calculated height and width for each pixel
	 */
	static Point<float> calculatePixelSize();
	/**
	 * @brief determines the anchor value of each pixel, for isInBounds()
	 *
	 * @param x the index value of x from the pixel, from the array
	 * @param y the index value of y from the pixel, from the array
	 */
	void setPixelLocation(const int& x, const int& y);

	/**
	 * @brief using the size and location of each pixel,
	 * this function detects if the mouse is inside of a pixel.
	 *
	 * @return if the mouse's x & y are within the pixel
	 */
	bool isInBounds() const;
};


