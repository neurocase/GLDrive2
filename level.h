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
  
  
 
  int checkpoints;
  
  Level(char **newmap, int length);
  void getPlayerStart(int&,int&);
  void getDimensions(int&,int&);
  ~Level();
  


};

#endif
