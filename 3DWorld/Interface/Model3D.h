///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: Model3D.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------


#pragma once
#include "Point3D.h"
#include "Line3D.h"
#include "Face3D.h"

/// @brief 3Dodel的接口，描述一个3D模型
/// 其包含了一系列的顶点、线段和面
/// 同时每个点、线段、面有着各自的索引号
class Model3D
{

public:

    /// @brief 默认构造函数
    Model3D() {};

    /// @brief 添加一个顶点
    /// @param[in]      point           顶点
    /// @return         是否添加成功（检查是否有重复的顶点）
    bool AddPoint(Point3D point);

    /// @brief 获取一个点的索引号
    /// @param[in]      point           点
    /// @return         点的索引号（如果不存在则返回-1）
    int GetPointIndex(Point3D point) const;
    
    /// @brief 添加一条线段
    /// 如果线段的某端点不在模型中，则将其添加到模型中
    /// @param[in]      line            线段
    /// @return         是否添加成功
    bool AddLine(Line3D line);

    /// @brief 获取一条线段的索引号
    /// @param[in]      line            线段
    /// @return         线段的索引号（如果不存在则返回-1）
    int GetLineIndex(Line3D line) const;

    /// @brief 添加一个面
    /// 如果面的某顶点不在模型中，则将其添加到模型中
    /// @param[in]      face            面
    /// @return         是否添加成功
    bool AddFace(Face3D face);

    /// @brief 获取一个面的索引号
    /// @param[in]      face            面
    /// @return         面的索引号（如果不存在则返回-1）
    int GetFaceIndex(Face3D face) const;

private:

    /// @brief 3D模型的顶点
    std::vector<Point3D> points_;

    /// @brief 3D模型的线段
    std::vector<Line3D> lines_;

    /// @brief 3D模型的面
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