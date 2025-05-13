// planner.cpp
#include "planner.h"
#include <iostream>
#include "file_manager.h"
#include "task_types.h"

void DailyPlanner::addTask(unique_ptr<Task> task) {
    tasks.push_back(move(task));
}

void DailyPlanner::displayAllTasks() const {
    if (tasks.empty()) {
        cout << "���������� ����." << endl;
        return;
    }

    cout << "��� ������ (" << tasks.size() << "):" << endl;
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
    cout << "���������� ������ ��� \"" << keyword << "\":" << endl;
    bool found = false;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i]->getDescription().find(keyword) != string::npos) {
            cout << i << ". ";
            tasks[i]->display();
            found = true;
        }
    }

    if (!found) {
        cout << "������ �� �������." << endl;
    }
}

size_t DailyPlanner::getTaskCount() const {
    return tasks.size();
}

const Task& DailyPlanner::getTask(size_t index) const {
    return *tasks[index];
}

void DailyPlanner::saveToFile(const string& filename) const {
    FileManager::saveToCSV(filename, tasks);
}

void DailyPlanner::loadFromFile(const string& filename) {
    tasks = FileManager::loadFromCSV(filename);
}

void DailyPlanner::editTask(size_t index) {
    if (index >= tasks.size()) return;

    Task* task = tasks[index].get();
    cout << "�������������� ������: ";
    task->display();

    cout << "������� ����� �������� (�������� ������, ����� �� ������): ";
    string newDesc;
    getline(cin, newDesc);
    if (!newDesc.empty()) {
        task->setDescription(newDesc);
    }

    cout << "������� ����� ���� (���� ����� ���, ��� 0 ����� �� ������): ";
    int day, month, year;
    if (cin >> day && day != 0) {
        cin >> month >> year;
        tm timeinfo = { 0 };
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        time_t newDue = mktime(&timeinfo);
        if (newDue != -1) {
            task->setDueDate(newDue);
        }
    }
    cin.ignore();

    // ��� ������ ����� - ��������� ����������
    if (task->getType() == "������ ������") {
        ImportantTask* importantTask = dynamic_cast<ImportantTask*>(task);
        if (importantTask) {
            cout << "������� ����� ��������� (1-10, ��� 0 ����� �� ������): ";
            int newPrio;
            if (cin >> newPrio && newPrio != 0) {
                importantTask->setPriority(newPrio);
            }
            cin.ignore();
        }
    }

    // ��� ������������� ����� - ��������� �������
    if (task->getType() == "������������� ������") {
        RecurringTask* recurringTask = dynamic_cast<RecurringTask*>(task);
        if (recurringTask) {
            cout << "������� ����� ������� (��������� - 1/����������� - 2/���������� - 3, ��� 0 ����� �� ������): ";
            string newFreq;
            getline(cin, newFreq);
            if (newFreq == "1") {
                recurringTask->setFrequency("���������");
            }
            else if (newFreq == "2") {
                recurringTask->setFrequency("�����������");
            }
            else if (newFreq == "3") {
                recurringTask->setFrequency("����������");
            }
        }
    }
}