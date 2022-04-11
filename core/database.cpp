#include "../common/utils.h"
#include "database.h"
#include "property.h"
#include "value.h"


#include <iostream>

Database::Database()
{}

void Database::createTable(std::string name, std::vector<Property> properties)
{
    m_tables.push_back(Table(name, properties));
}

Table Database::getTable(int index)
{
    return m_tables[index];
}
