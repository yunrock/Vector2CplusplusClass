#include <iostream>

/**
 * @author Yunuén Vladimir
 *
 */

class Vector2 {
private:
  class Coordenate {
  private:
    float m_value;
    Coordenate(float &p_value) : m_value(p_value) {}
    Coordenate &operator=(const float& p_val) {
      m_value = p_val;
      return *this;
    }
    operator const float &() const { return m_value; }
    friend class Vector2;
  };
  float m_x;
  float m_y;

public:
Vector2 () : x(m_x), y(m_y) { }
Coordenate x, y;
};