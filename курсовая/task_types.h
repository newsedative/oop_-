// task_types.h
#pragma once
#include "task.h"

class RegularTask : public Task {
public:
    RegularTask(const string& desc, time_t due);
    void display() const override;
    string getType() const override;
};

class ImportantTask : public Task {
    int priority;
public:
    ImportantTask(const string& desc, time_t due, int prio);
    void display() const override;
    string getType() const override;
    int getPriority() const;
};

class RecurringTask : public Task {
    string frequency;
public:
    RecurringTask(const string& desc, time_t due, const string& freq);
    void display() const override;
    string getType() const override;
    string getFrequency() const;
};