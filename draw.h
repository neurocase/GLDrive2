#ifndef DRAW_H
#define DRAW_H


class Draw{

  private:
  
  unsigned int car[12];
  unsigned int loadedtex;

	public:
	
	Draw();
	void RenderText(const TTF_Font *Font, const GLubyte& R,const GLubyte& G, const GLubyte& B,
const double& X, const double& Y, const double& Z,  const std::string& Text);



	unsigned int LoadTexture(const char* filename);
	
	void RaceCar(double, double, double, unsigned int);
	void TrafficCone(double, double, double, unsigned int);
	void RedTri(double, double, double);
	void XpmMap(char **newmap, int length);
	void GrnSqr(double rot, double x, double y);
	
	~Draw();
	
	
};



#endif
