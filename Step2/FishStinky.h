/**
 * \file FishStinky.h
 *
 * \author lingyundai
 *
 *  This is the class for stinky fish.
 */

#pragma once
#include "Item.h"
#include <memory>


/**The stinky fish class.
 * 
 */
class CFishStinky :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFishStinky() = delete;

	/// Copy constructor (disabled)
	CFishStinky(const CFishStinky&) = delete;

	CFishStinky(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

	/// Set the stinky fish location
	/// \param X X location
	/// \param Y Y location
	virtual void SetLocation(double X, double Y) override;

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Fish image
};

