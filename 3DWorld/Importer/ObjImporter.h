///--------------------------------------------------------------------------------------------------------------------------------------------------
/// 文件名: ObjImporter.h
/// 作者：mathdream
/// 
/// 重要说明：
/// 1.OBJ文件为多行ASCII码文件，仅包含英文字符。每行表示下列之一的内容：
/// 若行首为1个#字符，表示注释行，后接空格，空格后为注释内容，持续到换行符。
/// 若行首为1个v字符，表示三维点。后接空格，空格后为2个浮点数（每个浮点数之后有1个空格），之后为换行符。
/// 若行首为1个l字符，表示空间线段。后接空格，空格后为2个整数（每个整数之后有1个空格），之后是换行符。整数表示三维点索引号（三维点在文件中出现的先后顺序，最小为1）。
/// 若行首为1个f字符，表示空间三角形。后接空格，空格后为3个整数（每个整数之后有1个空格），之后是换行符。整数表示三维点索引号（三维点在文件中出现的先后顺序，最小为1）。
/// 若行首为1个g字符，表示模型名称。后接空格，空格后为一个不再包含空格的连续字符串，之后为换行符。一个文件中仅仅包含一个g开头的行。
/// OBJ文件同时满足下列规则：
/// 所有v开头的行，一定连续出现，且均在所有以l和f开头的行之前。
/// 所有l开头的行，一定连续出现。
/// 所有f开头的行，一定连续出现。
/// 
///--------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once
#include "ImporterBase.h"

/// @brief Obj导入器，用于导入Obj格式的3D模型
class ObjImporter : public ImporterBase
{

public:

    ObjImporter(std::shared_ptr<Model3D> model)
        : ImporterBase(model, ImporterType::OBJ)
    {}

    /// @brief 导入模型
    /// @param[in]      path            文件路径
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