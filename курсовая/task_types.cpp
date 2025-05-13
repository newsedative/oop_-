// task_types.cpp
#include "task_types.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

RegularTask::RegularTask(const string& desc, time_t due)
    : Task(desc, due) {}

void RegularTask::display() const {
    cout << "[�������] " << description << " (��: " << getDueDateString();
    cout << ") - " << (isCompleted() ? "���������" : "�� ���������") << endl;
}

string RegularTask::getType() const {
    return "������� ������";
}

string RegularTask::toCSV() const {
    return Task::toCSV();
}

void RegularTask::fromCSV(const string& csvLine) {
    Task::fromCSV(csvLine);
    istringstream ss(csvLine);
    string token;
    for (int i = 0; i < 4; i++) getline(ss, token, ';');
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

string ImportantTask::toCSV() const {
    return Task::toCSV() + ";" + to_string(priority);
}

void ImportantTask::fromCSV(const string& csvLine) {
    Task::fromCSV(csvLine);
    istringstream ss(csvLine);
    string token;
    for (int i = 0; i < 4; i++) getline(ss, token, ';');
    if (!token.empty()) priority = stoi(token);
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

string RecurringTask::toCSV() const {
    return Task::toCSV() + ";;" + frequency;
}

void RecurringTask::fromCSV(const string& csvLine) {
    Task::fromCSV(csvLine);
    istringstream ss(csvLine);
    string token;
    for (int i = 0; i < 5; i++) getline(ss, token, ';');
    frequency = token;
}

