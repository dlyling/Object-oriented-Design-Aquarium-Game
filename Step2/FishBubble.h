/**
 * \file FishBubble.h
 *
 * \author lingyundai
 *
 * This is the class for bubble fish.
 */

#pragma once
#include "Item.h"
#include <memory>


/**
 * The bubble fish class.
 */
class CFishBubble :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFishBubble() = delete;

	/// Copy constructor (disabled)
	CFishBubble(const CFishBubble&) = delete;

	CFishBubble(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Fish image
};

