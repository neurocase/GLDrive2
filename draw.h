#ifndef DRAW_H
#define DRAW_H


class Draw{

  private:
  
  unsigned int car[12];
  unsigned int loadedtex;

	public:
	
	Draw();
	
	unsigned int LoadTexture(const char* filename);
	
	void RaceCar(double, double, double, unsigned int);
	void TrafficCone(double, double, double, unsigned int);
	void RedTri(double, double, double);
	
	
	~Draw();
	
	
};



#endif
