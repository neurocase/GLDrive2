#ifndef PHYSICS_H
#define PHYSICS_H

class Physics{
  
  public:
  
  Physics();
  ~Physics();
  
  void CalcPhys(double &degrot, int rotdir, double &px, double &py, double &velx, double &vely, bool throttle, bool isbrake, bool ishbrake,double &engineforcereturn, char **newmap, int maplength);


};


#endif
