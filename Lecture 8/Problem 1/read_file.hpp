#pragma once
#include "Global.hpp"

void read_data(const string& file_loc)
{
    string s;
    ifstream file(file_loc);
    if (file) {
        while (file >> s)
        {
            transform(s.begin(), s.end(), s.begin(), tolower);
            s.erase(std::remove(s.begin(), s.end(), ','), s.end());
            s.erase(std::remove(s.begin(), s.end(), '.'), s.end());
            s.erase(std::remove(s.begin(), s.end(), '!'), s.end());
            s.erase(std::remove(s.begin(), s.end(), ':'), s.end());
            s.erase(std::remove(s.begin(), s.end(), '?'), s.end());
            
            if (data_map.count(s) > 0)
                data_map.at(s) += 1;
            else
                data_map.insert(std::pair<string, int>(s, 1));
        }
    }
}