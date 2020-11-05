#pragma once

#include <chrono>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <deque>

time_t last_update = 0;

bool check_change(const std::string& file) {
    struct stat result;
    if (stat(file.c_str(), &result) != 0) return false;
    if (result.st_mtime == last_update) return false;
    return true;
}