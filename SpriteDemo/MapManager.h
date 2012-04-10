#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "CustomSprite.h"

#include <map>
#include <list>
#include <algorithm> // for STL find()
#include <iostream>


using std::list;
using std::map;
using std::cout;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();

	void ClearBucketLists();

	void RegisterSprite( CustomSprite * sprite );


	list<CustomSprite *> GetNearbySprites( CustomSprite * sprite );

private:

	map< int, list< CustomSprite *> > m_buckets;

	list<int> GetBucketId( CustomSprite * sprite );	

	void AddSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif