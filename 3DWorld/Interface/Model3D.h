#pragma once
#include "Point3D.h"
#include "Line3D.h"
#include "Face3D.h"

/// @brief 3Dodel�Ľӿڣ�����һ��3Dģ��
class Model3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Model3D() {};

    /// @brief ���һ������
    /// @param[in]      point           ����
    /// @return         �Ƿ���ӳɹ�������Ƿ����ظ��Ķ��㣩
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

    /// @brief ���һ���߶�

private:

    /// @brief 3Dģ�͵Ķ���
    std::vector<Point3D> points_;

    /// @brief 3Dģ�͵��߶�
    std::vector<Line3D> lines_;

    /// @brief 3Dģ�͵���
    std::vector<Face3D> faces_;

};
