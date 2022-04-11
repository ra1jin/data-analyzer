#include "property.h"
#include "value.h"

Property::Property(std::string name, Value::Type type, Role role) :
    m_name(name),
    m_type(type),
    m_role(role)
{}

std::string Property::getName() const
{
    return m_name;
}

Value::Type Property::getValueType() const
{
    return m_type;
}

Property::Role Property::getRole() const
{
    return m_role;
}

bool operator == (const Property & a, const Property & b)
{
    return a.m_name == b.m_name;
}
