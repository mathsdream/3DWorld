#pragma once
#include <vector>
#include <iostream>
#include "Point3D.h"

class Face3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Face3D()
    {
        points_.reserve(3);
    }

private:
    
    /// @brief ��Ķ���
    std::vector<Point3D> points_;

};
