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
/// ͬʱÿ���㡢�߶Ρ������Ÿ��Ե������ţ��ֱ��1��ʼ
class Model3D
{

public:

    /// @brief Ĭ�Ϲ��캯��
    Model3D() {};

    /// @brief ��ȡģ�͵�����
    /// @return         ����
    const std::string& GetName() const { return name_; }

    /// @brief ����ģ�͵�����
    /// @param[in]      name            ����
    void SetName(const std::string& name) {}

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

    /// @brief ����������ɾȥһ�����㣨����ص��߶κ��棩
    /// @param[in]      index           ������
    /// @return         �Ƿ�ɾ���ɹ�
    bool RemovePoint(int index);

    /// @brief ��ȡģ�͵Ķ���
    /// @return         ����
    auto GetPoints() const { return points_; }

    /// @brief ��ȡģ�͵��߶�
    /// @return         �߶�
    auto GetLines() const { return lines_; }

    /// @brief ��ȡģ�͵���
    /// @return         ��
    auto GetFaces() const { return faces_; }

    /// @brief ��ȡģ�͵Ķ�����
    /// @return         ������
    int GetPointCount() const { return points_.size(); }

    /// @brief ��ȡģ�͵��߶���
    /// @return         �߶���
    int GetLineCount() const { return lines_.size(); }

    /// @brief ��ȡģ�͵�����
    /// @return         ����
    int GetFaceCount() const { return faces_.size(); }

    /// @brief ��ȡ�߶ε��ܳ���
    /// @return         �ܳ���
    double GetTotalLength() const;

    /// @brief ��ȡ��������
    /// @return         �����
    double GetTotalArea() const;

private:

    /// @brief 3Dģ�͵Ķ���
    std::vector<Point3D> points_;

    /// @brief 3Dģ�͵��߶�
    std::vector<Line3D> lines_;

    /// @brief 3Dģ�͵���
    std::vector<Face3D> faces_;

    /// @brief 3Dģ�͵�����
    std::string name_;

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
            return i + 1;
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
            return i + 1;
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
            return i + 1;
    return -1;
}

inline bool Model3D::RemovePoint(int index)
{
    if (index < 1 || index > points_.size())
        return false;
    const Point3D point = points_[index - 1];
    points_.erase(points_.begin() + index - 1);
    for (int i = 0; i < lines_.size(); i++)
    {
        if (lines_[i].IsPointOfLine(point))
        {
            lines_.erase(lines_.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < faces_.size(); i++)
    {
        if (faces_[i].IsPointOfFace(point))
        {
            faces_.erase(faces_.begin() + i);
            i--;
        }
    }
    return true;
}

inline double Model3D::GetTotalLength() const
{
    double total_length = 0;
    for (const Line3D& line : lines_)
        total_length += line.GetLength();
    return total_length;
}

inline double Model3D::GetTotalArea() const
{
    double total_area = 0;
    for (const Face3D& face : faces_)
        total_area += face.GetArea();
    return total_area;
}