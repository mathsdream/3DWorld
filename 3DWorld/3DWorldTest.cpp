#include "Interface/Model3D.h"

int main()
{
    Point3D point1(1.0, 2.0, 3.0);
    Point3D point2(1.0, 2.0, 3.0);
    Point3D point3(1.0, 2.0, 4.0);
    Model3D model;
    if (model.AddPoint(point1))
        std::cout << "Add point1 successfully." << std::endl;
    else
        std::cout << "Add point1 failed." << std::endl;
    if (model.AddPoint(point2))
        std::cout << "Add point2 successfully." << std::endl;
    else
        std::cout << "Add point2 failed." << std::endl;
    if (model.AddPoint(point3))
        std::cout << "Add point3 successfully." << std::endl;
    else
        std::cout << "Add point3 failed." << std::endl;

    return 0;
}