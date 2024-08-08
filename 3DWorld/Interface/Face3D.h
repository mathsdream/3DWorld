#pragma once
#include <vector>
#include "Point3D.h"

/// @brief 3D面的接口，描述一个3D面，由三个顶点组成
class Face3D
{

public:

    /// @brief 默认构造函数
    Face3D()
    {
        points_.reserve(3);
    }

    /// @brief 构造函数
    /// @param[in]      point1,point2,point3       面的三个顶点
    Face3D(Point3D point1, Point3D point2, Point3D point3)
    {
        points_.reserve(3);
        if (point1 == point2 || point1 == point3 || point2 == point3)
            throw std::invalid_argument("The three points are the same.");
        else
        {
            points_.push_back(point1);
            points_.push_back(point2);
            points_.push_back(point3);
        }
    }

    /// @brief 获取面的顶点
    /// @return         面的顶点
    std::vector<Point3D> GetPoints() const { return points_; }

    /// @brief 设置面的其中一个顶点
    /// @param[in]      point           顶点
    /// @param[in]      index           顶点的索引
    /// @return         是否设置成功
    bool SetPoint(Point3D point, int index = 0);

    /// @brief 获取面的面积
    /// @return         面的面积
    double GetArea() const;

    /// @brief 问一个点是否为面的顶点
    /// @param[in]      point           点
    /// @return         是否为面的顶点
    bool IsPointOfFace(Point3D point) const;

    /// @brief 重载=运算符
    /// @param[in]      face            另一个面
    /// @return         当前面
    Face3D& operator=(const Face3D& face);
    
    /// @brief 重载==运算符
    /// @param[in]      face            另一个面
    /// @return         是否相等（无序）
    bool operator==(const Face3D& face) const;

private:
    
    /// @brief 面的顶点
    std::vector<Point3D> points_;

};

inline bool Face3D::SetPoint(Point3D point, int index)
{
    if (index < 0 || index >= 3)
    {
        std::cerr << "The index is out of range." << std::endl;
        return false;
    }
    if (index == 0 && (point == points_[1] || point == points_[2]))
    {
        std::cerr << "The point is the same as the other two points." << std::endl;
        return false;
    }
    if (index == 1 && (point == points_[0] || point == points_[2]))
    {
        std::cerr << "The point is the same as the other two points." << std::endl;
        return false;
    }
    if (index == 2 && (point == points_[0] || point == points_[1]))
    {
        std::cerr << "The point is the same as the other two points." << std::endl;
        return false;
    }
    points_[index] = point;
    return true;
}

inline double Face3D::GetArea() const
{
    double a = points_[0].DistanceTo(points_[1]);
    double b = points_[1].DistanceTo(points_[2]);
    double c = points_[2].DistanceTo(points_[0]);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

inline bool Face3D::IsPointOfFace(Point3D point) const
{
    for (auto& p : points_)
    {
        if (p == point)
            return true;
    }
    return false;
}

inline Face3D& Face3D::operator=(const Face3D& face)
{
    points_[0] = face.points_[0];
    points_[1] = face.points_[1];
    points_[2] = face.points_[2];
    return *this;
}

inline bool Face3D::operator==(const Face3D& face) const
{
    for (auto& p : face.points_)
    {
        if (!IsPointOfFace(p))
            return false;
    }
    return true;
}

