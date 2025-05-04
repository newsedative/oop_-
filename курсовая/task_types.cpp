// task_types.cpp
#include "task_types.h"
#include <iostream>

RegularTask::RegularTask(const string& desc, time_t due)
    : Task(desc, due) {}

void RegularTask::display() const {
    cout << "[�������] " << description << " (��: " << getDueDateString();
    cout << ") - " << (isCompleted() ? "���������" : "�� ���������") << endl;
}

string RegularTask::getType() const {
    return "������� ������";
}

ImportantTask::ImportantTask(const string& desc, time_t due, int prio)
    : Task(desc, due), priority(prio) {}

void ImportantTask::display() const {
    cout << "[������] " << description << " (���������: " << priority;
    cout << ", ��: " << getDueDateString() << ") - ";
    cout << (isCompleted() ? "���������" : "�� ���������") << endl;
}

string ImportantTask::getType() const {
    return "������ ������";
}

int ImportantTask::getPriority() const {
    return priority;
}

RecurringTask::RecurringTask(const string& desc, time_t due, const string& freq)
    : Task(desc, due), frequency(freq) {}

void RecurringTask::display() const {
    cout << "[�������������] " << description << " (�������: " << frequency;
    cout << ", ��: " << getDueDateString() << ") - ";
    cout << (isCompleted() ? "���������" : "�� ���������") << endl;
}

string RecurringTask::getType() const {
    return "������������� ������";
}

string RecurringTask::getFrequency() const {
    return frequency;
}
