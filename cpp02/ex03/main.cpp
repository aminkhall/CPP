#include "Point.hpp"

int main() {
    // Create triangle points
    Point A(2.0f, 2.0f);
    Point B(5.0f, 6.0f);
    Point C(2.0f, 5.0f);

    // Test points
    Point inside(3.0f, 5.0f);
    Point outside(3.0f, 4.0f);
    Point edge(2.8f, 5.3f);

    std::cout << "Triangle: " << A << ", " << B << ", " << C << std::endl;

    std::cout << "Testing point " << inside << ": "
              << (bsp(A, B, C, inside) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "Testing point " << outside << ": "
              << (bsp(A, B, C, outside) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "Testing point " << edge << ": "
              << (bsp(A, B, C, edge) ? "INSIDE" : "OUTSIDE") << std::endl;

    return 0;
}