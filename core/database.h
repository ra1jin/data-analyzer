#ifndef DATABASE_H
#define DATABASE_H

#include "table.h"

class Database
{
public:
    Database();

    void                  createTable(std::string name, std::vector<Property> properties);
    Table                 getTable(int index);

private:
    std::vector<Table>    m_tables;
};

#endif // DATABASE_H
