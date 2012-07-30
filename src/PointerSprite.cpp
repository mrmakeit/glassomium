/*
   Glassomium - web-based TUIO-enabled window manager
   http://www.glassomium.org

   Copyright 2012 Piero Toffanin

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
   
#include "PointerSprite.h"

/** Initializes a circle looking pointer */
PointerSprite::PointerSprite(float radius, Color color)
 : sf::Sprite(){

	sf::Texture *spriteTex = new sf::Texture();
	if (color == PointerSprite::Red){
		spriteTex->loadFromFile("textures/pointer_red.png");
	}else if (color == PointerSprite::Green){
		spriteTex->loadFromFile("textures/pointer_green.png");
	}else if (color == PointerSprite::Blue){
		spriteTex->loadFromFile("textures/pointer_blue.png");
	}
	
	this->setTexture(*spriteTex, true);

	// Set center anchor point
	this->setOrigin((float)spriteTex->getSize().x / 2.0f, (float)spriteTex->getSize().y / 2.0f);

	// Resize
	float textureWidth = this->getLocalBounds().width;
	float scaleFactor = radius / textureWidth;
	this->setScale(scaleFactor, scaleFactor);
}

PointerSprite::~PointerSprite(){

}
