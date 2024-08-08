#include "Interface/Model3D.h"
#include "Interface/Line3D.h"
#include "Interface/Point3D.h"


int main()
{
    Point3D point1(0, 0, 0);
    Point3D point2(1, 2, 3);
    Line3D line1(point1, point2);
    std::cout << "The length of line1 is " << line1.GetLength() << std::endl;

    Model3D model;
    Point3D point3(1, 2, 3);
    if (model.AddPoint(point1))
        std::cout << "Add point1 successfully." << std::endl;
    if (model.AddPoint(point2))
        std::cout << "Add point2 successfully." << std::endl;
    if (model.AddPoint(point3))
        std::cout << "Add point3 successfully." << std::endl;

    return 0;
}