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

string Task::toCSV() const {
    ostringstream oss;
    oss << getType() << ";"
        << description << ";"
        << getDueDateString() << ";"
        << (isCompleted() ? "1" : "0");
    return oss.str();
}

void Task::fromCSV(const string& csvLine) {
    istringstream ss(csvLine);
    string token;

    getline(ss, token, ';'); 
    getline(ss, description, ';');

    getline(ss, token, ';');
    tm tm = {};
    istringstream dateStream(token);
    dateStream >> get_time(&tm, "%d.%m.%Y");
    dueDate = mktime(&tm);

    getline(ss, token);
    completed = (token == "1");
}