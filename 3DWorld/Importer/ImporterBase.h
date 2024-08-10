///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: ImporterBase.h
/// ���ߣ�mathdream
/// 
/// ��Ҫ˵����
/// 1.���ļ�Ϊ�ṩ��һ���������ĽӿڵĻ��࣬���ڵ���3Dģ��
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "../Interface/Model3D.h"

/// @brief ������������
enum class ImporterType
{
    OBJ,
};

class ImporterBase
{

public:

    /// @brief ���캯��
    /// @param[in]      model           ģ��ָ��
    /// @param[in]      type            ����������
    ImporterBase(std::shared_ptr<Model3D> model, const ImporterType type)
        : model_(model), type_(type)
    {}

    /// @brief ����ģ��
    /// @param[in]      path            �ļ�·��
    virtual void Import(const std::string& path) = 0;
    
    /// @brief �����ģ��ָ��
    std::shared_ptr<Model3D> model_ = nullptr;

    /// @brief Importer����
    const ImporterType type_;
};