#pragma once
#include <vector>
#include <memory>
#include "task.h"

class FileManager {
public:
    static void saveToCSV(const string& filename, const vector<unique_ptr<Task>>& tasks);
    static vector<unique_ptr<Task>> loadFromCSV(const string& filename);
};