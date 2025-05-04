// task_types.cpp
#include "task_types.h"
#include <iostream>

RegularTask::RegularTask(const string& desc, time_t due)
    : Task(desc, due) {}

void RegularTask::display() const {
    cout << "[Обычная] " << description << " (до: " << getDueDateString();
    cout << ") - " << (isCompleted() ? "Выполнено" : "Не выполнено") << endl;
}

string RegularTask::getType() const {
    return "Обычная задача";
}

ImportantTask::ImportantTask(const string& desc, time_t due, int prio)
    : Task(desc, due), priority(prio) {}

void ImportantTask::display() const {
    cout << "[Важная] " << description << " (приоритет: " << priority;
    cout << ", до: " << getDueDateString() << ") - ";
    cout << (isCompleted() ? "Выполнено" : "Не выполнено") << endl;
}

string ImportantTask::getType() const {
    return "Важная задача";
}

int ImportantTask::getPriority() const {
    return priority;
}

RecurringTask::RecurringTask(const string& desc, time_t due, const string& freq)
    : Task(desc, due), frequency(freq) {}

void RecurringTask::display() const {
    cout << "[Повторяющаяся] " << description << " (частота: " << frequency;
    cout << ", до: " << getDueDateString() << ") - ";
    cout << (isCompleted() ? "Выполнено" : "Не выполнено") << endl;
}

string RecurringTask::getType() const {
    return "Повторяющаяся задача";
}

string RecurringTask::getFrequency() const {
    return frequency;
}
