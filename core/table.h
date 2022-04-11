#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>

#include "entry.h"
#include "property.h"

class Table
{
public:
    Table();
    Table(std::string name, std::vector<Property> properties);

    std::string                 getName() const         { return m_name; }
    std::vector<Property>       getProperties() const   { return m_properties; }

    int                         getPropertyId(Property) const;

    int                         addEntry(Entry);

    void                        print(std::ostream &, bool debug = false);
    bool                        save(std::string filename);

private:
    bool                        isValidEntry(Entry);

private:
    std::string                 m_name;
    std::vector<Property>       m_properties;
    std::vector<Entry>          m_entries;
};

#endif // TABLE_H
