#include "stdafx.h"
#include "CustomSprite.h"

sf::Image CustomSprite::m_image; 

bool CustomSprite::Init(std::string const & imageFile) {
	return m_image.LoadFromFile(imageFile);
}

CustomSprite::CustomSprite(sf::Vector2f const & position, sf::Vector2f const & scale, sf::Vector2f const & velocity) : 
	sf::Sprite(m_image, position, scale) {
		m_radius = (GetSize().x / 4) - 1.5;
	}

void CustomSprite::SetVelocity( sf::Vector2f const & velocity ) {
	m_velocity = velocity;
}

sf::Vector2f const & CustomSprite::GetVelocity() const {
	return m_velocity;
}

void CustomSprite::update() {
	Move(m_velocity);
}

void CustomSprite::keepInBounds() {
	sf::Vector2f size = GetSize();
	sf::Vector2f pos = GetPosition();

	if (pos.x < 0 ||
		pos.x > DemoConstants::SCREEN_WIDTH - size.x) {
			m_velocity.x *= -1;
	}

	if (pos.y < 0 ||
		pos.y > DemoConstants::SCREEN_HEIGHT - size.y) {
			m_velocity.y *= -1;
	}
}

float const & CustomSprite::radius() const {
	return m_radius;
}

void CustomSprite::reverse(){
	m_velocity.x *= -1;
	m_velocity.y *= -1;
}

