/*
 * Engine.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "Engine.h"
#include "Environment.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "Level1.h"
#include <iostream>
//#include "LPC2478.h"
//#include "LCDControllerDriver.h"
#include "Sprite.h"
#include "Megaman.h"
using namespace std;

Engine::Engine() {


}

Engine::~Engine() {

}

void Engine::start() {
	cout << "Entering Engine start function" << endl;

	if(SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		cout << "Error while loading the SDL" << endl;
	}

	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
	{
		cout << "Error while loading the Mixer" << endl;
	}

	Mix_Music *music = 0;
	music = Mix_LoadMUS( "src/game/megaman_demo/sound/frostman.mid" );
	Mix_PlayMusic( music, -1 );

	// Create the instance of a level
	Environment* environment = new Level1();
	environment->build();
	cout << " Environment a builder" << endl;
	SDL_Surface** videoPage = new SDL_Surface*[2];

	videoPage[0] = SDL_SetVideoMode( 480, 272, 32, SDL_SWSURFACE );
	videoPage[1] = SDL_SetVideoMode( 480, 272, 32, SDL_SWSURFACE );

	uint8_t currentPage = 0;

	// Infinite game loop
	cout << "Starting the update and render loop" << endl;
	uint32_t counter = 200;
	while(1) {
		// Switch to the other video page
		currentPage ^= 1;

		if(counter > 0) {
			counter--;
		}

		//Routine 1
		/*
		if(counter == 195) {
			((Megaman*)environment->getHero())->runLeft();
		}
		else if(counter == 135) {
			((Megaman*)environment->getHero())->jump();
			//environment->getHero()->runRight();
		}
		else if(counter == 100) {
			((Megaman*)environment->getHero())->runRight();
		}
		else if(counter == 15) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 0) {
			((Megaman*)environment->getHero())->stopRunning();
			counter = 200;
		}
		*/

		//Routine 2
		if(counter == 195) {
			((Megaman*)environment->getHero())->runLeft();
		}
		else if(counter == 170) {
			((Megaman*)environment->getHero())->runRight();
		}
		else if(counter == 167) {
			((Megaman*)environment->getHero())->runLeft();
		}
		else if(counter == 165) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 155) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 145) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 141) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 137) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 130) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 128) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 110) {
			((Megaman*)environment->getHero())->slide();
			//environment->getHero()->runRight();
		}
		else if(counter == 105) {
			((Megaman*)environment->getHero())->slide();
			//environment->getHero()->runRight();
		}
		else if(counter == 81) {
			((Megaman*)environment->getHero())->runLeft();
		}
		else if(counter == 80) {
			((Megaman*)environment->getHero())->shot();
		}
		else if(counter == 79) {
			((Megaman*)environment->getHero())->stopRunning();
		}
		else if(counter == 78) {
			((Megaman*)environment->getHero())->runRight();
		}
		else if(counter == 77) {
			((Megaman*)environment->getHero())->stopRunning();
		}
		else if(counter == 75) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 55) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 42) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 30) {
			((Megaman*)environment->getHero())->slide();
		}
		else if(counter == 25) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 15) {
			((Megaman*)environment->getHero())->stopRunning();
			counter = 200;
			cout << "Restarting counter" << endl;
		}

		environment->update();
		environment->render(videoPage[currentPage]);
		SDL_Flip( videoPage[currentPage] );

		SDL_Delay(60);
	}

	/*videoPage[0] = new VideoMemory((uint32_t*)0xA0000000,480,272);
	videoPage[1] = new VideoMemory((uint32_t*)0xA007F800,480,272);
	videoPage[1] = new VideoMemory((uint32_t*)0xA0080000,480,272);*/

	//uint8_t currentPage = 0;

	/*LPC2478::getLCD()->setBaseAddress((uint32_t)(videoPage[0]->getPointer()));
	LPC2478::getLCD()->setBackground(0x00DEC3BD);
	LPC2478::getLCD()->setBaseAddress((uint32_t)(videoPage[1]->getPointer()));
	LPC2478::getLCD()->setBackgrougnd(0x00DEC3BD);*/

	// Start tick timer
	/*
	// Infinite game loop
	cout << "Starting the update and render loop";
	uint32_t counter = 200;
	while(1) {
		// Switch to the other video page
		currentPage ^= 1;

		if(counter > 0) {
			counter--;
		}

		if(counter == 195) {
			((Megaman*)environment->getHero())->runLeft();
		}
		else if(counter == 135) {
			((Megaman*)environment->getHero())->jump();
			//environment->getHero()->runRight();
		}
		else if(counter == 100) {
			((Megaman*)environment->getHero())->runRight();
		}
		else if(counter == 15) {
			((Megaman*)environment->getHero())->jump();
		}
		else if(counter == 0) {
			((Megaman*)environment->getHero())->stopRunning();
			counter = 200;
		}



		//environment->update();
		//environment->render(videoPage[currentPage]);


		// Display the newly rendered page
		LPC2478::getLCD()->setBaseAddress((uint32_t)(videoPage[currentPage]->getPointer()));

		// 1/25s synchronization
		//LPC2478::delay(500000);



	}*/

}
