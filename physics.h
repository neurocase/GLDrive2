#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"

class Physics{
  
  public:
  
  Physics();
  ~Physics();
  
  void CalcPhys(Player &Player, char **newmap, int maplength);


};


#endif
