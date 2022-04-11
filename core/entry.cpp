#include "entry.h"

Entry::Entry()
{}

Entry::Entry(std::vector<Value> values) : m_values(values)
{}

void Entry::addValue(Value value)
{
    m_values.push_back(value);
}

int Entry::size() const
{
    return m_values.size();
}

Value Entry::operator [] (int index)
{
    return m_values[index];
}

bool operator == (const Entry & a, const Entry & b)
{
    return a.m_values == b.m_values;
}

std::ostream & operator << (std::ostream & out, const Entry & line)
{
    for (Value v : line.m_values)
    {
        out << v;
        out << std::string(";");
    }

    return out;
}
