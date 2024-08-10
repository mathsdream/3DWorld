///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: Point3D.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <cmath>
#include <iostream>
#include <vector>

/// @brief 点的接口，描述空间中的一个点
class Point3D
{

public:

    /// @brief 默认构造函数
    Point3D()
        : x_(0), y_(0), z_(0)
    {}

    /// @brief 构造函数
    /// @param[in]      x               点的x坐标
    /// @param[in]      y               点的y坐标
    /// @param[in]      z               点的z坐标
    Point3D(double x, double y, double z)
        : x_(x), y_(y), z_(z)
    {}

    /// @brief 获取点的x坐标
    /// @return         x坐标
    double getX() const { return x_; }

    /// @brief 获取点的y坐标
    /// @return         y坐标
    double getY() const { return y_; }

    /// @brief 获取点的z坐标
    /// @return         z坐标
    double getZ() const { return z_; }

    /// @brief 设置点的x坐标
    /// @param[in]      x               x坐标
    void setX(double x) { x_ = x; }

    /// @brief 设置点的y坐标
    /// @param[in]      y               y坐标
    void setY(double y) { y_ = y; }

    /// @brief 设置点的z坐标
    /// @param[in]      z               z坐标
    void setZ(double z) { z_ = z; }

    /// @brief 获取到另一个点的距离
    /// @param[in]      point           另一个点
    /// @return         两点之间的距离
    double DistanceTo(const Point3D& point) const;

    /// @brief 重载=运算符
    /// @param[in]      point           另一个点
    /// @return         当前点
    Point3D& operator=(const Point3D& point);

    /// @brief 重载==运算符
    /// @param[in]      point           另一个点
    /// @return         两点是否相等
    bool operator==(const Point3D& point) const;

private:

    /// @brief 点的坐标
    double x_, y_, z_;

};

inline double Point3D::DistanceTo(const Point3D& point) const
{
    return std::sqrt((x_ - point.x_) * (x_ - point.x_) +
        (y_ - point.y_) * (y_ - point.y_) +
        (z_ - point.z_) * (z_ - point.z_));
}

inline Point3D& Point3D::operator=(const Point3D& point)
{
    x_ = point.x_;
    y_ = point.y_;
    z_ = point.z_;
    return *this;
}

inline bool Point3D::operator==(const Point3D& point) const
{
    return x_ == point.x_ && y_ == point.y_ && z_ == point.z_;
}