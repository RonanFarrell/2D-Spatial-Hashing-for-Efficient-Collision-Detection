#include "stdafx.h"
#include "CollisionManager.h"


CollisionManager* CollisionManager::mInstance = 0;

CollisionManager::CollisionManager() {}

CollisionManager* CollisionManager::instance() {
	if (mInstance == 0) {
		mInstance = new CollisionManager();
	}
	return mInstance;
}

//Function that checks for collisions between 2 CustomSprite, by comparing the distance between them
//with their radius
bool CollisionManager::CheckCollision(CustomSprite const * const cs1, CustomSprite const * const cs2) {
	
	sf::Vector2f vecBetween = (cs1->GetPosition() - cs2->GetPosition());	//Gets the distance vector between the 2 CustomSprites
	
	float lengthSqrd = (vecBetween.x * vecBetween.x) + (vecBetween.y * vecBetween.y);	//Gets the length squared between the 2
	
	float minDist = cs1->radius() + cs2->radius();	//Adds the radii
	
	//Checks the length squared against the radius squared
	if (lengthSqrd <= (minDist * minDist)) {
		return true;
	}

	return false;
}

