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

using namespace std;

int FPS = 30;
double angle=0.0;
const int triangle=1;
Uint32 tickstatus = 0;

int playerstartx = 0;
int playerstarty = 0;
int maptestlength;


bool turnLeft = false;
bool turnRight = false;
double accel = 0;

void lookforplayerstart(char **newmap, int length){

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
cout << "::" << *newmap << ": Map Loaded ::" << endl;
if (checkcol != " "){ cout << endl << "too many colours, there may be errors" << endl;}
cout << " Width: " << mapwidth;
cout << " Height: " << mapheight;
cout << " Colours: " << colours << endl;

for (int i =colours+1; i < mapheight+colours+1; i++)
{// cout << newmap[i] << endl;
  for (int j =0; j < mapwidth; j++)
  {
    if (newmap[i][j] == '+' ){

    PlayerOne.xpos = i;
    PlayerOne.ypos = j;
    
    }
  }
}

}

void reportstatus(){
  int aaa = SDL_GetTicks();
 // std::cout << SDL_GetTicks()-tickstatus << " ";
// std::cout << " - ";
  if(6500.0<SDL_GetTicks()-tickstatus)
    {
      tickstatus =SDL_GetTicks();
       std::cout << "    PLAYERONE: X:" << PlayerOne.xpos << " Y:" << PlayerOne.ypos << " ViewDistance:" << PlayerOne.viewspeeddist << std::endl;
		}
}
void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  gluPerspective(45,640.0/480.0,1.0,500.0);
  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

  RaceTrack.playercar.texid = DrawEn.LoadTexture("yellowcar.bmp");
  PlayerOne.texid = RaceTrack.trafficcone.texid;
  RaceTrack.trafficcone.texid = DrawEn.LoadTexture("trafficcone.bmp");
  
  maptestlength = (sizeof(maptest_xpm)/sizeof(*maptest_xpm));
  lookforplayerstart(maptest_xpm, maptestlength);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
  
    reportstatus();
  
  float camlocx =  PlayerOne.xpos;
  float camlocy =  PlayerOne.ypos;
  float totalvel = std::abs(PlayerOne.velx) + std::abs(PlayerOne.vely);
  glLoadIdentity();
  
  
  
  if (PlayerOne.viewspeeddist >= 28) PlayerOne.viewspeeddist = 28;
  glTranslatef(-camlocx, -camlocy,-20.0-PlayerOne.viewspeeddist);
 
 
  glBindTexture(GL_TEXTURE_2D,NULL);


// CONSIDER CLEANING UP THIS LINE BY PASSING A CLASS THROUGH THE FUNCTION RATHER THAN ALL THESE VARIABLES

  PhysEn.CalcPhys(PlayerOne.rot,PlayerOne.rotdir, PlayerOne.xpos, PlayerOne.ypos, PlayerOne.velx, PlayerOne.vely, PlayerOne.throttle, PlayerOne.brake, PlayerOne.hbrake, PlayerOne.viewspeeddist, maptest_xpm, maptestlength);
 
 
 
 
  DrawEn.RaceCar(PlayerOne.rot,PlayerOne.xpos,PlayerOne.ypos, RaceTrack.playercar.texid);
  
 /* for (int i = 0; i < 50; i++)
  {
    for (int j = 0; j < 50; j++)
    {
      DrawEn.TrafficCone(-90,j*3,i*3, RaceTrack.trafficcone.texid);
    }
  }*/
    DrawEn.XpmMap(maptest_xpm, maptestlength);
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
						PlayerOne.hbrake = true;
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
    //  PlayerOne.rot -= 1.0;
      PlayerOne.rotdir = -1;
    }
    if (turnLeft){
    //  PlayerOne.rot += 1.0;
      PlayerOne.rotdir = 1;
    }
    if (!turnRight && !turnLeft){
          PlayerOne.rotdir = 0;
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
