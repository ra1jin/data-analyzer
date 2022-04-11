#include "csvimporter.h"

#include <map>
#include <iostream>

CSVImporter::CSVImporter()
{}


CSVImporter::CSVImporter(std::string filename)
{
    m_csv.load(filename);
}


void CSVImporter::load(std::string filename)
{
    m_csv.load(filename);
}


void CSVImporter::createTable(std::string name, std::vector<Property> properties)
{
    m_tables.push_back(Table(name, properties));
}


void CSVImporter::process()
{
    for (std::vector<std::string> line : m_csv.getData())
    {
        std::map<std::string, int> primaryKeys;

        for (Table & table : m_tables)
        {
            Entry newEntry;

            for (Property prop : table.getProperties())
            {
                std::string propertyName = prop.getName();
                Property::Role propertyRole = prop.getRole();
                Value val;

                if (propertyRole == Property::Role::FOREIGN_KEY)
                {
                    if (primaryKeys.find(propertyName) == primaryKeys.end())
                    {
                        throw std::invalid_argument("Primary key not find !");
                    }

                    val = primaryKeys[propertyName];
                }
                else
                {
                    int numColumn = m_csv.getFieldId(propertyName);
                    val = line[numColumn];
                }

                newEntry.addValue(val);
            }

            primaryKeys["id" + table.getName()] = table.addEntry(newEntry);
        }
    }
}


Table CSVImporter::getTable(int index)
{
    return m_tables[index];
}
