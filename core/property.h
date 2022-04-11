#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "value.h"

class Property
{
public:
    enum Role { VALUE, PRIMARY_KEY, FOREIGN_KEY };

    Property(std::string name, Value::Type type = Value::Type::INTEGER, Property::Role role = Role::VALUE);

    std::string     getName() const;
    Value::Type     getValueType() const;
    Role            getRole() const;

    friend bool operator == (const Property & a, const Property & b);

private:
    std::string     m_name;
    Value::Type     m_type;
    Role            m_role;
};

#endif // PROPERTY_H
