#include "../../common/utils.h"
#include "csv.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

CSV::CSV()
{}

CSV::CSV(std::string filename)
{
    load(filename);
}

bool CSV::load(std::string filename)
{
    std::ifstream ifs;
    std::string str;

    ifs.open(filename, std::ifstream::in);

    if (!ifs.is_open())
    {
        std::cout << "Erreur de chargement du fichier !" << std::endl;
        return false;
    }

    std::getline(ifs, str);

    std::stringstream fieldstream(str);

    while (std::getline(fieldstream, str, ';'))
    {
        m_fields.push_back(str);
    }

    while (std::getline(ifs, str))
    {
        std::vector<v_string> lines = parseLine(str);

        for (v_string newLine : lines)
        {
            m_data.push_back(newLine);
        }
    }

    ifs.close();
    return true;
}

std::vector<v_string> CSV::parseLine(std::string line, char token, char subtoken)
{
    std::stringstream stream(line);
    std::string value;

    std::vector<v_string> splited;
    std::vector<v_string> out;

    while (std::getline(stream, value, token))
    {
        if (value.find(subtoken) != std::string::npos)
        {
            std::stringstream valuestream(value);
            v_string words;

            std::getline(valuestream, value, subtoken);

            while (std::getline(valuestream, value, subtoken))
            {
                words.push_back(value);
            }

            if (!words.empty())
            {
                splited.push_back(words);
            }
        }
        else
        {
            if (value.empty())
            {
                splited.push_back({});
            }
            else
            {
                splited.push_back({value});
            }
        }
    }

    duplicate(splited, out);

    return out;
}

void CSV::duplicate(const std::vector<v_string> & in, std::vector<v_string> & out, v_string line, int x)
{
    if (x < in.size())
    {
        for (int y = 0; y < in[x].size(); y++)
        {
            line.push_back(in[x][y]);

            if (x + 1 == in.size())
            {
                out.push_back(line);
            }
            else
            {
                duplicate(in, out, line, x + 1);
            }

            line.pop_back();
        }
    }

    return;
}

const std::vector<v_string> & CSV::getData() const
{
    return m_data;
}

int CSV::getFieldId(std::string name) const
{
    return Utils::indexOf<std::string>(m_fields, name);
}

