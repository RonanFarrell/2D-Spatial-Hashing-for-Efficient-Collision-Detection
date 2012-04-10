#include "stdafx.h"
#include "SpriteManager.h"

// Adds DemoConstants::NUM_SPRITES to a container, each sprite has a random screen position
//  and direction vector.
SpriteManager::SpriteManager() {

	for (int i = 0 ; i < DemoConstants::NUM_SPRITES; ++i) {
		CustomSprite* sprite = new CustomSprite();
		sprite->SetScale( sf::Vector2f(0.5f, 0.5f) );
		sprite->SetPosition( rand() % static_cast<int> ( ( DemoConstants::SCREEN_WIDTH - sprite->GetSize().x ) ), 
			                rand() % static_cast<int> ( ( DemoConstants::SCREEN_HEIGHT - sprite->GetSize().y ) ) );	   	
		// Give each sprite a random direction vector.
		float randXDir = ( rand() % 10 ) / 15.0f;
		float randYDir = ( rand() % 10 ) / 15.0f;
		sprite->SetVelocity( sf::Vector2f( randXDir, randYDir ) );
		m_sprites.push_back( sprite );
	}	

	//m_pCollisionManager = CollisionManager::instance();
}

vector<CustomSprite *> & SpriteManager::GetAllSprites() {
	return m_sprites;
}

void SpriteManager::updateSprites() {
	for (int i = 0; i < m_sprites.size(); ++i) {
		m_sprites.at(i)->update();
		m_sprites.at(i)->keepInBounds();
	}

	/*for (int i = 0; i < m_sprites.size(); ++i) {
		for(int j = i + 1; j < m_sprites.size(); ++j) {
			if (m_pCollisionManager->CheckCollision(m_sprites.at(i), m_sprites.at(j)) == true) {
				m_sprites.at(i)->SetVelocity(sf::Vector2f(m_sprites.at(i)->GetVelocity().x * -1, m_sprites.at(i)->GetVelocity().y * -1));
				m_sprites.at(j)->SetVelocity(sf::Vector2f(m_sprites.at(j)->GetVelocity().x * -1, m_sprites.at(j)->GetVelocity().y * -1));
			}
		}
	}*/


	
}
