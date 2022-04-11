#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <cstring>
#include <assert.h>

class Value
{
public:
    union Data
    {
        int	i;
        double d;
        bool b;
        char *s;
    };

    enum Type { UNDEFINED, INTEGER, DOUBLE, BOOLEAN, VARCHAR };

    Value();
    Value(int value);
    Value(double value);
    Value(bool value);
    Value(std::string value);

    void                    setValue(int value)         { m_type = Type::INTEGER; m_data.i = value; }
    void                    setValue(double value)      { m_type = Type::DOUBLE;  m_data.d = value; }
    void                    setValue(bool value)        { m_type = Type::BOOLEAN; m_data.b = value; }
    void                    setValue(std::string value);

    Type                    getType()   { return m_type; }

    int &                   getInt()    { assert(m_type == Type::INTEGER); return m_data.i; }
    double &                getDouble() { assert(m_type == Type::DOUBLE);  return m_data.d; }
    bool &                  getBool()   { assert(m_type == Type::BOOLEAN); return m_data.b; }
    char *                  getString() { assert(m_type == Type::VARCHAR); return m_data.s; }

    std::string             toString() const { return valueToStr(); }

    void                    reset();

    friend std::ostream &   operator << (std::ostream & out, const Value & v);
    friend bool             operator == (const Value & a, const Value & b);

public:
    std::string             typeToStr() const;
    std::string             valueToStr() const;

private:
    Data                    m_data;
    Type                    m_type;
};

#endif // VALUE_H
