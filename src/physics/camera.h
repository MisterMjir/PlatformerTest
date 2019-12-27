#ifndef CAMERA
#define CAMERA

enum CAMERA_DIRECTION {NORTH_WEST, NORTH, NORTH_EAST, WEST, EAST, SOUTH_WEST, SOUTH, SOUTH_EAST, NONE};

class Camera
{
public:
  Camera();
  void move(int, int);
  void set(int, int);
  void setX(int);
  void setY(int);
  int getX() {return x;}
  int getY() {return y;}
  CAMERA_DIRECTION getDirection(); // Only for TileManager to use
private:
  int x;
  int y;
  int oldX;
  int oldY;
  CAMERA_DIRECTION direction;
};

#endif
