#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "CustomSprite.h"
#include "DemoConstants.h"
//#include "CollisionManager.h"
#include <vector>

using std::vector;

class SpriteManager {
public:
	SpriteManager();

	vector<CustomSprite *> & GetAllSprites();
	void updateSprites();
	
	/*CollisionManager * m_pCollisionManager*/;

private:
	vector<CustomSprite *> m_sprites;
};

#endif