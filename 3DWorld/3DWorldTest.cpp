#include "Interface/Model3D.h"
#include "Importer/ObjImporter.h"
#include "Exporter/ObjExporter.h"
#include "Viewer/Viewer.h"

/// 一个程序，允许用户随意输入点、线、面，然后可以输出模型的点线面信息
int main()
{
    std::shared_ptr<Model3D> model;
    std::shared_ptr<Controller> controller = std::make_shared<Controller>(model);
    Viewer view(controller);
    view.MainWindow();
    return 0;
}

//Model3D model;
//while (true)
//{
//    std::cout << "Please select a option: " << std::endl;
//    std::cout << "1. Add a point" << std::endl;
//    std::cout << "2. Add a line (by coordinate)" << std::endl;
//    std::cout << "3. Add a face (by coordinate)" << std::endl;
//    std::cout << "4. Add a line (by index)" << std::endl;
//    std::cout << "5. Add a face (by index)" << std::endl;
//    std::cout << "6. Print the model" << std::endl;
//    std::cout << "7. Exit" << std::endl;
//    int option;
//    std::cin >> option;
//    switch (option)
//    {
//    case 1:
//    {
//        double x, y, z;
//        std::cout << "Please input the x, y, z of the point: " << std::endl;
//        std::cin >> x >> y >> z;
//        Point3D point(x, y, z);
//        if (!model.AddPoint(point))
//        {
//            std::cerr << "The point is already in the model." << std::endl;
//        }
//        break;
//    }
//    case 2:
//    {
//        double x1, y1, z1, x2, y2, z2;
//        std::cout << "Please input the x, y, z of the first point of the line: " << std::endl;
//        std::cin >> x1 >> y1 >> z1;
//        std::cout << "Please input the x, y, z of the second point of the line: " << std::endl;
//        std::cin >> x2 >> y2 >> z2;
//        Line3D line(Point3D(x1, y1, z1), Point3D(x2, y2, z2));
//        if (!model.AddLine(line))
//        {
//            std::cerr << "The line is already in the model." << std::endl;
//        }
//        break;
//    }
//    case 3:
//    {
//        double x1, y1, z1, x2, y2, z2, x3, y3, z3;
//        std::cout << "Please input the x, y, z of the first point of the face: " << std::endl;
//        std::cin >> x1 >> y1 >> z1;
//        std::cout << "Please input the x, y, z of the second point of the face: " << std::endl;
//        std::cin >> x2 >> y2 >> z2;
//        std::cout << "Please input the x, y, z of the third point of the face: " << std::endl;
//        std::cin >> x3 >> y3 >> z3;
//        Face3D face(Point3D(x1, y1, z1), Point3D(x2, y2, z2), Point3D(x3, y3, z3));
//        if (!model.AddFace(face))
//        {
//            std::cerr << "The face is already in the model." << std::endl;
//        }
//        break;
//    }
//    case 4:
//    {
//        int index1, index2;
//        std::cout << "Please input the index of the two points of the line: " << std::endl;
//        std::cin >> index1 >> index2;
//        if (index1 < 0 || index1 >= model.GetPointCount() ||
//            index2 < 0 || index2 >= model.GetPointCount())
//        {
//            std::cerr << "The index is out of range." << std::endl;
//            break;
//        }
//        Line3D line(model.GetPoints()[index1], model.GetPoints()[index2]);
//        if (!model.AddLine(line))
//        {
//            std::cerr << "The line is already in the model." << std::endl;
//        }
//        break;
//    }
//    case 5:
//    {
//        int index1, index2, index3;
//        std::cout << "Please input the index of the three points of the face: " << std::endl;
//        std::cin >> index1 >> index2 >> index3;
//        if (index1 < 0 || index1 >= model.GetPointCount() ||
//            index2 < 0 || index2 >= model.GetPointCount() ||
//            index3 < 0 || index3 >= model.GetPointCount())
//        {
//            std::cerr << "The index is out of range." << std::endl;
//            break;
//        }
//        Face3D face(model.GetPoints()[index1],
//            model.GetPoints()[index2],
//            model.GetPoints()[index3]);
//        if (!model.AddFace(face))
//        {
//            std::cerr << "The face is already in the model." << std::endl;
//        }
//        break;
//    }
//    case 6:
//    {
//        for (int i = 0; i < model.GetPoints().size(); i++)
//        {
//            std::cout << "Point " << i << ": " <<
//                model.GetPoints()[i].getX() << " " <<
//                model.GetPoints()[i].getY() << " " <<
//                model.GetPoints()[i].getZ() << std::endl;
//        }
//        for (int i = 0; i < model.GetLines().size(); i++)
//        {
//            std::cout << "Line " << i << ": " <<
//                model.GetPointIndex(model.GetLines()[i].GetPoints()[0]) << " " <<
//                model.GetPointIndex(model.GetLines()[i].GetPoints()[1]) << std::endl;
//        }
//        for (int i = 0; i < model.GetFaces().size(); i++)
//        {
//            std::cout << "Face " << i << ": " <<
//                model.GetPointIndex(model.GetFaces()[i].GetPoints()[0]) << " " <<
//                model.GetPointIndex(model.GetFaces()[i].GetPoints()[1]) << " " <<
//                model.GetPointIndex(model.GetFaces()[i].GetPoints()[2]) << std::endl;
//        }
//        std::cout << "The count of points is " << model.GetPointCount() << std::endl;
//        std::cout << "The count of lines is " << model.GetLineCount() << std::endl;
//        std::cout << "The count of faces is " << model.GetFaceCount() << std::endl;
//        std::cout << "The total length of lines is " << model.GetTotalLength() << std::endl;
//        std::cout << "The total area of faces is " << model.GetTotalArea() << std::endl;
//        break;
//    }
//    case 7:
//        return 0;
//    default:
//        std::cerr << "Invalid option." << std::endl;
//        break;
//    }
//
//}