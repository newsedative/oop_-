#include "file_manager.h"
#include "task_types.h"
#include <fstream>
#include <sstream>
#include <iostream>


vector<unique_ptr<Task>> FileManager::loadFromCSV(const string& filename) {
    vector<unique_ptr<Task>> tasks;
    ifstream file(filename);
    if (!file) return tasks;

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        istringstream ss(line);
        string type;
        getline(ss, type, ';');

        unique_ptr<Task> task;
        if (type == "Обычная задача") {
            task = make_unique<RegularTask>();
        }
        else if (type == "Важная задача") {
            task = make_unique<ImportantTask>();
        }
        else if (type == "Повторяющаяся задача") {
            task = make_unique<RecurringTask>();
        }

        if (task) {
            task->fromCSV(line);
            tasks.push_back(move(task));
        }
    }
    return tasks;
}

void FileManager::saveToCSV(const string& filename, const vector<unique_ptr<Task>>& tasks) {
    bool file_exists = ifstream(filename).peek() != ifstream::traits_type::eof();
    ofstream file(filename);
    if (!file) return;

    file << "Тип;Описание;Дата;Приоритет;Важность;СтепеньВыполнения\n";

    for (const auto& task : tasks) {
        file << task->toCSV() << "\n";
    }
}