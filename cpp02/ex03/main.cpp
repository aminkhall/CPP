#include "Point.hpp"

int main()
{
    // Create triangle points
    Point A(2.0f, 2.0f);
    Point B(5.0f, 6.0f);
    Point C(2.0f, 5.0f);

    // Test points
    Point inside(3.0f, 5.0f);
    Point outside(3.0f, 4.0f);
    Point edge(2.8f, 5.3f);
    FIXED F(12.2f);
    FIXED G(2);
    FIXED R = FIXED(2) + FIXED(15) + FIXED(13) - FIXED(13) + FIXED(2) * FIXED(10);

    std::cout << F << std::endl;
    std::cout << G << std::endl;
    std::cout << R << std::endl;
    std::cout << ">>>>>" << R.min(F, G) << "<<<<<<<<" << std::endl;

    // R = F +  G;
    // std::cout << "Triangle: " << A << ", " << B << ", " << C << std::endl;

    std::cout << "Testing point " << inside << ": "
              << (bsp(A, B, C, inside) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "Testing point " << outside << ": "
              << (bsp(A, B, C, outside) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "Testing point " << edge << ": "
              << (bsp(A, B, C, edge) ? "INSIDE" : "OUTSIDE") << std::endl;

    return 0;
}