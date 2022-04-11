#ifndef CSVIMPORTER_H
#define CSVIMPORTER_H

#include <vector>

#include "../../core/table.h"
#include "csv.h"

class CSVImporter
{
public:
    CSVImporter();
    CSVImporter(std::string filename);

    void                  load(std::string filename);
    void                  process();

    void                  createTable(std::string name, std::vector<Property> properties);
    Table                 getTable(int index);

private:
    std::vector<Table>    m_tables;
    CSV                   m_csv;
};

#endif // CSVIMPORTER_H
