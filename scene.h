#ifndef SCENE_H
#define SCENE_H


class Scene{
  private:
  
  
  public:
  
  Scene();
  ~Scene();
  
  struct SceneObject{
  unsigned int texid;
  };
  
  SceneObject trafficcone;
  SceneObject playercar;
};



#endif
