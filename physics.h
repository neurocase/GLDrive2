#ifndef PHYSICS_H
#define PHYSICS_H

#include "level.h"
#include "player.h"

class Physics{
  
  public:
  
  Physics();
  ~Physics();
  
  void CalcPhys(Player &Player, Level &MyLevel);


};


#endif
