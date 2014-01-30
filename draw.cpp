
#include "include.h"
#include "draw.h"

using namespace std;

Draw::Draw()
{
  loadedtex=0;

}

bool texLoaded = 0;
//const double PI = 3.141592653589793;



void Draw::RenderText(const TTF_Font *Font, const GLubyte& R, const GLubyte& G, const GLubyte& B,
                const double& X, const double& Y, const double& Z,  const std::string& Text)
{
	/*Create some variables.*/
	SDL_Color Color = {R, G, B};
	SDL_Surface *Message = TTF_RenderText_Blended(const_cast<TTF_Font*>(Font), Text.c_str(), Color);
	unsigned Texture = 0;
 
	/*Generate an OpenGL 2D texture from the SDL_Surface*.*/
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Message->w, Message->h, 0, GL_BGRA,
	             GL_UNSIGNED_BYTE, Message->pixels);
 
	/*Draw this texture on a quad with the given xyz coordinates.*/
	glBegin(GL_QUADS);
		glTexCoord2d(0, 1); glVertex3d(X, Y, Z);
		glTexCoord2d(1, 1); glVertex3d(X+(Message->w/3), Y, Z);
		glTexCoord2d(1, 0); glVertex3d(X+(Message->w/3), Y+(Message->h/3), Z);
		glTexCoord2d(0, 0); glVertex3d(X, Y+(Message->h/3), Z);
	glEnd();
 
	/*Clean up.*/
	glDeleteTextures(1, &Texture);
	SDL_FreeSurface(Message);
}





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


void Draw::GrnSqr(double rot, double x, double y)
{
    double size = 0.5;
    double sizex = size;    
  
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
	
	  glBindTexture(GL_TEXTURE_2D,NULL);
	  glColor3f(0,1,0.3);
	
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

/*
".	c #FFFFFF",
"+	c #000000",
"@	c #00FFFF",
"#	c #0000FF",
*/


void Draw::XpmMap(char **newmap, int length)
{

string tempw;
string temph;
int mapwidth = 0;
int mapheight = 0;
int colours = 0;
int startat = 0;

int i = 0;
while(mapwidth == 0){
  tempw[i] = newmap[0][i];
    if (newmap[0][i] == ' ')  mapwidth = atoi(tempw.c_str());
  i++;  
}
int j = 0;
while(mapheight == 0){
    if (newmap[0][i] == ' '){  mapheight = atoi(temph.c_str()); break;}
    temph[j] = newmap[0][i];
    j++;
    i++;  
}
i++;
static char *ccol = &newmap[0][i];
colours = atoi(ccol);

string checkcol;
checkcol = newmap[0][i+1];

//if (checkcol != " "){ cout << endl << "too many colours, there may be errors" << endl;}

for (int i =colours+1; i < mapheight+colours+1; i++)
{// cout << newmap[i] << endl;
  for (int j =0; j < mapwidth; j++)
  {
    if (newmap[i][j] != ' ' ){
    this->GrnSqr(0, i, j);
    
    }
  }
}
}



	
Draw::~Draw()
{
}
