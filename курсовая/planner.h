// planner.h
#pragma once
#include "task.h"
#include <vector>
#include <memory>

class DailyPlanner {
    vector<unique_ptr<Task>> tasks;

public:
    void addTask(unique_ptr<Task> task);
    void displayAllTasks() const;
    void markTaskCompleted(size_t index);
    void removeTask(size_t index);
    void searchTasks(const string& keyword) const;
    size_t getTaskCount() const;
    const Task& getTask(size_t index) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void editTask(size_t index);
};