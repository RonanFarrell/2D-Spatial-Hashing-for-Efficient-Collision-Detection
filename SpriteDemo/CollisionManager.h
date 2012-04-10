#pragma once
#include "CustomSprite.h"
#include <SFML/Graphics.hpp>


static class CollisionManager {
public:
	static CollisionManager* instance();
	bool CheckCollision(CustomSprite const * const, CustomSprite const * const);

private:
	CollisionManager();
	CollisionManager(const CollisionManager&);
	CollisionManager& operator=(const CollisionManager&);
	
	static CollisionManager* mInstance;
};