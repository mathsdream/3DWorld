///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: Model3D.h
/// ���ߣ�mathdream
/// 
/// ��Ҫ˵����
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------


#pragma once
#include "Point3D.h"
#include "Line3D.h"
#include "Face3D.h"

/// @brief 3Dodel�Ľӿڣ�����һ��3Dģ��
/// �������һϵ�еĶ��㡢�߶κ���
/// ͬʱÿ���㡢�߶Ρ������Ÿ��Ե�������
class Model3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Model3D() {};

    /// @brief ���һ������
    /// @param[in]      point           ����
    /// @return         �Ƿ���ӳɹ�������Ƿ����ظ��Ķ��㣩
    bool AddPoint(Point3D point);

    /// @brief ��ȡһ�����������
    /// @param[in]      point           ��
    /// @return         ��������ţ�����������򷵻�-1��
    int GetPointIndex(Point3D point) const;
    
    /// @brief ���һ���߶�
    /// ����߶ε�ĳ�˵㲻��ģ���У�������ӵ�ģ����
    /// @param[in]      line            �߶�
    /// @return         �Ƿ���ӳɹ�
    bool AddLine(Line3D line);

    /// @brief ��ȡһ���߶ε�������
    /// @param[in]      line            �߶�
    /// @return         �߶ε������ţ�����������򷵻�-1��
    int GetLineIndex(Line3D line) const;

    /// @brief ���һ����
    /// ������ĳ���㲻��ģ���У�������ӵ�ģ����
    /// @param[in]      face            ��
    /// @return         �Ƿ���ӳɹ�
    bool AddFace(Face3D face);

    /// @brief ��ȡһ�����������
    /// @param[in]      face            ��
    /// @return         ��������ţ�����������򷵻�-1��
    int GetFaceIndex(Face3D face) const;

private:

    /// @brief 3Dģ�͵Ķ���
    std::vector<Point3D> points_;

    /// @brief 3Dģ�͵��߶�
    std::vector<Line3D> lines_;

    /// @brief 3Dģ�͵���
    std::vector<Face3D> faces_;

};

inline bool Model3D::AddPoint(Point3D point)
{
    if (GetPointIndex(point) != -1)
        return false;
    points_.push_back(point);
    return true;
}

inline int Model3D::GetPointIndex(Point3D point) const
{
    for (int i = 0; i < points_.size(); i++)
        if (points_[i] == point)
            return i;
    return -1;
}

inline bool Model3D::AddLine(Line3D line)
{
    for (int i = 0; i < line.GetPoints().size(); i++)
        if (GetPointIndex(line.GetPoints()[i]) == -1)
            points_.push_back(line.GetPoints()[i]);
    if (GetLineIndex(line) != -1)
        return false;
    lines_.push_back(line);
    return true;
}

inline int Model3D::GetLineIndex(Line3D line) const
{
    for (int i = 0; i < lines_.size(); i++)
        if (lines_[i] == line)
            return i;
    return -1;
}

inline bool Model3D::AddFace(Face3D face)
{
    for (int i = 0; i < face.GetPoints().size(); i++)
        if (GetPointIndex(face.GetPoints()[i]) == -1)
            points_.push_back(face.GetPoints()[i]);
    if (GetFaceIndex(face) != -1)
        return false;
    faces_.push_back(face);
    return true;
}

inline int Model3D::GetFaceIndex(Face3D face) const
{
    for (int i = 0; i < faces_.size(); i++)
        if (faces_[i] == face)
            return i;
    return -1;
}