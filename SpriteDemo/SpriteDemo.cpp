#include "stdafx.h"
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>

#include "CollisionManager.h"
#include "MapManager.h"
#include "SpriteManager.h"
#include <iostream>
using namespace std;

// Sample program to demonstrate basic usage of SFML library. Can also be used as a starting
//  point for the spatial hashing assignment.

int main() {
	
    sf::RenderWindow App(sf::VideoMode(DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT, 32), "SFML Graphics");

	sf::Shape lines[6];
	for(int i = 1; i < 4; ++i) {
		lines[i-1] = sf::Shape::Line(0,DemoConstants::CELLSIZE*i, DemoConstants::SCREEN_WIDTH, DemoConstants::CELLSIZE*i, 1, sf::Color::White);
		lines[i+2] = sf::Shape::Line(DemoConstants::CELLSIZE*i,0, DemoConstants::CELLSIZE*i, DemoConstants::SCREEN_HEIGHT, 1, sf::Color::White);
	}
	

	// How to load an image
	sf::Image image;
    

	// How to create a sprite from that image.
	CustomSprite::Init("chromatic_circle.png");

	// Make an instance of our sprite manager.
	SpriteManager spriteManager;

	//Create an instance of the map manager
	MapManager mapManager;
	//Create an instance of the collision manager
	CollisionManager * m_pCollisionManager = CollisionManager::instance();
	CustomSprite * theChosenOne;
	vector<CustomSprite *> & allSprites = spriteManager.GetAllSprites();
	list<CustomSprite *> nearbySprites;

	theChosenOne = allSprites.at(8);
	App.SetFramerateLimit(120);
	
    // Start game loop
    while (App.IsOpened())
    {
		
        // Process events
        sf::Event Event;
	
        while (App.PollEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

		
        // Clear the screen (fill it with black color)
        App.Clear();
		
		
		// How to draw a line.
		for(int i = 0; i < 6; ++i) {
			App.Draw(lines[i]);
		}

		//Mouse Input
		if (sf::Mouse::IsButtonPressed(sf::Mouse::Left)) {
			//Check Collision mouse
			for (int i = 0; i < allSprites.size(); ++i) {
				if (sf::Mouse::GetPosition(App).x % ((int)allSprites.at(i)->GetPosition().x+1) < (allSprites.at(i)->radius() * 2)
					&& sf::Mouse::GetPosition(App).y % ((int)allSprites.at(i)->GetPosition().y+1) < (allSprites.at(i)->radius() * 2)) {
						theChosenOne = allSprites.at(i);
				}
			}
		}



		//Add all the sprites to their buckets
		for (int i = 0; i < allSprites.size(); ++i){
			mapManager.RegisterSprite(allSprites.at(i));
		}
		theChosenOne->SetColor(sf::Color(255, 255, 255));
		
		//Get the list of sprites nearby
		nearbySprites = mapManager.GetNearbySprites(theChosenOne);
		list<CustomSprite *>::iterator iter = nearbySprites.begin();
		//Collision check with nearby sprites
		for (int i = 0; i < nearbySprites.size(); ++i, ++iter) {
			if (m_pCollisionManager->CheckCollision(theChosenOne, *iter) == true) {
				iter.operator*()->reverse();
				theChosenOne->reverse();
			}
			iter.operator*()->SetColor(sf::Color(150, 150, 150));
		}


		//Update the sprites, includes keeping them within 
		//the boundaries of the window
		spriteManager.updateSprites();
	
		// How to draw a container of sprites.
		for ( int i = 0; i < allSprites.size(); ++i ) {							
			App.Draw( * allSprites.at(i) );
			allSprites.at(i)->SetColor(sf::Color(50, 50, 50));
		}
		
		mapManager.ClearBucketLists();

        // Display window contents on screen
        App.Display();
    }
	

    return EXIT_SUCCESS;
}
