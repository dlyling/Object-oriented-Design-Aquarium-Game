/**
 * \file Aquarium.h
 *
 * \author lingyundai
 *
 * The main class to represent the aquarium.
 */

#pragma once

#include<memory>
#include<vector>

class CItem;
class CFishStinky;

/**
 * The aquarium class
 */
class CAquarium
{
public:
	CAquarium();

	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);

	std::shared_ptr<CItem> HitTest(int x, int y);

	void MoveFront(std::shared_ptr<CItem> item);

	/// Detect when stinky fish is in aquarium
	/// \param stinky
	/// \param X X location
	/// \param Y Y location
	void FishSignal(CFishStinky* stinky, double X, double Y);

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};

