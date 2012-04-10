#include "stdafx.h"
#include "MapManager.h"

// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager() {
	for( int i = 0; i < 16; ++i){
		m_buckets.insert(make_pair(i, list<CustomSprite *>()));
	}
}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::ClearBucketLists() {	
	// TODO: Implement logic here...

	for (int i = 0; i < m_buckets.size(); ++i) {
		m_buckets.at(i).clear();
	}
	
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::RegisterSprite( CustomSprite * sprite ) {
	list<int> cellIds = GetBucketId( sprite );
	
	list<int>::iterator iter = cellIds.begin();
	
	for (int i = 0; i < cellIds.size(); ++iter, ++i) {
		m_buckets.at(*iter).push_back(sprite);
	}

}
	
// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::GetBucketId(CustomSprite * sprite) {
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;

	int yMod = ((int)sprite->GetPosition().y) / DemoConstants::CELLSIZE;
	int xMod = ((int)sprite->GetPosition().x) / DemoConstants::CELLSIZE;
	
	bucketsSpriteIsIn.push_back((yMod*4) + xMod);	//TODO Modify DemoConstants with a value to store the number of rows and collumns

	xMod = (int)(sprite->GetPosition().x + (sprite->radius() * 2)) / DemoConstants::CELLSIZE;
	yMod = (int)(sprite->GetPosition().y + (sprite->radius() * 2)) / DemoConstants::CELLSIZE;

	int oppVertexBucketID = ((yMod*4) + xMod);

	if (oppVertexBucketID - *bucketsSpriteIsIn.begin() == 5){
		//Add sprite to the 3 buckets surrounding the bucket of the first vertex
		bucketsSpriteIsIn.push_back(*bucketsSpriteIsIn.begin() + 1);
		bucketsSpriteIsIn.push_back(oppVertexBucketID - 1);
		bucketsSpriteIsIn.push_back(oppVertexBucketID);
	}
	else if (oppVertexBucketID != *bucketsSpriteIsIn.begin()){
		//Just add it to the bucket that the corner is in
		bucketsSpriteIsIn.push_back(oppVertexBucketID);
	}

	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::AddSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) {
	// TODO: Implement logic here...
	//Not needed
}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<CustomSprite *> MapManager::GetNearbySprites( CustomSprite * sprite ) {
	// The list of nearby sprites to return.
	list<CustomSprite *> nearbySprites;
	
	list<int> cellIds = GetBucketId( sprite );
	list<int>::iterator iter = cellIds.begin();

	map<int, list<CustomSprite *>>::iterator it;

	for (int i = 0; i < cellIds.size(); ++iter, ++i) {
		it = m_buckets.find(*iter);
		nearbySprites.merge(it->second);
	}

	nearbySprites.remove(sprite);
	
	return nearbySprites;
}
