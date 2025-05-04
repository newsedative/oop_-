// planner.cpp
#include "planner.h"
#include <iostream>

void DailyPlanner::addTask(unique_ptr<Task> task) {
    tasks.push_back(move(task));
}

void DailyPlanner::displayAllTasks() const {
    if (tasks.empty()) {
        cout << "Ежедневник пуст." << endl;
        return;
    }

    cout << "Все задачи (" << tasks.size() << "):" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i << ". ";
        tasks[i]->display();
    }
}

void DailyPlanner::markTaskCompleted(size_t index) {
    if (index < tasks.size()) {
        tasks[index]->markCompleted();
    }
}

void DailyPlanner::removeTask(size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void DailyPlanner::searchTasks(const string& keyword) const {
    cout << "Результаты поиска для \"" << keyword << "\":" << endl;
    bool found = false;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i]->getDescription().find(keyword) != string::npos) {
            cout << i << ". ";
            tasks[i]->display();
            found = true;
        }
    }

    if (!found) {
        cout << "Задачи не найдены." << endl;
    }
}

size_t DailyPlanner::getTaskCount() const {
    return tasks.size();
}

const Task& DailyPlanner::getTask(size_t index) const {
    return *tasks[index];
}