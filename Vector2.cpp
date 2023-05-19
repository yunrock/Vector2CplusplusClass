#include "Vector2.h"

using namespace Vector2D;

/**
 * @brief Member function that calculates the magnitud of the vector
 */
void Vector2::m_Magnitude() {
  m_magnitude = sqrt( (pow(m_xValue, 2) + pow(m_yValue, 2)) );
}

/**
 * @brief Member function that calculates the direction of the vector
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
 * @brief Normalizes the current vector
 */
void Vector2::normalize() {
  float tmpMagnitude = m_magnitude;
  x = m_xValue / tmpMagnitude;  
  y = m_yValue / tmpMagnitude;  
}

/**
 * @brief Rotates the current vector based in the formula
 * x' = x * cos(t_rAngle) - y * sen(t_rAngle) 
 * y' = x * sen(t_rAngle) + y * cos(t_rAngle) 
 * @param t_rAngle is the angle to rotate the vector
 */
void Vector2::rotate(const float& t_rAngle) {
  x = (m_xValue * cos(t_rAngle)) - (m_yValue * sin(t_rAngle));  
  y = (m_xValue * sin(t_rAngle)) + (m_yValue * cos(t_rAngle));  
}

/**
 * @brief Asigns the values of the parameter vector to the current vector 
 * @param t_rVector vector from wich values will be copied
 */
void Vector2::operator =(const Vector2& t_rVector) {
  this->x = t_rVector.m_xValue;
  this->y = t_rVector.m_yValue;
}

/**
 * @brief Sum of two vectors
 * @param t_rVector is a constant reference
 * @return a new Vector2 object 
 */
Vector2 Vector2::operator +(const Vector2& t_rVector) {
  return Vector2(this->x + t_rVector.m_xValue, this->y + t_rVector.m_yValue);
}

/**
 * @brief Substraction of two vectors
 * @param t_rVector is a constant reference
 * @return a new Vector2 object 
 */
Vector2 Vector2::operator -(const Vector2& t_rVector) {
  return Vector2(this->x - t_rVector.m_xValue, this->y - t_rVector.m_yValue);
}

/**
 * @brief Scalar product
 * @param t_rScalar const float reference
 * @return a new Vector2 object
 */
Vector2 Vector2::operator *(const float& t_rScalar) {
  return Vector2(this->x * t_rScalar, this->y * t_rScalar);
}

/**
 * @brief Division by a number
 * @param t_rScalar const float reference
 * @return a new Vector2 object
 */
Vector2 Vector2::operator /(const float& t_rScalar) {
  return Vector2(this->x * t_rScalar, this->y * t_rScalar);
}

/**
 * @brief Replace the coordinates values by the adition of the @param
 * @param t_rVector is a constant reference
 */
void Vector2::operator +=(const Vector2& t_rVector) {
  this->x = this->x + t_rVector.m_xValue;
  this->y = this->y + t_rVector.m_yValue;
}

/**
 * @brief Replace the coordinates values by the substraction of the @param
 * @param t_rVector is a constant reference
 */
void Vector2::operator -=(const Vector2& t_rVector) {
  this->x = this->x - t_rVector.m_xValue;
  this->y = this->y - t_rVector.m_yValue;
}

/**
 * @brief Replace the coordinates values by the scalar product of the @param
 * @param t_rScalar const float reference
 */
void Vector2::operator *=(const float& t_rScalar) {
  this->x = this->x * t_rScalar;
  this->y = this->y * t_rScalar;
}

/**
 * @brief Replace the coordinates values by the adition of the @param
 * @param t_rScalar const float reference
 */
void Vector2::operator /=(const float& t_rScalar) {
  this->x = this->x / t_rScalar;
  this->y = this->y / t_rScalar;
}

/**
 * @brief Compares the coordinates by the @param coordinates
 * @param t_rVector to be compared by values
 * @return return true if x = @param.x AND y = @param.y
 */
bool Vector2::operator ==(const Vector2& t_rVector) {
  return (this->m_xValue == t_rVector.m_xValue) && (this->m_yValue == t_rVector.m_yValue);
}

/**
 * @brief Compares the coordinates by the @param coordinates
 * @param t_rVector to be compared by values
 * @return return false if x = @param.x AND y = @param.y
 */
bool Vector2::operator !=(const Vector2& t_rVector) {
  return !(*this == t_rVector);
}

/**
 * @brief Compares the magnitude whit the @param magnitude
 * @param t_rVector to be compared by magnitude
 * @return return true if the magnitud of vector 
 * is strictly less than the @param magnitude
 */
bool Vector2::operator <(const Vector2& t_rVector) {
  return this->m_magnitude < t_rVector.m_magnitude;
}

/**
 * @brief Compares the magnitude whit the @param magnitude
 * @param t_rVector to be compared by magnitude
 * @return return true if the magnitud of vector 
 * is strictly bigger than the @param magnitude
 */
bool Vector2::operator >(const Vector2& t_rVector) {
  return this->m_magnitude > t_rVector.m_magnitude;
}

/**
 * @brief Compares the magnitude whit the @param magnitude
 * @param t_rVector to be compared by magnitude
 * @return return true if the magnitud of vector 
 * is less or equals than the @param magnitude
 */
bool Vector2::operator <=(const Vector2& t_rVector) {
  return this->m_magnitude <= t_rVector.m_magnitude;
}

/**
 * @brief Compares the magnitude whit the @param magnitude
 * @param t_rVector to be compared by magnitude
 * @return return true if the magnitud of vector 
 * is bigger or equals than the @param magnitude
 */
bool Vector2::operator >=(const Vector2& t_rVector) {
  return this->m_magnitude <= t_rVector.m_magnitude;
}

/**
 * @brief Dot product is a static function
 * @param t_rVector1 is a constant reference (v1)
 * @param t_rVector2 is a constant reference (v2)
 * @return float = (v1.x * v2.x) + (v1.y * v2.y)
 */
float Vector2::dotProduct(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  return (t_rVector1.m_xValue * t_rVector2.m_xValue) + (t_rVector1.m_yValue * t_rVector2.m_yValue);
}

/**
 * @brief Cross product is a static function
 * @param t_rVector1 is a constant reference (v1)
 * @param t_rVector2 is a constant reference (v2)
 * @return float = (v1.x * v2.y) - (v2.y * v2.x)
 */
float Vector2::crossProduct(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  return (t_rVector1.m_xValue * t_rVector2.m_yValue) - (t_rVector1.m_yValue * t_rVector2.m_xValue);
}

/**
 * @brief Distance between two vectors
 * @param t_rVector1 is a constant reference
 * @param t_rVector2 is a constant reference
 * @return float
 */
float Vector2::distance(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  float xTmp = t_rVector2.m_xValue - t_rVector1.m_xValue;
  float yTmp = t_rVector2.m_yValue - t_rVector1.m_yValue;
  if (xTmp == 0 && yTmp == 0) {
    return 0;
  }
  return sqrt ( powf(xTmp, 2) + powf(yTmp, 2) );
}

/**
 * @brief Calculates the angle between two vectors using @see dotPtoduct
 * @param t_rVector1 is a constant reference
 * @param t_rVector2 is a constant reference
 * @return float resulting of acos(dotPtoduct(t_rVector1, t_rVector2) / product of their magnitudes)
 */
float Vector2::angleBetween(const Vector2& t_rVector1, const Vector2& t_rVector2) {
  float xTmp = t_rVector2.m_xValue - t_rVector1.m_xValue;
  float yTmp = t_rVector2.m_yValue - t_rVector1.m_yValue;
  if (xTmp == 0 && yTmp == 0) {
    return 0;
  }
  return acos(dotProduct(t_rVector1, t_rVector2) / (t_rVector1.m_magnitude * t_rVector2.m_magnitude));
}

/**
 * @brief Rotates a vector through @param angle
 * @param t_rVector1 is a constant reference
 * @param t_rfloat is a constant reference
 * @return new vector @param angle rotated
 */
Vector2 Vector2::rotate(const Vector2& t_rVector1, const float& t_rAngle) {
  return Vector2((cos(t_rAngle) * t_rVector1.m_xValue) - (sin(t_rAngle) * t_rVector1.m_yValue),
                 (sin(t_rAngle) * t_rVector1.m_xValue) + (cos(t_rAngle) * t_rVector1.m_yValue));
}

/**
 * @brief normalize a new instance that is a copy of @param vector
 * @param t_rVector1 is a constant reference
 * @return normalized copy of @param 
 */
Vector2 Vector2::normalize(const Vector2& t_rVector1) {
  Vector2 tmp(t_rVector1.x, t_rVector1.y); 
  tmp.normalize();
  return tmp;
}