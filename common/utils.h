#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class Utils
{
public:
    template <typename T>
    static int indexOf(std::vector<T> tab, T search)
    {
        typename std::vector<T>::iterator it = std::find(tab.begin(), tab.end(), search);

        return (it != tab.end()) ? std::distance(tab.begin(), it) : -1;
    }

};

#endif // UTILS_H
