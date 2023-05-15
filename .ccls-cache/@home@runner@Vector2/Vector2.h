/**
 * <author> Yunuén Vladimir 
 * <site> https://yunuenvladimir.com
 * <source> https://github.com/yunrock/Vector2CplusplusClass
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
      float m_xValue; /**< stores the x Vector2 coordinate value */
      float m_yValue; /**< stores the y Vector2 coordinate value */
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
      
        public:
          /**
           * Here is where all the magic hapen. Every time it uses the = operator to update
           * a coordinate of the vector, the magnitud and the direction of itself
           * is also updated.
           */
          Coordenate& operator=(const float& t_val) {
            m_rValue = t_val;
            m_pParent->m_Magnitude();
            m_pParent->m_Direction();
            return *this;
          }
          /**
           * This kind of use of the operator () allow us to
           * get access to the m_rValue, which means that we can
           * get the coordinate value in the Vector2 class
           */
          operator const float& () const { 
            return m_rValue; 
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
      void rotate(const float& t_rAngle);

      void operator =(const Vector2& t_rVector);
      Vector2 operator +(const Vector2& t_rVector);
      Vector2 operator -(const Vector2& t_rVector);
      Vector2 operator *(const float& t_rScalar);
      Vector2 operator /(const float& t_rScalar);
      void operator +=(const Vector2& t_rVector);
      void operator -=(const Vector2& t_rVector);
      void operator *=(const float& t_rScalar);
      void operator /=(const float& t_rScalar);
      bool operator ==(const Vector2& t_rVector);//////
      bool operator !=(const Vector2& t_rVector);//////
      bool operator <(const Vector2& t_rVector);//////
      bool operator >(const Vector2& t_rVector);//////
      bool operator <=(const Vector2& t_rVector);//////
      bool operator >=(const Vector2& t_rVector);//////

      static float dotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2);
      static float distance(const Vector2& t_rVector1, const Vector2& t_rVector2);
      static Vector2 rotate(const Vector2& t_rVector, const float& t_rAngle); //////
  };
}


using namespace Vector2D;

/**
 * Member function that calculates the magnitud of the vector
 */
void Vector2::m_Magnitude() {
  m_magnitude = sqrt( (pow(m_xValue,2) + pow(m_yValue, 2)) );
}

/**
 * Member function that calculates the direction of the vector
 */
void Vector2::m_Direction() {
  if (m_xValue == 0) {
    if (m_yValue == 0) {
      m_direction = 0;
      return;
    }
    if (m_yValue > 0) {
      m_direction = 90;
      return;
    }
    if (m_yValue < 0) {
      m_direction = 180;
      return;
    }
  }
  m_direction = atan(m_yValue / m_xValue);
}

/**
 * @returns a float value that is the magnitud of the vector
 */
float Vector2::magnitude() {
  return m_magnitude;
}

/**
 * @returns a float value that is the direction of the vector
 */
float Vector2::direction() {
  return m_direction;
}

/**
 * Normalizes the current vector
 */
void Vector2::normalize() {
  x = m_xValue / m_magnitude;  
  y = m_yValue / m_magnitude;  
}

/**
 * Rotates the current vector based in the formula
 * x' = x * cos(t_rAngle) - y * sen(t_rAngle) 
 * y' = x * sen(t_rAngle) + y * cos(t_rAngle) 
 * @param t_rAngle is the angle to rotate the vector
 */
void Vector2::rotate(const float& t_rAngle) {
  x = (m_xValue * cos(t_rAngle)) - (m_yValue * sin(t_rAngle));  
  y = (m_xValue * sin(t_rAngle)) + (m_yValue * cos(t_rAngle));  
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
Vector2 Vector2::operator +(const Vector2& t_rVector) {
  return Vector2(this->x + t_rVector.m_xValue, this->y + t_rVector.m_yValue);
}

/**
 * 
 * @param
 * @return
 */
Vector2 Vector2::operator -(const Vector2& t_rVector) {
  return Vector2(this->x - t_rVector.m_xValue, this->y - t_rVector.m_yValue);
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
Vector2 Vector2::operator /(const float& t_rScalar) {
  return Vector2(this->x * t_rScalar, this->y * t_rScalar);
}

/**
 * 
 * @param
 */
void Vector2::operator +=(const Vector2& t_rVector) {
  this->x = this->x + t_rVector.m_xValue;
  this->y = this->y + t_rVector.m_yValue;
}

/**
 * 
 * @param
 */
void Vector2::operator -=(const Vector2& t_rVector) {
  this->x = this->x - t_rVector.m_xValue;
  this->y = this->y - t_rVector.m_yValue;
}

/**
 * 
 * @param
 * @return
 */
void Vector2::operator *=(const float& t_rScalar) {
  this->x = this->x * t_rScalar;
  this->y = this->y * t_rScalar;
}

/**
 * 
 * @param
 * @return
 */
void Vector2::operator /=(const float& t_rScalar) {
  this->x = this->x / t_rScalar;
  this->y = this->y / t_rScalar;
}

/**
 * 
 * @param
 * @param
 * @return
 */
float Vector2::dotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  return (t_rVector1.m_xValue * t_rVector2.m_xValue) + (t_rVector1.m_yValue * t_rVector2.m_yValue);
}

/**
 * 
 * @param
 * @param
 * @return
 */
float Vector2::distance(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  float xTmp = t_rVector2.m_xValue - t_rVector1.m_xValue;
  float yTmp = t_rVector2.m_yValue - t_rVector1.m_yValue;
  if (xTmp == 0 && yTmp == 0) {
    return 0;
  }
  return sqrt ( powf(xTmp, 2) + powf(yTmp, 2) );
}