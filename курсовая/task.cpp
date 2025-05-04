// task.cpp
#include "task.h"
#include <iomanip>
#include <sstream>

Task::Task(const string& desc, time_t due)
    : description(desc), dueDate(due), completed(false) {}

void Task::markCompleted() {
    completed = true;
}

bool Task::isCompleted() const {
    return completed;
}

string Task::getDescription() const {
    return description;
}

time_t Task::getDueDate() const {
    return dueDate;
}

string Task::getDueDateString() const {
    tm timeinfo;
    localtime_s(&timeinfo, &dueDate);
    char buffer[80];
    strftime(buffer, 80, "%d.%m.%Y", &timeinfo);
    return string(buffer);
}