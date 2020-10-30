#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Global vars
vector<float> file_data;
time_t last_update = 0;

//Prototypes
bool read_data(const string& file);
void sort_data(vector<float>&);
void cleaning_data(vector<float>& vec);
float simple_moving_average();
bool check_change(const string& file);

bool read_data(const string& file_loc) {
    file_data.clear();
    string s;
    ifstream file(file_loc);
    if (file) {
        struct stat result;
        if (stat(file_loc.c_str(), &result) == 0) last_update = result.st_mtime;

        while (file >> s)
        {
            file_data.push_back(stof(s));
        }
        sort_data(file_data);
        for (int i = 0; i < file_data.size() - 1; i++) printf("[%d] Value: %.4f\n", i, file_data[i]);
        return true;
    }
	return false;
}

void sort_data(vector<float> &vec) {
    sort(vec.begin(), vec.end());
}

void cleaning_data(vector<float>& vec) {
    // What should be cleaned?
}

float simple_moving_average() {
    float average = 0;

    for (auto iter : file_data) {
        average += iter;
    }

    return average /= file_data.size();
}

bool check_change (const string &file) {
    struct stat result;
    if (stat(file.c_str(), &result) != 0) return false;
    if (result.st_mtime == last_update) return false;
    return true;
}