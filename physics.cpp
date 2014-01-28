#include "include.h"
#include "physics.h"

const double PI = 3.141592653589793;
double force = 0;	
double mass = 1;
double engineforce = 1;
double traction = 1;
int dotdot = 0;
double totVel = 0;

double maxspeed = 700;

Physics::Physics()
{
}

void Physics::CalcPhys(double &degrot, int rotdir, double &px, double &py, double &velx, double &vely, bool throttle, bool isbrake, bool ishbrake, double &viewspeeddist, char **newmap, int maplength)
{



	//degdToRad
	double radrot = degrot * (PI/180);
  

if (throttle == true){


	//first gear
	if (engineforce < 70){
	engineforce += 3;	
	}
	//second gear
	engineforce += 5;
	if (engineforce > maxspeed){
		engineforce = maxspeed;
	}
}else{
if (engineforce > 0){
		engineforce -= 2;
		}
}
	

if (isbrake){
	if (engineforce > 0){
		engineforce -= 10;
	}
	if (engineforce <= 0){
		engineforce -= 0.7;
		if (engineforce < -20){
			engineforce = -20;
		}
	}
}
if (engineforce < 0 && !isbrake){
	engineforce = 0;
}

//reduce speed for turning
if (rotdir != 0){
engineforce -= 5;
}
totVel = std::abs(velx) + std::abs(vely);

if (std::abs(totVel) < 0.5){
	totVel = 0;
	//make sure turning is'nt trigered by a very small total velocity of 0.0000004325 or something.
}

if (totVel > 5 || engineforce > 0)
{
	double incT = 0.055;
	
	if (totVel < 10){
		//dodgey hack to make the car turn slower at extreem slow speeds 
		incT = incT * totVel /2;
	}
	
	
	//times turning by total velocity for handbrake effect
	if (ishbrake){
		if (totVel > 8 ){
		incT = 0.055 * totVel / 30;
		} 
	engineforce = -0.5;

	}
switch(rotdir){
	case -1:
		radrot -= incT;
		break;
	case 1:
		radrot += incT;
		break;
	default:
		break;
} 
}
double thickness = 6;
	
double dragX = thickness * -velx / mass;
double dragY = thickness * -vely / mass;

double forceX = engineforce * cos(radrot) + dragX;
double forceY = engineforce * sin(radrot) + dragY; 


if (dotdot == 0){	

} 
dotdot++;
if (dotdot > 30){
	dotdot = 0;
}



double deltaT = 0.01;

double dt2 = deltaT * deltaT / 2;

double accelX = forceX / mass; //accel * cos(radrot);
double accelY = forceY / mass; //accel * sin(radrot);


int cx = (int)px;
int cy = (int)py;

if (newmap[cx][cy] == ' '){
//velx = velx /2;
//vely = vely /2;
if (engineforce > 12){
engineforce = engineforce -2;
}
}

px = px + deltaT * velx + dt2 * accelX;
velx = velx + deltaT * accelX;

py = py + deltaT * vely + dt2 * accelY;
vely = vely + deltaT * accelY;



//if (viewspeeddist > 30){ viewspeeddist = 30;}else{
viewspeeddist = totVel;
degrot = radrot * (180/PI);




}



Physics::~Physics()
{
};


