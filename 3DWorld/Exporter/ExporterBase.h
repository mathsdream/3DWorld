///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: ExporterBase.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.该文件为提供的一个导出器的接口的基类，用于导出3D模型
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------


#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "../Interface/Model3D.h"

/// @brief 导出器的类型
enum class ExporterType
{
    OBJ,
};

class ExporterBase
{

public:
    
    /// @brief 构造函数
    /// @param[in]      model           模型指针
    /// @param[in]      type            导出器类型
    ExporterBase(std::shared_ptr<Model3D> model, const ExporterType type)
        : model_(model), type_(type)
    {}

    /// @brief 导出模型
    /// @param[in]      path            文件路径
    virtual void Export(const std::string& path) = 0;
    
    /// @brief 导出的模型指针
    std::shared_ptr<Model3D> model_;

    /// @brief Exporter类型
    const ExporterType type_;

};