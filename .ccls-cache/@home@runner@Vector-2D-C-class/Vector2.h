/**
 * @file Vector2.h
 * @brief This file contains the definition of the Vector2 class, which is used to handle two-dimensional vectors.
 * The class provides various operations and functionalities for manipulating vectors.
 * @author Yunuén Vladimir
 * @site https://yunuenvladimir.com
 * @source https://github.com/yunrock/Vector2CplusplusClass
 * @license CC BY-SA 4.0 <https://creativecommons.org/licenses/by-sa/4.0/>
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

#ifndef VECTOR2_H
#define VECTOR2_H
#endif

#include <iostream>
#include <math.h>


namespace Vector2D {
  class Vector2 {
    private:
      float m_xValue; /**< stores the x Vector2 coordinate value */
      float m_yValue; /**< stores the y Vector2 coordinate value */
      float m_magnitude; /**< stores the magnitude of the vector */
      float m_direction; /**< stores the direction (angle) of the vector in radians */

      /**
       * @class Coordenate
       * @brief A private nested class that allows Vector2 class to track changes to its coordinates.
       * was changed by the operator "=". To do this, is necesary handle the value
       * of the coordinate as a reference of the original value in the Vector2 class
       */
      class Coordenate {
        private:
          float& m_rValue; /**< Reference to the Vector2 coordinate value */
          Vector2* m_pParent;/**< Pointer to the parent Vector2 object */
          Coordenate(float& t_value, Vector2* t_m_pParent) : 
            m_rValue(t_value), m_pParent(t_m_pParent) {}
      
        public:
          /**
           * @brief Assignment operator overload that updates the coordinate value, 
           *magnitude, and direction of the parent Vector2 object.
           * Here is where all the magic hapen. Every time it uses the = operator to update
           * a coordinate of the vector, the magnitud and the direction of itself
           * is also updated.
           * @param t_val The new value to assign to the coordinate
           * @return Reference to the Coordenate object
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
           * @return Constant reference to the coordinate value
           */
          operator const float& () const { 
            return m_rValue; 
          }
        friend class Vector2;
      };
    
      void m_Magnitude();
      void m_Direction();
  
    public:
      Coordenate x; /**< Coordenate object representing the x-coordinate of the vector */
      Coordenate y; /**< Coordenate object representing the y-coordinate of the vector */

      /**
       * @brief Constructs a Vector2 object with the given x and y coordinates.
       * The magnitude and direction are automatically calculated.
       * @param t_x The x-coordinate value
       * @param t_y The y-coordinate value
       */
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
      bool operator ==(const Vector2& t_rVector);
      bool operator !=(const Vector2& t_rVector);
      bool operator <(const Vector2& t_rVector);
      bool operator >(const Vector2& t_rVector);
      bool operator <=(const Vector2& t_rVector);
      bool operator >=(const Vector2& t_rVector);

      static float dotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2);
      static float crossProduct(const Vector2& t_rVector1, const Vector2& t_rVector2);
      static float distance(const Vector2& t_rVector1, const Vector2& t_rVector2);
      static float angleBetween(const Vector2& t_rVector1, const Vector2& t_rVector2); 
      static Vector2 rotate(const Vector2& t_rVector, const float& t_rAngle); 
      static Vector2 normalize(const Vector2& t_rVector); 
  };
}
