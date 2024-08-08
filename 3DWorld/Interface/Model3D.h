#pragma once
#include "Point3D.h"
#include "Line3D.h"
#include "Face3D.h"

/// @brief 3Dodel的接口，描述一个3D模型
class Model3D
{

public:

    /// @brief 默认构造函数
    Model3D() {};

    /// @brief 添加一个顶点
    /// @param[in]      point           顶点
    /// @return         是否添加成功（检查是否有重复的顶点）
    bool AddPoint(Point3D point)
    {
        for (Point3D& p : points_)
        {
            if (p == point)
                return false;
        }
        points_.push_back(point);
        return true;
    }

    /// @brief 添加一个线段

private:

    /// @brief 3D模型的顶点
    std::vector<Point3D> points_;

    /// @brief 3D模型的线段
    std::vector<Line3D> lines_;

    /// @brief 3D模型的面
    std::vector<Face3D> faces_;

};
