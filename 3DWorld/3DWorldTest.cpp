#include "Interface/Model3D.h"
#include "Interface/Line3D.h"
#include "Interface/Point3D.h"


int main()
{
    Point3D point1(0, 0, 0);
    Point3D point2(1, 2, 3);
    Line3D line1(point1, point2);
    std::cout << "The length of line1 is " << line1.GetLength() << std::endl;
    Point3D point3(1, 2, 3);

    // ��������û�ֱ�ӵ���line�ĳ�Ա����
    // line1.points_[0] = point3;
    // �����ͻᵼ��line1�������˵��غ�

    // �������ǲ������û�ֱ�ӵ���line�ĳ�Ա����
    if (!line1.SetPoint(point3, 0))
        std::cerr << "Failed to set the point." << std::endl;
    std::cout << "The length of line1 is " << line1.GetLength() << std::endl;

    return 0;
}