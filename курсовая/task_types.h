// task_types.h
#pragma once
#include "task.h"

class RegularTask : public Task {
public:
    RegularTask() : Task("", time(nullptr)) {}
    RegularTask(const string& desc, time_t due);
    void display() const override;
    string getType() const override;
    string toCSV() const override;
    void fromCSV(const string& csvLine) override;
    void editTask();
};

class ImportantTask : public Task {
    int priority;
public:
    ImportantTask() : Task("", time(nullptr)), priority(0) {}
    ImportantTask(const string& desc, time_t due, int prio);
    void display() const override;
    string getType() const override;
    int getPriority() const;
    string toCSV() const override;
    void fromCSV(const string& csvLine) override;
    void setPriority(int newPrio) { priority = newPrio; }
};

class RecurringTask : public Task {
    string frequency;
public:
    RecurringTask() : Task("", time(nullptr)), frequency("ежедневно") {}
    RecurringTask(const string& desc, time_t due, const string& freq);
    void display() const override;
    string getType() const override;
    string getFrequency() const;
    string toCSV() const override;
    void fromCSV(const string& csvLine) override;
    void setFrequency(const string& newFreq) { frequency = newFreq; }
};