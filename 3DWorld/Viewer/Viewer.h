#include "../Controller/controller.h"

class Viewer
{

public:

    Viewer(std::shared_ptr<Controller> controller)
        : controller_(controller)
    {}

    void MainWindow() const
    {
        while (true)
        {
            std::cout << "Please input the selection:" << std::endl;
            std::cout << "1. Import a model" << std::endl;
            std::cout << "2. Print the model" << std::endl;

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
            default:
                break;
            }
        }
    }



    /// @brief ¿ØÖÆÆ÷
    std::shared_ptr<Controller> controller_;

};