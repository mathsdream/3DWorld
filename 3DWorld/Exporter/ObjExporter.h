///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: ObjExporter.h
/// ���ߣ�mathdream
/// 
/// ��Ҫ˵����
/// 1.
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------


#pragma once
#include "ExporterBase.h"

/// @brief Obj������
class ObjExporter : public ExporterBase
{

public:

    /// @brief ���캯��
    /// @param[in]      model           ģ��ָ��
    ObjExporter(std::shared_ptr<Model3D> model)
        : ExporterBase(model, ExporterType::OBJ)
    {}

    /// @brief ����ģ��
    /// @param[in]      path            �ļ�·��
    void Export(const std::string& path) override;

};

inline void ObjExporter::Export(const std::string& path)
{
    std::ofstream file(path);
    if (!file.is_open())
        throw std::invalid_argument("The file is not open.");
    else
    {
        file << "g " << model_->GetName() << std::endl;
        for (const auto& point : model_->GetPoints())
            file << "v " << point.getX() << " " << point.getY() << " " << point.getZ() << std::endl;
        for (const auto& line : model_->GetLines())
            file << "l " << model_->GetPointIndex(line.GetPoints()[0]) <<
            " " << model_->GetPointIndex(line.GetPoints()[1]) << std::endl;
        for (const auto& face : model_->GetFaces())
        {
            file << "f";
            for (const auto& point : face.GetPoints())
                file << " " << model_->GetPointIndex(point);
            file << std::endl;
        }
    }
    file.close();
}