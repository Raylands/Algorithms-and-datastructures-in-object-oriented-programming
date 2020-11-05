#pragma once
#include "Global.hpp"

using namespace std;

// Global vars
extern time_t last_update;

namespace Deque {
    // Local vars
    deque<float> file_data;

    // Prototypes
    bool read_data(const string&, bool, int);
    float simple_moving_average(const deque<float>&, int);

    bool read_data(const string& file_loc, bool every_step = true, int filter_size = 0) {
        while (!file_data.empty())
            file_data.pop_front();
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

            printf("Overall SMA: %.4f\n", simple_moving_average(file_data, filter_size));
            return true;
        }
        return false;
    }

    float simple_moving_average(const deque<float>& que, int filter_size = 0) {
        float average = 0;

        //Bad for performance, but otherwise loss of original data
        deque<float> file_data_copy = que;

        if (filter_size == 0)
            filter_size = que.size();

        for (int i = 0; i < filter_size; i++) {
            average += file_data_copy.back();
            file_data_copy.pop_back();
        }

        return average /= filter_size;
    }
}