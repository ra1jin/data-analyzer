#include <iostream>
#include "plugins/CSVImporter/csvimporter.h"

int main()
{
    CSVImporter importer;

    importer.load("C:/data.csv");

    importer.createTable("Periode",
    {
        Property("theme_s", Value::Type::VARCHAR)
    });

    try
    {
        importer.process();
    }
    catch (std::exception & e)
    {
        std::cerr << "Error during build tables process : " << e.what() << std::endl;
    }

    Table periode = importer.getTable(0);

    if (periode.save("test.csv"))
    {
        std::cout << "periode save";
    }

    return 0;
}
