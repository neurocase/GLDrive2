#ifndef PHYSICS_H
#define PHYSICS_H

class Physics{
  
  public:
  
  Physics();
  ~Physics();
  
  void CalcPhys(double rot, double &px, double &py, double &velx, double &vely, bool throttle, bool isbrake, bool ishbrake);


};


#endif
