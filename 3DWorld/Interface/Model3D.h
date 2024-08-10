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
/// 同时每个点、线段、面有着各自的索引号，分别从1开始
class Model3D
{

public:

    /// @brief 默认构造函数
    Model3D() {};

    /// @brief 获取模型的名称
    /// @return         名称
    const std::string& GetName() const { return name_; }

    /// @brief 设置模型的名称
    /// @param[in]      name            名称
    void SetName(const std::string& name) {}

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

    /// @brief 根据索引号删去一个顶点（及相关的线段和面）
    /// @param[in]      index           索引号
    /// @return         是否删除成功
    bool RemovePoint(int index);

    /// @brief 获取模型的顶点
    /// @return         顶点
    auto GetPoints() const { return points_; }

    /// @brief 获取模型的线段
    /// @return         线段
    auto GetLines() const { return lines_; }

    /// @brief 获取模型的面
    /// @return         面
    auto GetFaces() const { return faces_; }

    /// @brief 获取模型的顶点数
    /// @return         顶点数
    int GetPointCount() const { return points_.size(); }

    /// @brief 获取模型的线段数
    /// @return         线段数
    int GetLineCount() const { return lines_.size(); }

    /// @brief 获取模型的面数
    /// @return         面数
    int GetFaceCount() const { return faces_.size(); }

    /// @brief 获取线段的总长度
    /// @return         总长度
    double GetTotalLength() const;

    /// @brief 获取面的总面积
    /// @return         总面积
    double GetTotalArea() const;

private:

    /// @brief 3D模型的顶点
    std::vector<Point3D> points_;

    /// @brief 3D模型的线段
    std::vector<Line3D> lines_;

    /// @brief 3D模型的面
    std::vector<Face3D> faces_;

    /// @brief 3D模型的名称
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