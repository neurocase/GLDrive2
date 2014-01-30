#include "include.h"
#include "level.h"


using namespace std;

struct Dim{
  int height = 0;
  int width = 0;
};

struct Playerstart{
  int x = 0;
  int y = 0;
};
Dim dim;
Playerstart playerstart;

Level::Level(char **newmap, int length){




std::string tempw;
std::string temph;




//dim.width = 0;
//dim.height = 0;
checkpoints = 0;
int colours = 0;
int startat = 0;


int i = 0;
while(dim.width == 0){
  tempw[i] = newmap[0][i];
    if (newmap[0][i] == ' ')  dim.width = atoi(tempw.c_str());
  i++;  
}
int j = 0;
while(dim.height == 0){
    if (newmap[0][i] == ' '){  dim.height = atoi(temph.c_str()); break;}
    temph[j] = newmap[0][i];
    j++;
    i++;  
}
i++;
static char *ccol = &newmap[0][i];
colours = atoi(ccol);

string checkcol;
checkcol = newmap[0][i+1];


  if (checkcol != " "){ cout << endl << "too many colours, there may be errors" << endl;}
 
for (int i =colours+1; i < dim.height+colours+1; i++)
{// cout << newmap[i] << endl;
  for (int j =0; j < dim.width; j++)
  {
    if (newmap[i][j] == '+' ){
    checkpoints++;
    playerstart.x = i;
    playerstart.y = j;
    
    }
  }
}


std::cout <<  **newmap << ": Map Loaded :" << std::endl;
std::cout << "Dim :: Width:" << dim.width << " Height:" << dim.height << " Colours:" << colours << std::endl;
std::cout << "Player Start: X:" << playerstart.x << " Y:" << playerstart.y << std::endl;

}

void Level::getPlayerStart(int& x,int& y){
x = playerstart.x;
y = playerstart.y;

}


void Level::getDimensions(int& x,int& y){
x = dim.width;
y = dim.height;
}

Level::~Level(){
}
