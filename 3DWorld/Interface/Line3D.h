#pragma once
#include <stdexcept>
#include <vector>
#include <set>
#include "Point3D.h"

class Line3D
{

public:

    /// @brief 默认构造函数
    Line3D()
    {
        points_.reserve(2);
    }

    /// @brief 构造函数
    /// @param[in]      point1,point2       线段的两个端点
    Line3D(Point3D point1, Point3D point2)
    {
        points_.reserve(2);
        if (point1 == point2)
            throw std::invalid_argument("The two points are the same.");
        else
        {
            points_.push_back(point1);
            points_.push_back(point2);
        }
    }

    /// @brief 获取线段的长度
    /// @return         线段的长度
    double GetLength() const
    {
        return points_[0].DistanceTo(points_[1]);
    }

    /// @brief 重载==运算符
    /// @param[in]      line            另一个线段
    /// @return         是否相等
    bool operator==(const Line3D& line) const
    {
        return (points_[0] == line.points_[0] && points_[1] == line.points_[1]) ||
            (points_[0] == line.points_[1] && points_[1] == line.points_[0]);
    }


private:

    /// @brief 线段的端点
    std::vector<Point3D> points_;

};

