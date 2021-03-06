#include "include.h"
#include "physics.h"
#include "level.h"
#include "degrad.cpp"

double force = 0;	
double mass = 1;
double traction = 1;
int dotdot = 0;

double maxspeed = 450;

Physics::Physics()
{
}

void Physics::CalcPhys(Player &Player, Level &MyLevel)
{
	double radrot = DegToRad(Player.rot);// * (PI/180);

if (Player.throttle == true){

	//first gear
	if (Player.engineforce < 70){
	Player.engineforce += 3;	
	}
	//second gear
	Player.engineforce += 5;
	if (Player.engineforce > maxspeed){
		Player.engineforce = maxspeed;
	}
}else{
if (Player.engineforce > 0){
		Player.engineforce -= 2;
		}
}
	
if (Player.brake  || Player.hbrake){
	if (Player.engineforce > 0){
		Player.engineforce -= 10;
	}
	if (Player.engineforce <= 0){
		Player.engineforce -= 0.7;
		if (Player.engineforce < -40){
			Player.engineforce = -20;
		}
	}
}
if (Player.engineforce < 0 && !Player.brake){
	Player.engineforce = 0;
}
//reduce speed for turning
if (Player.rotdir != 0){
Player.engineforce -= 2;
}
Player.totvel = std::abs(Player.velx) + std::abs(Player.vely);

if (std::abs(Player.totvel) < 0.5){
	Player.totvel = 0;
	//make sure turning is'nt trigered by a very small total velocity of 0.0000004325 or something.
}

if (Player.totvel > 0 && Player.engineforce > 0)
{
	double turnval = 0.04;
	//times turning by total velocity for handbrake effect
	if (Player.hbrake){
//		if (Player.totvel > 8 ){
		turnval = 0.07;
	}
  switch(Player.rotdir){
    case -1:
	    radrot -= turnval;
	    break;
    case 1:
	    radrot += turnval;
	    break;
    default:
	    break;	
	} 
}
// THICKNESS refers to the thickness of air, creating drag on the car.
double thickness = 6;
double dragX = thickness * -Player.velx / mass;
double dragY = thickness * -Player.vely / mass;

double forceX = Player.engineforce * cos(radrot) + dragX;
double forceY = Player.engineforce * sin(radrot) + dragY; 

double deltaT = 0.01;

double dt2 = deltaT * deltaT / 2;

double accelX = forceX / mass; //accel * cos(radrot);
double accelY = forceY / mass; //accel * sin(radrot);

int cx = (int)Player.xpos;
int cy = (int)Player.ypos;

if (MyLevel.getGridChar(cx,cy) == ' '){
	if (Player.engineforce > 18){
		Player.engineforce -= 4;
		if (Player.engineforce > 26){
		Player.engineforce = Player.engineforce -12;
		}
	}
}


Player.xpos = Player.xpos + deltaT * Player.velx + dt2 * accelX;
Player.velx = Player.velx + deltaT * accelX;

Player.ypos = Player.ypos + deltaT * Player.vely + dt2 * accelY;
Player.vely = Player.vely + deltaT * accelY;

//if (Player.viewspeeddist > 30){ Player.viewspeeddist = 30;}else{
Player.viewspeeddist = Player.totvel;
Player.rot = RadToDeg(radrot);
}

Physics::~Physics()
{
};


