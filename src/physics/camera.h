#ifndef CAMERA
#define CAMERA

class Camera
{
public:
  static int getX() {return x;}
  static int getY() {return y;}
  static void changeX(int change) {x += change;}
  static void changeY(int change) {y += change;}
private:
  Camera();
  ~Camera();
  static int x, y;
};

#endif
