// task.h
#pragma once
#include <string>
#include <ctime>

using namespace std;

class Task {
protected:
    string description;
    time_t dueDate;
    bool completed;

public:
    Task(const string& desc, time_t due);
    virtual ~Task() = default;

    // ����� ����������� �������
    virtual void display() const = 0;
    virtual string getType() const = 0;

    // ����� ������
    void markCompleted();
    bool isCompleted() const;
    string getDescription() const;
    time_t getDueDate() const;
    string getDueDateString() const;
};