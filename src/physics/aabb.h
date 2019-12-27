#ifndef AABB_CLASS
#define AABB_CLASS

enum AABB_Type {COLLISION, HIT, HURT};

class AABB
{
public:
  AABB(int x, int y, int w, int h, AABB_Type, bool linked);

  int xOverlap(AABB*);
  int xDiff(AABB*);
  int yOverlap(AABB*);
  int yDiff(AABB*);

  int getX() {return x;}
  void changeX(int change) {x += change;}
  int getY() {return y;}
  void changeY(int change) {y += change;}
  int getW() {return w;}
  int getH() {return h;}
  AABB_Type getType() {return type;}
  bool isLinked() {return linked;}
private:
  int x, y, w, h; // Coordinates and size
  AABB_Type type; // Type of AABB
  bool linked; // Is this linked to other AABBs
};

#endif
