/**
 * \file Item.h
 *
 * \author lingyundai
 *
 * The main class to represent the aquarium.
 */

#pragma once

class CAquarium;

/**
 * The item class.
 */
class CItem
{
public:
	virtual ~CItem();

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics* graphics) = 0;

	/** Test this item to see if it has been clicked on
	 * \param x X location on the aquarium to test
	 * \param y Y location on the aquarium to test
	 * \return true if clicked on */
	virtual bool HitTest(int x, int y) = 0;

	/// Move fish location
	/// \param X X location
	/// \param Y Y location
	void MoveFish(double X, double Y);

	/** Get aquarium
	* \returns aquarium */
	CAquarium* GetAquarium() { return mAquarium; }

protected:
	CItem(CAquarium* aquarium);

private:
	/// The aquarium this item is contained in
	CAquarium* mAquarium;

	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	// Fish location in the aquarium
	double fishX; ///< X location for fish
	double fishY; ///< Y location for fish
	double stinkyX; ///< X location for the stinky fish
	double stinkyY; ///< Y location for the stinky fish
};

