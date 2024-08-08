#pragma once
#include <stdexcept>
#include <vector>
#include <set>
#include "Point3D.h"

class Line3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Line3D()
    {
        points_.reserve(2);
    }

    /// @brief ���캯��
    /// @param[in]      point1,point2       �߶ε������˵�
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

    /// @brief ��ȡ�߶εĶ˵�
    /// @return         �߶εĶ˵�
    std::vector<Point3D> GetPoints() const { return points_; }

    /// @brief �����߶ε�����һ���˵�
    /// @param[in]      point           �˵�
    /// @param[in]      index           �˵������
    /// @return         �Ƿ����óɹ�
    bool SetPoint(Point3D point, int index = 0);

    /// @brief ��ȡ�߶εĳ���
    /// @return         �߶εĳ���
    double GetLength() const;

    /// @brief ����=�����
    /// @param[in]      line            ��һ���߶�
    /// @return         ��ǰ�߶�
    Line3D& operator=(const Line3D& line);

    /// @brief ����==�����
    /// @param[in]      line            ��һ���߶�
    /// @return         �Ƿ����
    bool operator==(const Line3D& line) const;

private:

    /// @brief �߶εĶ˵�
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
