#ifndef LEVEL_H
#define LEVEL_H

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
  
  public:
  
  int lheight;
  int lwidth;
  int checkpoints;
  int arraylength;
  char **thismap;
  Level(char **newmap, int length, double& playsx, double& playsy);
  char getGridChar(int,int);
  void getPlayerStart(int&,int&);
  void getDimensions(int&,int&);
  ~Level();
  


};

#endif
