///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: Point3D.h
/// ���ߣ�mathdream
/// 
/// ��Ҫ˵����
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <cmath>
#include <iostream>
#include <vector>

/// @brief ��Ľӿڣ������ռ��е�һ����
class Point3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Point3D()
        : x_(0), y_(0), z_(0)
    {}

    /// @brief ���캯��
    /// @param[in]      x               ���x����
    /// @param[in]      y               ���y����
    /// @param[in]      z               ���z����
    Point3D(double x, double y, double z)
        : x_(x), y_(y), z_(z)
    {}

    /// @brief ��ȡ���x����
    /// @return         x����
    double getX() const { return x_; }

    /// @brief ��ȡ���y����
    /// @return         y����
    double getY() const { return y_; }

    /// @brief ��ȡ���z����
    /// @return         z����
    double getZ() const { return z_; }

    /// @brief ���õ��x����
    /// @param[in]      x               x����
    void setX(double x) { x_ = x; }

    /// @brief ���õ��y����
    /// @param[in]      y               y����
    void setY(double y) { y_ = y; }

    /// @brief ���õ��z����
    /// @param[in]      z               z����
    void setZ(double z) { z_ = z; }

    /// @brief ��ȡ����һ����ľ���
    /// @param[in]      point           ��һ����
    /// @return         ����֮��ľ���
    double DistanceTo(const Point3D& point) const;

    /// @brief ����=�����
    /// @param[in]      point           ��һ����
    /// @return         ��ǰ��
    Point3D& operator=(const Point3D& point);

    /// @brief ����==�����
    /// @param[in]      point           ��һ����
    /// @return         �����Ƿ����
    bool operator==(const Point3D& point) const;

private:

    /// @brief �������
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