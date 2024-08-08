///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: Point3D.h
/// ���ߣ�mathsdream
/// 
/// ��Ҫ˵����
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <vector>

/// @brief ��Ľӿڣ������ռ��е�һ����
class Point3D
{

public:

    /// @brief ���캯��
    /// @param[in]      x               ���x����
    /// @param[in]      y               ���y����
    /// @param[in]      z               ���z����
    Point3D(double x, double y, double z)
        : x_(x), y_(y), z_(z)
    {}

    /// @brief ��ȡ����һ����ľ���
    /// @param[in]      point           ��һ����
    double DistanceTo(const Point3D& point) const
    {
        return sqrt((x_ - point.x_) * (x_ - point.x_) +
            (y_ - point.y_) * (y_ - point.y_) +
            (z_ - point.z_) * (z_ - point.z_));
    }

    /// @brief ����==�����
    bool operator==(const Point3D& point) const
    {
        return x_ == point.x_ && y_ == point.y_ && z_ == point.z_;
    }

private:

    /// @brief �������
    double x_, y_, z_;

};