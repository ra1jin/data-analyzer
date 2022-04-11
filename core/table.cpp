#include "../common/utils.h"
#include "table.h"
#include "entry.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>

Table::Table()
{}

Table::Table(std::string name, std::vector<Property> properties) : m_name(name), m_properties(properties)
{}

int Table::getPropertyId(Property prop) const
{
    return Utils::indexOf<Property>(m_properties, prop);
}

int Table::addEntry(Entry entry)
{
    if (!isValidEntry(entry))
    {
        throw std::invalid_argument("Entry format not match !");
    }

    int index = Utils::indexOf<Entry>(m_entries, entry);

    if (index >= 0)
    {
        return index;
    }

    m_entries.push_back(entry);

    return m_entries.size() - 1;
}

bool Table::isValidEntry(Entry entry)
{
    if (entry.size() != m_properties.size())
    {
        return false;
    }

    for (int i = 0; i < entry.size(); i++)
    {
        if (entry[i].getType() != m_properties[i].getValueType())
        {
            return false;
        }
    }

    return true;
}

void Table::print(std::ostream & os, bool debug)
{
    for (unsigned i = 0; i < m_entries.size(); i++)
    {
        if (debug)
        {
            os << "[" << i << "] ";
        }

        os << m_entries[i] << std::endl;
    }
}

bool Table::save(std::string filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::trunc);

    if (file.is_open())
    {
        std::cout << "plouf";
        print(file, false);
        file.close();

        return true;
    }

    return false;
}
