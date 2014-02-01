#include "include.h"
#include "level.h"
#include <vector>

using namespace std;

struct Dim{
  int height = 0;
  int width = 0;
};

struct Playerstart{
  int x = 0;
  int y = 0;
};


struct Checkpoint{
int x = 0;
int y = 0;
int id;
bool flag = false;
};

vector <Checkpoint> checkpointvec;
vector <Checkpoint> checkpointout;

Dim dim;
Playerstart playerstart;


char **thismap;
Level::Level(char **newmap, int length, double& playsx, double& playsy){


arraylength = length;

std::string tempw;
std::string temph;

//dim.width = 0;
//dim.height = 0;
checkpoints = 0;
int colours = 0;
int startat = 0;
int flaggedpoints = 0;


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
  //  std::cout << "FUCKING CUNT" << std::endl;
    checkpointvec.push_back(Checkpoint());
    checkpointvec[checkpoints].x = i;
    checkpointvec[checkpoints].y = j;
    checkpointvec[checkpoints].flag = false;
    checkpointvec[checkpoints].id = checkpoints;
   // std::cout << "," << checkpointvec.size();
    checkpoints++;
    playerstart.x = i;
    playerstart.y = j;

    }
  }
}


std::cout <<  **newmap << ": Map Loaded :" << std::endl;
std::cout << "Dim :: Width:" << dim.width << " Height:" << dim.height << " Colours:" << colours << std::endl;
std::cout << "Player Start: X:" << playerstart.x << " Y:" << playerstart.y << std::endl;
std::cout << "Checkpoints :" << checkpoints << std::endl;
playsx = playerstart.x;
playsy = playerstart.y;

//lwidth = dim.width;
//lheight = dim.height;


thismap = newmap;
}


bool Level::lapCheck(){
	int size = checkpointvec.size();
	if (flaggedpoints >= (size/2)){
		std::cout << "newlap!" << std::endl;
		return true;
		}else{
	return false;
	}
}

void Level::resetFlags(){
std::cout << "reseting flags" << std::endl;
  for(int i = 0; i < checkpointvec.size(); i++){
				checkpointvec[i].flag = false;
				std::cout << "checkpoint " << i << ":" << checkpointvec[i].flag;
				flaggedpoints = 0;
			}
	std::cout << "flaggedpoints =" << flaggedpoints << std::endl;
}

int Level::getCheckpointId(int x, int y){
//std::cout << "checkpointvec.size()" << checkpointvec.size() << std::endl;
//    std::cout << "," << checkpointout.size();
		if (x == playerstart.x && y == playerstart.y){
				if (lapCheck()){			
			std::cout << "@start:"<< playerstart.x << "," << playerstart.y << " lapcheck:" << lapCheck() << std::endl; 
			std::cout << ":::::RETURNING 99:::::" << std::endl;
			return 99;
			}
		}
		
  for(int i = 0; i < checkpointvec.size(); i++){
    if (checkpointvec[i].x == x && checkpointvec[i].y == y){
			if (!checkpointvec[i].flag){
		  	std::cout << std::endl << "checkpoint " << i << ", " << flaggedpoints << " found" << std::endl;
				checkpointvec[i].flag = true;
				flaggedpoints++;
			}
    return i;
    }
  }
}



char Level::getGridChar(int x, int y){
//std::cout << ":" << ;//thismap[20][20];
  if (x > 0 && x < dim.width){
    if (y > 0 && y < dim.height){
     char c = thismap[x][y];
        return c;
    }else{
    return ' ';
    }
}
}

//void Level::tickCheckpoints(int id){
//}



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
