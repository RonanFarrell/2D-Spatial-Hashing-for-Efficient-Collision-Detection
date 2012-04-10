#ifndef CUSTOMSPRITE_H
#define CUSTOMSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "DemoConstants.h"

class CustomSprite : public sf::Sprite {
public :

    static bool Init(std::string const & imageFile);

	CustomSprite(sf::Vector2f const & position = sf::Vector2f(), sf::Vector2f const & scale = sf::Vector2f(1.0f, 1.0f), 
		sf::Vector2f const & velocity = sf::Vector2f(1.0f, 1.0f) );

	void SetVelocity( sf::Vector2f const & velocity );

	sf::Vector2f const & GetVelocity() const ;

	void update();

	void keepInBounds();

	float const & radius() const;

	void reverse();

private :

    static sf::Image m_image; // Shared by every instance.
	sf::Vector2f m_velocity;	  // Direction vector.
	float m_radius;
  
};

#endif