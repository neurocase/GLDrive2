#include "include.h"
#include "physics.h"

const double PI = 3.141592653589793;
double force = 0;	
double mass = 1;
double engineforce = 1;
double traction = 1;
int dotdot = 0;
double totVel = 0;

Physics::Physics()
{
}

void Physics::CalcPhys(double rot, double &px, double &py, double &velx, double &vely, bool throttle, bool isbrake, bool ishbrake)
{



	//degdToRad
	rot = rot * (PI/180);
	
///	rot = rot * (180/PI);

if (throttle == true){/*
  engineforce =1;
}else{
  engineforce =0;
}
py = engineforce * cos(rot) + 1;
px = engineforce * sin(rot) + 1; 
px = -px;
}*/



	//first gear
	if (engineforce < 20){
	engineforce += 1;	
	}
	//second gear
	engineforce += 0.8;
	if (engineforce > 90){
		engineforce = 90;
	}
	}else if (throttle == true){
		engineforce -= 3;
		
		
}

if (isbrake){
	if (engineforce > 0){
		engineforce -= 3;
	}
	if (engineforce <= 0){
		engineforce -= 0.3;
		if (engineforce < -10){
			engineforce = -10;
		}
	}
}
if (engineforce < 0 && !isbrake){
	engineforce = 0;
}

totVel = std::abs(velx) + std::abs(vely);

if (std::abs(totVel) < 0.5){
	totVel = 0;
	//make sure turning is'nt trigered by a very small total velocity of 0.0000004325 or something.
}

if (totVel > 0 || engineforce > 0)
{
	double incT = 0.055;
	
	if (totVel < 2){
		//dodgey hack to make the car turn slower at extreem slow speeds 
		incT = incT * totVel /2;
	}
	
	
	//times turning by total velocity for handbrake effect
	if (ishbrake){
		if (totVel > 8 ){
		incT = 0.055 * totVel / 8;
		} 
	engineforce = -3;

	}/*
switch(r){
	case -1:
		rot -= incT;
		break;
	case 1:
		rot += incT;
		break;
	default:
		break;
} */
}
double thickness = 6;
	
double dragX = thickness * -velx / mass;
double dragY = thickness * -vely / mass;

double forceX = engineforce * cos(rot) + dragX;
double forceY = engineforce * sin(rot) + dragY; 


if (dotdot == 0){	

} 
dotdot++;
if (dotdot > 30){
	dotdot = 0;
}



double deltaT = 0.01;

double dt2 = deltaT * deltaT / 2;

double accelX = forceX / mass; //accel * cos(rot);
double accelY = forceY / mass; //accel * sin(rot);


px = px + deltaT * velx + dt2 * accelX;
velx = velx + deltaT * accelX;

py = py + deltaT * vely + dt2 * accelY;
vely = vely + deltaT * accelY;


}


Physics::~Physics()
{
};



//void Rotcalc::calcPhys(double &rot, int r, double &px, double &py, double &velx, double &vely, int throttle,int isbrake, bool ishbrake){
//}



/*
double forceX = engineforce * cos(rot) + dragX;
double forceY = engineforce * sin(rot) + dragY; 

*/
