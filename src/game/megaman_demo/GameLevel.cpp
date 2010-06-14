/*
 * GameLevel.cpp
 *
 *  Created on: 2010-06-02
 *      Author: Emile
 */

#include <iostream>
#include "GameLevel.h" // own header file
#include "Tile.h"
#include "Bitmap.h"
#include "VisibleArea.h"
#include "Background.h"
#include "Physics.h"
#include "Sprite.h"
#include "Metool.h"
#include "Megaman.h"
#include "LifeGauge.h"
#include "IncludeStates.h" // the include below includes all the States of megaman
using namespace std;

GameLevel::GameLevel() :
	Environment(960, 272, 56, 32) {
}

GameLevel::~GameLevel() {
}

void GameLevel::build() {
	// TODO change the code of that function to load level from a file
	std::cout << "Entering GameLevel build function" << endl;

	// FIXME that does nothing and i don't know why it was there
//	Bitmap** black_square = new Bitmap*[2];
//	black_square[0] = new Bitmap("src/display/black.bmp");
//	black_square[1] = new Bitmap("src/display/gray.bmp");

	Bitmap** snow = new Bitmap*[1];
	snow[0] = new Bitmap("src/display/snow1.bmp");

	Tile* tile1 = new Tile(56, 32, snow, 1, this);

	Bitmap** brick = new Bitmap*[1];
	brick[0] = new Bitmap("src/display/brick.bmp");

	Tile* tile2 = new Tile(56, 32, brick, 1, this);

	// Send the tiles to the environment (Base class)
	//for(uint8_t i=0; i<18; i++) {
	for (uint8_t i = 0; i < 15; i++) {
		add(tile1, i, 7);
	}

	//for(uint8_t i=0; i<18; i++) {
	for (uint8_t i = 0; i < 15; i++) {
		add(tile2, i, 8);
	}

	// A little hill
	add(tile1, 13, 6);

	// Create a new visible area for the entire screen
	VisibleArea* visibleArea = new VisibleArea();
	visibleArea->x = 0;
	visibleArea->y = 0;
	visibleArea->width = 480;
	visibleArea->height = 272;

	// Send it to the environment (Base class)
	set(visibleArea);

	Bitmap* background_bitmap = new Bitmap("src/display/back4.bmp");
	Background* background = new Background(background_bitmap, 768, 272, this);

	set(background);

	// Start with a power of 2 gravitation acceleration since it's easy to play with
	// ad 8 is close to earth acceleration anyway (which is ~9.81)
	Physics* physics = new Physics(1);
	set(physics);

	// Hero section
	std::cout << "Loading hero" << endl;

	// Preload every states.
	// TODO Maybe something better could be used here.
	MegamanStandingLeft::getInstance();
	MegamanStandingRight::getInstance();
	MegamanRunningLeft::getInstance();
	MegamanRunningRight::getInstance();
	MegamanJumpingLeft::getInstance();
	MegamanJumpingRight::getInstance();
	MegamanSlidingLeft::getInstance();
	MegamanSlidingRight::getInstance();
	MegamanRunningLeftShot::getInstance();
	MegamanRunningRightShot::getInstance();
	MegamanHitRight::getInstance();

	Megaman* hero = new Megaman(MegamanStandingRight::getInstance(), this);
	hero->enableCollisionCheck();
	hero->setPosition(720, 50);
	//set(hero, 240, 189);
	//set(hero, 240, 50);
	set(hero);
	cout << "Done Loading hero" << endl;

	cout << "Loading sprites" << endl;
	Metool** enemy = new Metool*[32];
	for (uint8_t i = 0; i < 32; i++) {
		if (i < 22) {
			enemy[i] = new Metool(MetoolWalkingRight::getInstance(), this);
			//add(enemy, 500, 204);
		} else {
			enemy[i] = new Metool(MetoolWalkingLeft::getInstance(), this);
		}
		startSpawning(enemy[i], (i * 25), 100);
	}

	// Try a sprite activated directly without being spawned by the environment
	Metool* lonely_metool = new Metool(MetoolWalkingRight::getInstance(), this);
	lonely_metool->setPosition(600, 50);
	activate(lonely_metool);

	// Load interface
	LifeGauge* lifeGauge = new LifeGauge(LifeGaugeNormal::getInstance(), this);
	lifeGauge->setPosition(600, 50);
	lifeGauge->linkTo(hero);
	lifeGauge->setOffset(15, 5);
	activate(lifeGauge);

}
