#ifndef PLAYER_H
#define PLAYER_H


class Player{
	
	private:
	
	
	
	public:
	
	Player();
	~Player();
	
	int texid;
	int rotdir;
	
	
	double engineforce;
	double xpos;
	double ypos;
	double width;
	double height;
	double rot;
	double accel;
	double velx;
	double vely;
	double totvel;
	double viewspeeddist;
	
	bool throttle;
	bool brake;
	bool hbrake;
	
	
	};



#endif
