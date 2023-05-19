
![cooltext435720758322101](https://github.com/yunrock/Vector2CplusplusClass/assets/5866432/3983644d-23a1-4da7-af09-3924f1fe29b3)

<hr></hr>
<h2 align="center"> 2D Vector Class in C++ </h2>
<p align="center">
   <img src="https://img.shields.io/badge/STATUS-IN%20DEVELOPMENT-green">
   <img src="https://img.shields.io/badge/LICENSE-CC%20BY--SA%204.0-blue">
</p>

## Introduction
<p align="justify">
   This Vector 2D class is a powerful tool for handling algebraic vectors in your projects. 
It provides a comprehensive set of operations and functionalities to perform common vector calculations efficiently.
</p>

## Description
<p align="justify">
   When working with vectors in programming, there is often the challenge of updating the vector's coordinates while simultaneously updating its magnitude and direction. Typically, this is done using Get and Set functions, but these functions are needed for each coordinate of the vector. <br>
   On the other hand, C# benefits from properties, which allow modifying the value of a field and performing actions as mentioned before. However, these features are not present in C++. <br> 
   That's why I built this Vector class, which includes another private class called Coordinate. Coordinate has a floating-point member variable that serves as a reference to store the coordinate value on the Vector side (I know it sounds tricky, but it might become clearer when looking at the code). Additionally, the = operator is overridden in the Coordinate class, so when updating the value of a coordinate, the magnitude and direction of the vector are also updated.  <br>
   With this class, you can confidently update the value of one of its coordinates using the = operator without worrying, as it will automatically update the magnitude and direction at that moment. <br>
</p>

### Example

```cpp
#include <iostream>
#include "Vector2.h"

int main() {
  // Create two vectors
  Vector2 v1(3, 4); // Its magnitude is 5 ( sqrt(9 + 16) )
  v1.x = 1; // At this point its magnitude is 4.12311
  v1.y = 1; // Now its magnitude is 1.41421, since sqrt( (1 * 1) + (1 * 1) ) => sqrt(2)
}
```

## Documentation
<p align="left">
   The code is thoroughly documented, please review it, and if there's anything that is not clear or lacks explanation, let me know.
</p>

## Features
<p align="left">
  
- `Feature 1`: Creation of 2D vectors with customizable x and y components.
- `Feature 1a`: Modifing the x and y components, by using = operator.
- `Feature 2`: Addition and subtraction of vectors.
- `Feature 3`: Scalar multiplication and division.
- `Feature 4`: Normalization of vectors.
- `Feature 5`: Calculation of the magnitude and angle of a vector.
- `Feature 6`: Calculation of the dot product and cross product of two vectors.
- `Feature 7`: Calculation of the angle between two vectors.
- `Feature 8`: Checking for equality between vectors.
- `Feature 9`: Checking for equality between magnitud of vectors.
</p>

## Technologies
<p align="left">
   C++
</p>

## Getting Started

To begin using the Vector2CplusplusClass in your C++ project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/yunrock/Vector2CplusplusClass.git
   ```

2. Include the necessary header file in your project:

   ```cpp
   #include "Vector2.h"
   ```

3. Compile your project with the Vector2CplusplusClass source files.

## Usage

Here's an example of how to use the Vector2CplusplusClass:

```cpp
#include "Vector2.h"
using namespace Vector2D;

using std::cout;

int main() {
  // Create two vectors
  Vector2 v1(3, 4);
  Vector2 v2(-2, 5);
  cout << "Vector 1: (" << v1.x << "," << v1.y << ")\n";
  cout << "Vector 1 magnitude: " << v1.magnitude() << "\n";
  cout << "Vector 1 direction: " << v1.direction() << "\n";
  cout << "Vector 2: (" << v2.x << "," << v2.y << ")\n";
  cout << "Vector 2 magnitude: " << v2.magnitude() << "\n";
  cout << "Vector 2 direction: " << v2.direction() << "\n\n";
  // Update vectors
  v1.x = -9;
  v2.x = 5;
  cout << "Updated vectors:" << "\n";
  cout << "Vector 1 magnitude: " << v1.magnitude() << "\n";
  cout << "Vector 1 direction: " << v1.direction() << "\n";
  cout << "Vector 2: (" << v2.x << "," << v2.y << ")\n";
  cout << "Vector 2 magnitude: " << v2.magnitude() << "\n";
  cout << "Vector 2 direction: " << v2.direction() << "\n\n";
    
  // Perform operations
  v1.normalize();
  v2.rotate(45);
  Vector2 sumVector = v1 + v2;
  Vector2 differenceVector = v1 - v2;
  Vector2 scaledVector = v1 * 2;
  Vector2 normalizedVector = Vector2::normalize(v2);
  float dotProduct = Vector2::dotProduct(v1, v2);
  float crossProduct = Vector2::crossProduct(v1, v2);
  bool areEqual = v1 == v2;

  // Print results
  cout << "After perform operations:" << "\n";
  cout << "Vector 1 normalized: (" << v1.x << "," << v1.y << ")\n";
  cout << "Vector 1 magnitude: " << v1.magnitude() << "\n";
  cout << "Vector 2 rotated(45): (" << v2.x << "," << v2.y << ")\n";
  cout << "Vector 2 direction: " << v2.direction() << "\n";
  cout << "Normalized copy of Vector 2: (" << normalizedVector.x << ", " << normalizedVector.y << ")\n";
  cout << "Sum Vector: (" << sumVector.x << ", " << sumVector.y << ")\n";
  cout << "Difference Vector: (" << differenceVector.x << ", " << differenceVector.y << ")\n";
  cout << "Scaled copy of Vector 1: (" << scaledVector.x << ", " << scaledVector.y << ")\n";
  cout << "Dot Product: " << dotProduct << "\n";
  cout << "Cross Product: " << crossProduct << "\n";
  cout << "Equality (magnitude) Check: " << std::boolalpha << areEqual << "\n";

} // End of main 
```

For detailed information about each method and its parameters, please refer to the documentation provided within the source code.


## Online example

You can see this class running at https://replit.com/@VladimirSanchez/Vector-2D-C-class

## Contribution

Contributions to the Vector2CplusplusClass project are welcome! If you want to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive messages.
4. Push your changes to your forked repository.
5. Submit a pull request to the main repository.

## License

CC BY-SA 4.0 https://creativecommons.org/licenses/by-sa/4.0/

## Author

| [<img src="https://github.com/yunrock/Vector2CplusplusClass/assets/5866432/a357a2cc-b63f-4a1e-9ac6-c1360e666f55" width=115><br><sub>Yunuén Vladimir</sub>](https://github.com/yunrock) |
| :---: |

If you have any questions or suggestions regarding the Vector2CplusplusClass, please feel free to contact the project maintainer at yunuenvladimir@gmail.com.

