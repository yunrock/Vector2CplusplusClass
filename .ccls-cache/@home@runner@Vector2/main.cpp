#include "Vector2.h"


int main() {
  Vector2 v2(1, 1);
  Vector2 v3(3, 4);
  v2.x = 3;
  v2.y = 5;
  //v3 = v2 * 10;
  //float f = Vector2::dotProduct(v2, v3);
  std::cout << Vector2::distance(v2, v3) << "  Hello World!\n"; 
}