#include "Vector2.h"
using namespace Vector2D;

using std::cout;

int main() {
    // Create two vectors
    Vector2 v1(3, 4);
    Vector2 v2(-2, 5);
    
    // Update vectors
    v1.x = -9;
    v2.x = 5;
    
    // Perform operations
    v1.normalize();
    v2.rotate(45);
    Vector2 sumVector = v1 + v2;
    Vector2 differenceVector = v1 - v2;
    Vector2 scaledVector = v1 * 2;
    Vector2 normalizedVector = Vector2::normalize(v1);
    float dotProduct = Vector2::dotProduct(v1, v2);
    float crossProduct = Vector2::crossProduct(v1, v2);
    bool areEqual = v1 == v2;

    // Print results
    cout << "Vector 1: (" << v1.x << "," << v1.y << ")\n";
    cout << "Vector 1 magnitude: " << v1.magnitude() << "\n";
    cout << "Vector 2: (" << v2.x << "," << v2.y << ")\n";
    cout << "Vector 2 direction: " << v2.direction() << "\n";
    cout << "Normalized Vector 1: (" << normalizedVector.x << ", " << normalizedVector.y << ")\n";
    cout << "Sum Vector: (" << sumVector.x << ", " << sumVector.y << ")\n";
    cout << "Difference Vector: (" << differenceVector.x << ", " << differenceVector.y << ")\n";
    cout << "Scaled Vector: (" << scaledVector.x << ", " << scaledVector.y << ")\n";
    cout << "Dot Product: " << dotProduct << "\n";
    cout << "Cross Product: " << crossProduct << "\n";
    cout << "Equality Check: " << std::boolalpha << areEqual << "\n";

}