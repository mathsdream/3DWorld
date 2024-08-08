#include "Interface/Model3D.h"

int main()
{
    Point3D point1(0, 0, 0);
    Point3D point2(1, 2, 3);
    Line3D line1(point1, point2);
    std::cout << "The length of line1 is " << line1.GetLength() << std::endl;

    return 0;
}