#include "../Interface/Model3D.h"
#include "../Importer/ObjImporter.h"
#include "../Exporter/ObjExporter.h"

class Controller
{

public:

    Controller()
    {
        model_ = std::make_shared<Model3D>();
        importer_ = std::make_shared<ObjImporter>(model_);
        exporter_ = std::make_shared<ObjExporter>(model_);
    }

    Controller(std::shared_ptr<Model3D> model)
        : model_(model)
    {
        importer_ = std::make_shared<ObjImporter>(model_);
        exporter_ = std::make_shared<ObjExporter>(model_);
    }

    void Import(const std::string& path)
    {
        importer_->Import(path);
    }

    void PrintModel() const
    {
        std::cout << "Points: " << model_->GetPointCount() << std::endl;
        for (const auto& point : model_->GetPoints())
        {
            std::cout << point.getX() << " " << point.getY() << " " << point.getZ() << std::endl;
        }
        std::cout << "Lines: " << model_->GetLineCount() << std::endl;
        for (int i = 0; i < model_->GetLineCount(); i++)
        {
            std::cout << "Line " << i + 1 << std::endl;
            for (const auto& point : model_->GetLines()[i].GetPoints())
            {
                std::cout << point.getX() << " " << point.getY() << " " << point.getZ() << std::endl;
            }
        }
        std::cout << "Faces: " << model_->GetFaceCount() << std::endl;
        for (int i = 0; i < model_->GetFaceCount(); i++)
        {
            std::cout << "Face " << i + 1 << std::endl;
            for (const auto& point : model_->GetFaces()[i].GetPoints())
            {
                std::cout << point.getX() << " " << point.getY() << " " << point.getZ() << std::endl;
            }
        }
    }


private:

    /// @brief 3D模型
    std::shared_ptr<Model3D> model_;

    /// @brief 导入器
    std::shared_ptr<ImporterBase> importer_;

    /// @brief 导出器
    std::shared_ptr<ExporterBase> exporter_;

};