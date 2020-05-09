/**
 * \file FishBeta.h
 *
 * \author lingyundai
 *
 * This is the class for beta fish.
 */

#pragma once

#include "Item.h"
#include <memory>


/**
 * The beta fish class.
 */
class CFishBeta :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;

	CFishBeta(CAquarium* aquarium);

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

private:
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; ///< Fish image
};

