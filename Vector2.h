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
 * (without _) s to name statics, r to name references, and p to name pointers.
 */
#include <iostream>
#include <math.h>

using std::cout;


namespace Vector2D {
  class Vector2 {
    private:
      float m_xValue;
      float m_yValue;
      float m_magnitude;
      float m_direction; 

      /**
       * This is a private class that allows Vector2 class to know if any coordenate
       * was changed by the operator "=". To do this, is necesary handle the value
       * of the coordinate as a reference of the original value in the Vector2 class
       */
      class Coordenate {
        private:
          float& m_rValue; /**< Reference to the Vector2 coordinate value */
          Vector2* m_pParent;
          Coordenate(float& t_value, Vector2* t_m_pParent) : 
                     m_rValue(t_value), m_pParent(t_m_pParent) {}
          operator const float& () const { 
            return m_rValue; 
          }
      
        public:
          Coordenate& operator=(const float& t_val) {
            m_rValue = t_val;
            m_pParent->m_Magnitude();
            m_pParent->m_Direction();
            return *this;
          }
        friend class Vector2;
      };
    
      void m_Magnitude();
      void m_Direction();
  
    public:
      Coordenate x, y;
      Vector2(float t_x, float t_y) : x(m_xValue, this), y(m_yValue, this) {
        x = t_x;
        y = t_y;
      }
      float magnitude();
      float direction(); 
      void normalize(); 
      void operator =(const Vector2& t_rVector);
      Vector2 operator *(const float& t_rScalar);
      Vector2 operator +(const Vector2& t_rVector);
      Vector2 operator -(const Vector2& t_rVector);
      static float sDotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2);
  };
}


using namespace Vector2D;

/**
 *
 */
void Vector2::m_Magnitude() {
  m_magnitude = sqrt( (pow(m_xValue,2) + pow(m_yValue, 2)) );
}

/**
 *
 */
void Vector2::m_Direction() {
        
}

/**
 *
 */
float Vector2::magnitude() {
  return m_magnitude;
}

/**
 *
 */
float Vector2::direction() {
  return m_direction;
}

/**
 *
 */
void Vector2::normalize() {
  
}

/**
 * 
 * @param
 */
void Vector2::operator =(const Vector2& t_rVector) {
  this->x = t_rVector.m_xValue;
  this->y = t_rVector.m_yValue;
}

/**
 * 
 * @param
 * @return
 */
Vector2 Vector2::operator *(const float& t_rScalar) {
  return Vector2(this->x * t_rScalar, this->y * t_rScalar);
}

/**
 * 
 * @param
 * @return
 */
Vector2 Vector2::operator +(const Vector2& t_rVector) {
  return Vector2(this->x + t_rVector.m_xValue, this->y + t_rVector.m_yValue);
}

/**
 * 
 * @param
 * @param
 * @return
 */
float Vector2::sDotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  return (t_rVector1.m_xValue * t_rVector2.m_xValue) + (t_rVector1.m_yValue * t_rVector2.m_yValue);
}