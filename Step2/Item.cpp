/**
 * \file Item.cpp
 *
 * \author lingyundai
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"

/// Maximum allowed X value
const double MaxX = 950;

/// Minimum allowed X value
const double MinX = 100;

/// Maximum allowed Y value
const double MaxY = 750;

/// Minimum allowed Y value
const double MinY = 50;

/// Minimum distance from a nudging fish
const double MinDistance = 200;

/**
* Constructor
* \param aquarium The aquarium this item is a member of
*/
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}

/**
 * Destructor
 */
CItem::~CItem()
{
}


/**
 * The function for moving the fish.
 * \param X 
 * \param Y 
 */
void CItem::MoveFish(double X, double Y)
{
	// fishX, fishY is the position of a fish
	// stinkyX, stinkyY is the position of the stinky 
	double fishX = GetX();
	double fishY = GetY();
	// Create a vector in the direction we are from the nudger
	double dx = fishX - X;
	double dy = fishY - Y;

	// Determine how far away we are
	double distance = sqrt(dx * dx + dy * dy);
	if (distance > 0 && distance < MinDistance)
	{
		// Distance is less than our minimum
		dx *= MinDistance / distance;
		dy *= MinDistance / distance;

		fishX = X + dx;
		fishY = Y + dy;

		// Ensure fishX, fishY remain in the specified bounds
		if (fishX > MaxX)
		{
			fishX = MaxX;
		}
		if (fishY > MaxY)
		{
			fishY = MaxY;
		}
		if (fishX < MinX)
		{
			fishX = MinX;
		}
		if (fishY < MinY)
		{
			fishY = MinY;
		}
		mX = fishX;
		mY = fishY;
	}
}