#include "include.h"
#include "player.h"



Player::Player(){

  rotdir = 0;

	xpos = 0;
	ypos = 0;
	width = 0;
	height = 0;
	rot = 0;
	accel = 0;
  velx = 0;
	vely = 0;
	viewspeeddist=0;
	
	throttle = false;
  brake = false;
	hbrake = false;

}

Player::~Player(){
}

