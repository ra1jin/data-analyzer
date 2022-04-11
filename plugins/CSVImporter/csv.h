#ifndef CSV_H
#define CSV_H

#include <vector>
#include <string>

typedef std::vector<std::string> v_string;

class CSV
{
public:
    CSV();
    CSV(std::string filename);

    bool                                load(std::string filename);

    const std::vector<v_string> &       getData() const;
    int                                 getFieldId(std::string name) const;

public:
    std::vector<v_string>               parseLine(std::string line, char token = ';', char subtoken = '#');
    void                                duplicate(const std::vector<v_string> & in, std::vector<v_string> & out, v_string tmp = {}, int x = 0);

private:
    std::vector<v_string>               m_data;
    v_string                            m_fields;
};

#endif // CSV_H
