#include "include.h"
#include "physics.h"
#include "level.h"
#include "degrad.cpp"


//const double PI = 3.141592653589793;
double force = 0;	
double mass = 1;
double traction = 1;
int dotdot = 0;
//double totVel = 0;

double maxspeed = 450;

Physics::Physics()
{
}
//void Physics::CalcPhys(double &degrot, int rotdir, double &px, double &py, double &velx, double &vely, bool throttle, bool isbrake, bool ishbrake, double &viewspeeddist, char **newmap, int maplength)
//  PhysEn.CalcPhys(PlayerOne.rot,PlayerOne.rotdir, PlayerOne.xpos, PlayerOne.ypos, PlayerOne.velx, PlayerOne.vely, PlayerOne.throttle, PlayerOne.brake, PlayerOne.hbrake, PlayerOne.viewspeeddist, maptest_xpm, maptestlength);

void Physics::CalcPhys(Player &Player, Level &MyLevel)
{



	//degdToRad
	double radrot = DegToRad(Player.rot);// * (PI/180);
  
//acceleration and gears 

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
	

	//	turnval = turnval * Player.totvel * 0.2;
	//}
	
	
	//times turning by total velocity for handbrake effect
	if (Player.hbrake){
//		if (Player.totvel > 8 ){
		turnval = 0.07;
		//std::cout << "turnval * " << (Player.totvel * 0.015) << "   " << std::endl;
	//	}
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
double thickness = 6;
	
double dragX = thickness * -Player.velx / mass;
double dragY = thickness * -Player.vely / mass;

double forceX = Player.engineforce * cos(radrot) + dragX;
double forceY = Player.engineforce * sin(radrot) + dragY; 


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


int cx = (int)Player.xpos;
int cy = (int)Player.ypos;

// program is crashing when car goes off map

if (MyLevel.getGridChar(cx,cy) == ' '){
//Player.velx = Player.velx /2;
//Player.vely = Player.vely /2;
if (Player.engineforce > 18){
  Player.engineforce -= 4;
  if (Player.engineforce > 26){
  Player.engineforce = Player.engineforce -12;
  }
}
}
// Check for check points and 
//for (int ccx = -4; ccx < 4; ccx++){    
//  for (int ccy = -4; ccy < 4; ccy++){
//    if (ccx + cx < 32 && ccy +cy < 32){
char val = MyLevel.getGridChar(cx,cy);
if (val == '+'){
  std::cout << "CHECKPOINT!";
}
      //if (newmap[cx][cy] == '+'){
       // std::cout << "CHECKPOINT!";
  //        newmap[cx+ccx][cy+ccy] = 'a';
          
  //    }
  //  }
 // }


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


