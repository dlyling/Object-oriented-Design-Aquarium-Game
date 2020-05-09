/**
 * \file Aquarium.cpp
 *
 * \author lingyundai
 */


#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishGoldeen.h"
#include "FishBubble.h"
#include "FishStinky.h"
#include <algorithm>


using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
}


/** Draw the aquarium
 * \param graphics The GDI+ graphics context to draw on
 */
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/**
 * When you grab an item with the mouse, 
 * move it to the end of the list mItems. 
 * \param item 
 */
void CAquarium::MoveFront(std::shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
	mItems.push_back(item);
}

void CAquarium::FishSignal(CFishStinky* stinky, double X, double Y)
{
	for (auto item: mItems)
	{
		if (item.get() != stinky) 
		{
			double X = stinky->GetX();
			double Y = stinky->GetY();
			item->MoveFish(X, Y);
		}
	}
}