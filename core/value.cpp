#include "value.h"

#include <iostream>
#include <sstream>

Value::Value() : m_type(Type::UNDEFINED)
{}

Value::Value(int value)
{
    setValue(value);
}

Value::Value(double value)
{
    setValue(value);
}

Value::Value(bool value)
{
    setValue(value);
}

Value::Value(std::string value)
{
    setValue(value);
}

void Value::setValue(std::string value)
{
    m_type = Type::VARCHAR;

    m_data.s = new char[value.size()];
    strcpy(m_data.s, value.c_str());
}

void Value::reset()
{
    m_data = Data();
    m_type = Type::UNDEFINED;
}

std::string Value::typeToStr() const
{
    std::stringstream type;

    if (m_type == Type::UNDEFINED) type << "undefined";
    if (m_type == Type::INTEGER)   type << "integer";
    if (m_type == Type::DOUBLE)    type << "double";
    if (m_type == Type::BOOLEAN)   type << "boolean";
    if (m_type == Type::VARCHAR)   type << "varchar";

    return type.str();
}

std::string Value::valueToStr() const
{
    std::stringstream value;

    if (m_type == Type::UNDEFINED) value << "null";
    if (m_type == Type::INTEGER)   value << m_data.i;
    if (m_type == Type::DOUBLE)    value << m_data.d;
    if (m_type == Type::BOOLEAN)   value << m_data.b;
    if (m_type == Type::VARCHAR)   value << m_data.s;

    return value.str();
}

bool operator == (const Value & a, const Value & b)
{
    if (a.m_type == Value::Type::INTEGER && b.m_type == Value::Type::INTEGER)
    {
        return a.m_data.i == b.m_data.i;
    }

    if (a.m_type == Value::Type::DOUBLE && b.m_type == Value::Type::DOUBLE)
    {
        return a.m_data.d == b.m_data.d;
    }

    if (a.m_type == Value::Type::BOOLEAN && b.m_type == Value::Type::BOOLEAN)
    {
        return a.m_data.b == b.m_data.b;
    }

    if (a.m_type == Value::Type::VARCHAR && b.m_type == Value::Type::VARCHAR)
    {
        return (strcmp(a.m_data.s, b.m_data.s) == 0);
    }

    return false;
}

std::ostream & operator << (std::ostream & out, const Value & v)
{
    out << v.toString();

    return out;
}
