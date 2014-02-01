#ifndef LEVEL_H
#define LEVEL_H


#include <vector>

class Level{

  private:
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
	bool flag;
	};
  
  public:
  
	Dim dim;
	Playerstart playerstart;
	std::vector <Checkpoint> checkpointvec;
	
//  int lheight;
 // int lwidth;
  int checkpoints;
  int arraylength;
	int flaggedpoints;

  Level(char **newmap, int length, double& playsx, double& playsy);
	void resetFlags();
	bool lapCheck();
  int getCheckpointId(int x, int y);
  char getGridChar(int,int);
  void getPlayerStart(int&,int&);
  void getDimensions(int&,int&);
  ~Level();
  


};

#endif
