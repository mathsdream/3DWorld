#pragma once
#include <vector>
#include <iostream>
#include "Point3D.h"

class Face3D
{

public:

    /// @brief 默认构造函数
    Face3D()
    {
        points_.reserve(3);
    }

private:
    
    /// @brief 面的顶点
    std::vector<Point3D> points_;

};
