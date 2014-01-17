
#include "include.h"
#include "draw.h"

Draw::Draw()
{
  loadedtex=0;

}

bool texLoaded = 0;
const double PI = 3.141592653589793;

unsigned int Draw::LoadTexture(const char* filename)
{
  SDL_Surface* img=SDL_LoadBMP(filename);
  
  if(img==NULL){
  std::cout << "errorloadingfilename"<< std::endl;
  }else{
    if (texLoaded == 0){
        std::cout << filename << " loaded" << std::endl;
      }
  }
  
  
  unsigned int id;
  glGenTextures(1,&id);
  glBindTexture(GL_TEXTURE_2D,id);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  SDL_FreeSurface(img);
  //loadedtex++;
  return id;
  
}

void Draw::RaceCar(double rot, double x, double y, unsigned int id)
{

  

  
  rot = rot * (PI/180);

  
  double vertxpos[4] = {-1.0, -1.0, 1.0,1.0};
	double vertypos[4] = {-0.6, 0.6, 0.6,-0.6};
	double tmpvertxpos[4] = {vertxpos[0],vertxpos[1],vertxpos[2],vertxpos[3]};
	double tmpvertypos[4] = {vertypos[0],vertypos[1],vertypos[2],vertypos[3]};
		
	for (int i = 0; i < 4; i++){
		vertxpos[i] = tmpvertxpos[i]*cos(rot)-tmpvertypos[i]*sin(rot);
		vertypos[i] = tmpvertxpos[i]*sin(rot)+tmpvertypos[i]*cos(rot);
		
	}
	
	glColor3f(1,1,1);
	
	  glBindTexture(GL_TEXTURE_2D,id);
	
	glBegin(GL_QUADS);  
	    glTexCoord2f(1.0,0.0);
        glVertex3f(x+vertxpos[0], y+vertypos[0], -10.0); //point A
         glTexCoord2f(0.0,0.0);
        glVertex3f(x+vertxpos[1], y+vertypos[1], -10.0); //point B
            glTexCoord2f(0.0,1.0);
        glVertex3f(x+vertxpos[2], y+vertypos[2], -10.0); //point C
            glTexCoord2f(1.0,1.0);
        glVertex3f(x+vertxpos[3], y+vertypos[3], -10.0); //point C
  glEnd();
  
}

void Draw::TrafficCone(double rot, double x, double y, unsigned int id)
{
    double size = 0.5;
    double sizex = size;    
  
  //double thisXt[2] = {-sizex, sizex};
  //double thisYt[4] = {0.1, 0.1, -0.1};
	//double tmpthisXt[4] = {vertxpos[0],vertxpos[1],vertxpos[2]};
	//double tmpthisYt[4] = {vertypos[0],vertypos[1],vertypos[2]};
		
	/*for (int i = 0; i < 3; i++){
		vertxpos[i] = tmpthisXt[i]*cos(rot)-tmpvertypos[i]*sin(rot);
		vertypos[i] = tmpthisXt[i]*sin(rot)+tmpvertypos[i]*cos(rot);
		
	}*/


  rot = rot * (PI/180);

  
  double vertxpos[4] = {-size, -size, size,size};
	double vertypos[4] = {-size, size, size,-size};
	double tmpvertxpos[4] = {vertxpos[0],vertxpos[1],vertxpos[2],vertxpos[3]};
	double tmpvertypos[4] = {vertypos[0],vertypos[1],vertypos[2],vertypos[3]};
		
	for (int i = 0; i < 4; i++){
		vertxpos[i] = tmpvertxpos[i]*cos(rot)-tmpvertypos[i]*sin(rot);
		vertypos[i] = tmpvertxpos[i]*sin(rot)+tmpvertypos[i]*cos(rot);
		
	}
	
	glColor3f(1,1,1);
	
	  glBindTexture(GL_TEXTURE_2D,id);
	
	glBegin(GL_QUADS);  
	    glTexCoord2f(1.0,0.0);
        glVertex3f(x+vertxpos[0], y+vertypos[0], -10.0); //point A
         glTexCoord2f(0.0,0.0);
        glVertex3f(x+vertxpos[1], y+vertypos[1], -10.0); //point B
            glTexCoord2f(0.0,1.0);
        glVertex3f(x+vertxpos[2], y+vertypos[2], -10.0); //point C
            glTexCoord2f(1.0,1.0);
        glVertex3f(x+vertxpos[3], y+vertypos[3], -10.0); //point C
  glEnd();


}

void Draw::RedTri(double, double, double)
{
}
	
Draw::~Draw()
{
}
