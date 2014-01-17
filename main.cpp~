#include "include.h"
#include "player.h"
#include "draw.h"
#include "scene.h"
#include "physics.h"
// -lGL -lGLU -lSDL


Player PlayerOne;
Scene RaceTrack;
Draw DrawEn;
Physics PhysEn;

int FPS = 30;
double angle=0.0;
const int triangle=1;


bool turnLeft = false;
bool turnRight = false;
double accel = 0;
/*
unsigned int loadTexture(const char* filename)
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
  return id;
}*/

//unsigned int yellowcartex;

void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  //glTranslatef(0,0,-20.0);
 
  
  gluPerspective(45,640.0/480.0,1.0,500.0);
  glMatrixMode(GL_MODELVIEW);
 // glShaderModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  
  RaceTrack.playercar.texid = DrawEn.LoadTexture("yellowcar.bmp");
  PlayerOne.texid = RaceTrack.trafficcone.texid;
  RaceTrack.trafficcone.texid = DrawEn.LoadTexture("trafficcone.bmp");
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //glTranslatef(0.0,0.0,-5.0);
   glTranslatef(PlayerOne.xpos,PlayerOne.ypos,-20.0);
   glBindTexture(GL_TEXTURE_2D,NULL);
  //double pos[]={-2.0,2.0,-3.0,1.0};make
  
 // glLightfv(GL_LIGHT0, GL_POSITION,pos);
 
  PhysEn.CalcPhys(PlayerOne.rot, PlayerOne.xpos, PlayerOne.ypos, PlayerOne.velx, PlayerOne.vely, PlayerOne.throttle, PlayerOne.brake, PlayerOne.hbrake);
 
  DrawEn.RaceCar(PlayerOne.rot,PlayerOne.xpos,PlayerOne.ypos, RaceTrack.playercar.texid);
  DrawEn.TrafficCone(45,5,5, RaceTrack.trafficcone.texid);
  
   

   /* int size = 1;
  glBegin(GL_QUADS);
    glColor3f(1,1,2);
    glTexCoord2f(0.0,1.0);
    glVertex3f(-size,size,0.0);
    glTexCoord2f(0.0,0.0);
    glVertex3f(-size,-size,0.0);
    glTexCoord2f(1.0,0.0);
    glVertex3f(size,-size,0.0);
    glTexCoord2f(1.0,1.0);
    glVertex3f(size,size,0.0);
  glEnd();*/
  
  //std::cout << PlayerOne.pos << " ";
}



int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  
  SDL_Surface* screen, *image;
	screen=SDL_SetVideoMode(640, 480,32,SDL_SWSURFACE|SDL_OPENGL);
  bool running = true;
  Uint32 start;
  SDL_Event event;
  init();
  
  // GAME LOOP
  
  while(running)
  {
    start=SDL_GetTicks();
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          running = false;
          break;
    		case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
					  case SDLK_UP:
						PlayerOne.throttle = true;
						break;
						case SDLK_DOWN:
						PlayerOne.brake = true;
						break;
						case SDLK_LEFT:
						turnLeft = true;
						break;
						case SDLK_RIGHT:
						turnRight = true;
						break;
						case SDLK_SPACE:
						PlayerOne.brake = true;
						break;
						case SDLK_ESCAPE:
						running=false;
						break;
					}
				break; 
			  case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
					  case SDLK_UP:
					  PlayerOne.throttle = false;
						break;
						case SDLK_DOWN:
						PlayerOne.brake = false;
						break;
						case SDLK_LEFT:
						turnLeft = false;
						break;
						case SDLK_RIGHT:
						turnRight = false;
						break;
						case SDLK_SPACE:
						PlayerOne.hbrake = false;
						break;
						case SDLK_ESCAPE:
						running=false;
						break;
					}
      }
    }
    if (turnRight){
      PlayerOne.rot -= 1.0;
    }
    if (turnLeft){
      PlayerOne.rot += 1.0;
    }
    
    display();
    SDL_GL_SwapBuffers();
    //angle += 0.5;
    if(PlayerOne.rot>360)
    {
      PlayerOne.rot-=360;
    }
    if(100/30>SDL_GetTicks()-start)
    {
      SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
		}
	}

  SDL_FreeSurface(image);
	SDL_Quit();
	return 0;
}
