#include "../Controller/controller.h"

class Viewer
{

public:

    Viewer(std::shared_ptr<Controller> controller)
        : controller_(controller)
    {}

    /// @brief 主窗口内容显示
    void MainWindow() const
    {
        while (true)
        {
            std::cout << "Please input the selection:" << std::endl;
            std::cout << "1. Import a model" << std::endl;
            std::cout << "2. Print the model" << std::endl;
            std::cout << "3. Modify the model" << std::endl;

            int selection;
            std::cin >> selection;
            switch (selection)
            {
            case 1:
            {
                std::string path;
                std::cout << "Please input the path of the model: " << std::endl;
                std::cin >> path;
                controller_->Import(path);
                break;
            }
            case 2:
            {
                controller_->PrintModel();
                break;
            }
            case 3:
            {
                ModifyModelWindow();
                break;
            }
            default:
                break;
            }
        }
    }

    /// @brief 修改模型子窗口
    void ModifyModelWindow() const
    {
        while (true)
        {
            std::cout << "Please input the selection:" << std::endl;
            std::cout << "1. Add a point" << std::endl;
            std::cout << "2. Add a line" << std::endl;
            std::cout << "3. Add a face" << std::endl;
            std::cout << "4. Modify a point" << std::endl;
            std::cout << "5. Modify a line" << std::endl;
            std::cout << "6. Modify a face" << std::endl;
            std::cout << "7. Remove a point( and " << std::endl;
            std::cout << "8. Remove a line" << std::endl;
            std::cout << "9. Remove a face" << std::endl;
            std::cout << "10. Exit" << std::endl;

            int selection;
            std::cin >> selection;
            switch (selection)
            {
            case 1:
            {
                std::cout << "Please input the position of the point: " << std::endl;
                double x, y, z;
                std::cin >> x >> y >> z;
                controller_->AddPoint(x, y, z);
                break;
            }
            case 10:
                return;
            default:
                break;
            }
        }
    }


    /// @brief 控制器
    std::shared_ptr<Controller> controller_;

};