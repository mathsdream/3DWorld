///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: Point3D.h
/// 作者：mathsdream
/// 
/// 重要说明：
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <vector>

/// @brief 点的接口，描述空间中的一个点
class Point3D
{

public:

    /// @brief 构造函数
    /// @param[in]      x               点的x坐标
    /// @param[in]      y               点的y坐标
    /// @param[in]      z               点的z坐标
    Point3D(double x, double y, double z)
        : x_(x), y_(y), z_(z)
    {}

    /// @brief 获取到另一个点的距离
    /// @param[in]      point           另一个点
    double DistanceTo(const Point3D& point) const
    {
        return sqrt((x_ - point.x_) * (x_ - point.x_) +
            (y_ - point.y_) * (y_ - point.y_) +
            (z_ - point.z_) * (z_ - point.z_));
    }

    /// @brief 重载==运算符
    bool operator==(const Point3D& point) const
    {
        return x_ == point.x_ && y_ == point.y_ && z_ == point.z_;
    }

private:

    /// @brief 点的坐标
    double x_, y_, z_;

};