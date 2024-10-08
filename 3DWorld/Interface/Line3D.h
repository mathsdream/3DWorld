///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: Line3D.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------


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

    /// @brief 获取线段的端点
    /// @return         线段的端点
    std::vector<Point3D> GetPoints() const { return points_; }

    /// @brief 设置线段的其中一个端点
    /// @param[in]      point           端点
    /// @param[in]      index           端点的索引
    /// @return         是否设置成功
    bool SetPoint(Point3D point, int index = 0);

    /// @brief 判断某点是否为线段的端点
    /// @param[in]      point           点
    /// @return         是否为线段的端点
    bool IsPointOfLine(Point3D point) const;

    /// @brief 获取线段的长度
    /// @return         线段的长度
    double GetLength() const;

    /// @brief 重载=运算符
    /// @param[in]      line            另一个线段
    /// @return         当前线段
    Line3D& operator=(const Line3D& line);

    /// @brief 重载==运算符
    /// @param[in]      line            另一个线段
    /// @return         是否相等
    bool operator==(const Line3D& line) const;

private:

    /// @brief 线段的端点
    std::vector<Point3D> points_;

};

inline bool Line3D::SetPoint(Point3D point, int index)
{
    if (index < 0 || index > 1)
        return false;
    if (index == 1 && point == points_[0])
        return false;
    if (index == 0 && point == points_[1])
        return false;
    points_[index] = point;
    return true;
}

inline bool Line3D::IsPointOfLine(Point3D point) const
{
    return points_[0] == point || points_[1] == point;
}

inline double Line3D::GetLength() const
{
    return points_[0].DistanceTo(points_[1]);
}

inline Line3D& Line3D::operator=(const Line3D& line)
{
    points_[0] = line.points_[0];
    points_[1] = line.points_[1];
    return *this;
}

inline bool Line3D::operator==(const Line3D& line) const
{
    return (points_[0] == line.points_[0] && points_[1] == line.points_[1]) ||
        (points_[0] == line.points_[1] && points_[1] == line.points_[0]);
}
