#pragma once
#include <algorithm>

#include "Global.hpp"

using namespace std;

// Global vars
extern time_t last_update;

namespace Vector {
    // Local vars
    vector<float> file_data;

    // Prototypes
    bool read_data(const string& file, bool, bool, int);
    void sort_data(vector<float>&);
    float simple_moving_average(const vector<float>&, int);

    bool read_data(const string& file_loc, bool sort = true, bool every_step = true, int filter_size = 0) {
        file_data.clear();
        file_data.shrink_to_fit();
        string s;
        ifstream file(file_loc);
        if (file) {
            struct stat result;
            if (stat(file_loc.c_str(), &result) == 0) last_update = result.st_mtime;

            while (file >> s)
            {
                file_data.push_back(stof(s));

                if (every_step)
                    printf("[%d] SMA: %.4f\n", file_data.size(), simple_moving_average(file_data, filter_size));
            }

            if (sort)
                sort_data(file_data);

            printf("Overall SMA: %.4f\n", simple_moving_average(file_data, filter_size));
            return true;
        }
        return false;
    }

    void sort_data(vector<float>& vec) {
        sort(vec.begin(), vec.end());
    }

    float simple_moving_average(const vector<float>& vec, int filter_size = 0) {
        float average = 0;

        if (filter_size == 0)
            filter_size = vec.size();

        for (int i = vec.size() - 1; i >= vec.size() - filter_size; --i) {
            if (i == -1)
                break;
            average += vec[i];
        }

        return average /= filter_size;
    }
}