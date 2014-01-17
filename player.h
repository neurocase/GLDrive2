#ifndef PLAYER_H
#define PLAYER_H


class Player{
	
	private:
	
	
	
	public:
	
	Player();
	~Player();
	
	int texid;
	int rotdir;
	
	double xpos;
	double ypos;
	double width;
	double height;
	double rot;
	double accel;
	double velx;
	double vely;
	
	bool throttle;
	bool brake;
	bool hbrake;
	
	
	};



#endif
