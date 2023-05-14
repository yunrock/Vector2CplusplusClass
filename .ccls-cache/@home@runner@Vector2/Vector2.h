/**
 * <author> Yunuén Vladimir 
 * <size> https://yunuenvladimir.com
 * <source> https://www.github.com/
 * <license> CC BY-SA 4.0 <https://creativecommons.org/licenses/by-sa/4.0/>
 *
 * Vector2 is a class to handle vectors of two coordinates,
 * but with the advantage of use the "=" operator to update
 * a coordenate of the vector, and also update the magnitude
 * and the direction. 
 * @example Vector2 v1(1, 1), //have a magnitud of 1.41421  
 * v1.x = 3; v1.y = 4; //automatically have a magnitude of 5 
 * 
 * <<IMPORTANT NOTE>> 
 * I use prefix: t_ to name parameters, m_ to name members, 
 * r to name references (without _), and p to name pointers (without _).
 */
#include <iostream>
#include <math.h>

using std::cout;


namespace Vector2D {
  class Vector2 {
    private:
      /**
       * This is a private class that allows Vector2 class to know if any coordenate
       * was changed by the operator "=". To do this, is necesary handle the value
       * of the coordinate as a reference of the original value in the Vector2 class
       */
      class Coordenate {
        private:
          float& m_rValue; /**< Reference to the Vector2 coordinate value */
          Vector2* m_pParent;
      
        public:
          Coordenate(float& t_value, Vector2* t_m_pParent) : m_rValue(t_value), m_pParent(t_m_pParent) {}
  
          Coordenate& operator=(const float& t_val) {
            m_rValue = t_val;
            m_pParent->Magnitude();
            return *this;
          }
  
          operator const float& () const { 
            return m_rValue; 
          }
  
          friend class Vector2;
      };
  
      float m_x;
      float m_y;
      float m_magnitude;
    
      void Magnitude() {
        m_magnitude = sqrt( (pow(m_x,2) + pow(m_y, 2)) );
      }
  
    public:
      Coordenate x, y;
      Vector2(float t_x, float t_y) : x(m_x, this), y(m_y, this) {
        x = t_x;
        y = t_y;
        //Magnitude();
      }
      float magnitude();
      void operator =(const Vector2& t_rVector);
      Vector2 operator *(const float& t_rScalar);
      Vector2 operator +(const Vector2& t_rVector);
      Vector2 operator -(const Vector2& t_rVector);
  };
}
/*
float Vector2::m_x = 0;
float Vector2::m_y = 0;
float Vector2::m_magnitude = 0;*/

using namespace Vector2D;

/**
 *
 */
float Vector2::magnitude() {
  return m_magnitude;
}

/**
 *
 */
void Vector2::operator =(const Vector2& t_rVector) {
  this->x = t_rVector.m_x;
  this->y = t_rVector.m_y;
}

Vector2 Vector2::operator *(const float& t_rScalar) {
  return Vector2(this->x * t_rScalar, this->y * t_rScalar);
}