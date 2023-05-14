#include "Vector2.h"


int main() {
  Vector2 v2(1, 1);
  Vector2 v3(1, 1);
  v2.x = 3;
  v2.y = 4;
  //v3 = v2 * 10;
  std::cout << v3.magnitude() << "  Hello World!\n";
}