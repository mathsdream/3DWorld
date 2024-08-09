///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: ExporterBase.h
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
enum class ExporterType
{
    OBJ,
};

class ExporterBase
{

public:
    
    /// @brief ���캯��
    /// @param[in]      model           ģ��ָ��
    /// @param[in]      type            ����������
    ExporterBase(std::shared_ptr<Model3D> model, const ExporterType type)
        : model_(model), type_(type)
    {}

    /// @brief ����ģ��
    /// @param[in]      path            �ļ�·��
    virtual void Export(const std::string& path) = 0;
    
    /// @brief ������ģ��ָ��
    std::shared_ptr<Model3D> model_;

    /// @brief Exporter����
    const ExporterType type_;

};