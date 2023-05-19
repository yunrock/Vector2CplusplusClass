#include "Vector2.h"
using namespace Vector2D;

int main() {
  Vector2 v1(1, 1);
  Vector2 v2(-1, 2);
  v2.x = 3;
  v2.y = 4;
  //v3 = v2 * 10;
  //float f = Vector2::dotProduct(v2, v3);
  //std::cout << Vector2::distance(v2, v3) << "\nHello World!  \n"; 
  std::cout << "\n v1(" << v1.x << ", " << v1.y << ")\n"; 
  std::cout << "\n v1 magnitude: " << v1.magnitude() << "\n"; 
  std::cout << "\n v2(" << v2.x << ", " << v2.y << ")\n"; 
  std::cout << "\n v2 magnitude: " << v2.magnitude() << "\n"; 
  Vector2 v3 = v2 * 10;
  std::cout << "\n v3 magnitude: " << v3.magnitude() << "\nHello World!  \n"; 
}