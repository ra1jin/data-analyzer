#ifndef ENTRY_H
#define ENTRY_H

#include <vector>
#include <string>
#include "value.h"

class Entry
{
public:
    Entry();
    Entry(std::vector<Value> values);

    void                    addValue(Value value);

    int                     size() const;

    Value                   operator [] (int index);
    friend bool             operator == (const Entry & a, const Entry & b);
    friend std::ostream &   operator << (std::ostream & out, const Entry & line);

private:
    std::vector<Value> m_values;
};

#endif // ENTRY_H
