///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: ImporterBase.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.该文件为提供的一个导入器的接口的基类，用于导入3D模型
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "../Interface/Model3D.h"

/// @brief 导入器的类型
enum class ImporterType
{
    OBJ,
};

class ImporterBase
{

public:

    /// @brief 构造函数
    /// @param[in]      model           模型指针
    /// @param[in]      type            导入器类型
    ImporterBase(std::shared_ptr<Model3D> model, const ImporterType type)
        : model_(model), type_(type)
    {}

    /// @brief 导入模型
    /// @param[in]      path            文件路径
    virtual void Import(const std::string& path) = 0;
    
    /// @brief 导入的模型指针
    std::shared_ptr<Model3D> model_ = nullptr;

    /// @brief Importer类型
    const ImporterType type_;
};