/**
 * \file FishGoldeen.h
 *
 * \author lingyundai
 *
 * This is the class for goldeen fish.
 */

#pragma once
#include "Item.h"

#include <memory>

/**
 * The goldeen fish class. 
 */
class CFishGoldeen :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFishGoldeen() = delete;

	/// Copy constructor (disabled)
	CFishGoldeen(const CFishGoldeen&) = delete;

	CFishGoldeen(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Fish image
};

