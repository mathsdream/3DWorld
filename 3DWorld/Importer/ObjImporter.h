///--------------------------------------------------------------------------------------------------------------------------------------------------
/// �ļ���: ObjImporter.h
/// ���ߣ�mathdream
/// 
/// ��Ҫ˵����
/// 1.OBJ�ļ�Ϊ����ASCII���ļ���������Ӣ���ַ���ÿ�б�ʾ����֮һ�����ݣ�
/// ������Ϊ1��#�ַ�����ʾע���У���ӿո񣬿ո��Ϊע�����ݣ����������з���
/// ������Ϊ1��v�ַ�����ʾ��ά�㡣��ӿո񣬿ո��Ϊ2����������ÿ��������֮����1���ո񣩣�֮��Ϊ���з���
/// ������Ϊ1��l�ַ�����ʾ�ռ��߶Ρ���ӿո񣬿ո��Ϊ2��������ÿ������֮����1���ո񣩣�֮���ǻ��з���������ʾ��ά�������ţ���ά�����ļ��г��ֵ��Ⱥ�˳����СΪ1����
/// ������Ϊ1��f�ַ�����ʾ�ռ������Ρ���ӿո񣬿ո��Ϊ3��������ÿ������֮����1���ո񣩣�֮���ǻ��з���������ʾ��ά�������ţ���ά�����ļ��г��ֵ��Ⱥ�˳����СΪ1����
/// ������Ϊ1��g�ַ�����ʾģ�����ơ���ӿո񣬿ո��Ϊһ�����ٰ����ո�������ַ�����֮��Ϊ���з���һ���ļ��н�������һ��g��ͷ���С�
/// OBJ�ļ�ͬʱ�������й���
/// ����v��ͷ���У�һ���������֣��Ҿ���������l��f��ͷ����֮ǰ��
/// ����l��ͷ���У�һ���������֡�
/// ����f��ͷ���У�һ���������֡�
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include "ImporterBase.h"

/// @brief Obj�����������ڵ���Obj��ʽ��3Dģ��
class ObjImporter : public ImporterBase
{

public:

    ObjImporter(std::shared_ptr<Model3D> model)
        : ImporterBase(model, ImporterType::OBJ)
    {}

    /// @brief ����ģ��
    /// @param[in]      path            �ļ�·��
    virtual void Import(const std::string& path) override;

};

inline void ObjImporter::Import(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::invalid_argument("The file is not open.");
    else
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (line[0] == 'v')
            {
                std::istringstream iss(line);
                char c;
                double x, y, z;
                iss >> c >> x >> y >> z;
                model_->AddPoint(Point3D(x, y, z));
            }
            else if (line[0] == 'l')
            {
                std::istringstream iss(line);
                char c;
                int index1, index2;
                iss >> c >> index1 >> index2;
                model_->AddLine(Line3D(model_->GetPoints()[index1 - 1],
                    model_->GetPoints()[index2 - 1]));
            }
            else if (line[0] == 'f')
            {
                std::istringstream iss(line);
                char c;
                int index1, index2, index3;
                iss >> c >> index1 >> index2 >> index3;
                model_->AddFace(Face3D(model_->GetPoints()[index1 - 1],
                    model_->GetPoints()[index2 - 1],
                    model_->GetPoints()[index3 - 1]));
            }
        }
    }
}