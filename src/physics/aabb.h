#ifndef AABB_CLASS
#define AABB_CLASS

class AABB
{
public:
  AABB(int x, int y, int w, int h, bool collision, bool hit, bool hurt);

  // Collision
  int xCollision(AABB*);
  int xDiff(AABB*);
  int yCollision(AABB*);
  int yDiff(AABB*);

  // Hit

  // Hurt

  int getX() {return x;}
  void changeX(int change) {x += change;}
  int getY() {return y;}
  void changeY(int change) {y += change;}
  int getW() {return w;}
  int getH() {return h;}
private:
  int x, y, w, h;
  bool collision, hit, hurt;
};

#endif
