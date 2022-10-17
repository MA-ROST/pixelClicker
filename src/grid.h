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
	static constexpr int PIXEL_SIZE{ 60 };
	bool m_isFilled = false;
public:
	static Point<int> pixelSize;
	static constexpr int GRID_SIZE{ 9 };
	static constexpr Point<int> gridSize{ 9,9 };

	void setupDrawing(const int& x, const int& y, ofColor color, bool isFilled);
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

	/**
	 * @brief Uses the present Pixel and Grid size to calculate a size for the screen.
	 * This Function assumes that the rows and columns are equal in length
	 *
	 * @return Returns what the size of the screen should be
	 */
	static int calculateScreenSize();


};

/**
 * Using the size of the window and the size of the grid that will be made,
 * the height and width will be calculated for each pixel
 *
 * @bug Generating LNK2001 unresolved external symbol "public: static struct Point<int> Grid::pixelSize" (?pixelSize@Grid@@2U?$Point@H@@A)
 * PixelBatman D:\College\VisualStudio\of_v0.11.2_vs2017_release\apps\myApps\PixelBatman\grid.obj
 */
static void calculatePixelSize();
