#include <iostream>
#include <memory>
#include "planner.h"
#include "task_types.h"
#include <Windows.h>
#include <ctime>
#include <limits>

using namespace std;

DailyPlanner planner;

enum MenuOption {
    ADD_TASK,
    DISPLAY_TASKS,
    MARK_COMPLETE,
    DELETE_TASK,
    SEARCH_TASK,
    EDIT_TASK,
    EXIT,
    OPTIONS_COUNT
};

struct MenuItem {
    const char* text;
    void (*action)();
};

time_t inputDate() {
    int day, month, year;
    tm timeinfo = { 0 };
    bool validDate = false;

    while (!validDate) {
        cout << "Введите дату (день месяц год): ";
        if (!(cin >> day >> month >> year)) {
            cout << "Ошибка: Введите дату (день месяц год): \n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();
        if (year < 1900 || year > 2100) {
            cout << "Ошибка: год должен быть между 1900 и 2100\n";
            continue;
        }
        if (month < 1 || month > 12) {
            cout << "Ошибка: месяц должен быть от 1 до 12\n";
            continue;
        }
        int maxDays;
        if (month == 2) {
            bool isLeap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
            maxDays = isLeap ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDays = 30;
        }
        else {
            maxDays = 31;
        }
        if (day < 1 || day > maxDays) {
            cout << "Ошибка: для " << month << "/" << year
                << " день должен быть от 1 до " << maxDays << "\n";
            continue;
        }
        validDate = true;
    }

    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;

    time_t result = mktime(&timeinfo);
    if (result == -1) {
        cerr << "Ошибка: некорректная дата\n";
        return -1;
    }
    return result;
}

void addTaskAction() {
    cout << "1. Добавить обычную задачу\n";
    cout << "2. Добавить важную задачу\n";
    cout << "3. Добавить повторяющуюся задачу\n";

    int task_type;
    cin >> task_type;
    cin.ignore();

    if (task_type == 1) {
        cout << "Введите описание задачи: ";
        string desc;
        getline(cin, desc);
        time_t due = inputDate();
        planner.addTask(make_unique<RegularTask>(desc, due));
        cout << "Задача добавлена.\n";
        return;
    }
    else if (task_type == 2)
    {
        cout << "Введите описание задачи: ";
        string desc;
        getline(cin, desc);
        time_t due = inputDate();
        cout << "Введите приоритет (1-10): ";
        int priority;
        cin >> priority;
        planner.addTask(make_unique<ImportantTask>(desc, due, priority));
        cout << "Задача добавлена.\n";
        return;
    }
    else if (task_type == 3)
    {
        cout << "Введите описание задачи: ";
        string desc;
        getline(cin, desc);
        time_t due = inputDate();
        cout << "Введите частоту (ежедневно - 1/еженедельно - 2/ежемесячно - 3): ";
        string freq;
        while (true) {
            getline(cin, freq);
            if (freq == "1" || freq == "2" || freq == "3") {
                break;
            }
            cout << "Ошибка: Введите частоту (ежедневно - 1/еженедельно - 2/ежемесячно - 3): ";
        }
        string frequency;
        if (freq == "1") {
            frequency = "ежедневно";
        }
        else if (freq == "2") {
            frequency = "еженедельно";
        }
        else {
            frequency = "ежемесячно";
        }
        planner.addTask(make_unique<RecurringTask>(desc, due, frequency));
        cout << "Задача добавлена.\n";
        return;
    }
}

void displayAllTasks() {
    planner.displayAllTasks();
    return;
}

void markTaskComplete() {
    if (planner.getTaskCount() > 0) {
        planner.displayAllTasks();
        cout << "Введите номер задачи: ";
        size_t index;
        cin >> index;
        planner.markTaskCompleted(index);
        cout << "Задача отмечена как выполненная.\n";
    }
    else {
        cout << "Нет задач для отметки.\n";
    }
    return;
}

void deleteTask() {
    if (planner.getTaskCount() > 0) {
        planner.displayAllTasks();
        cout << "Введите номер задачи для удаления: ";
        size_t index;
        cin >> index;
        planner.removeTask(index);
        cout << "Задача удалена.\n";
    }
    else {
        cout << "Нет задач для удаления.\n";
    }
    return;
}

void searchTask() {
    cout << "Введите ключевое слово для поиска: ";
    string keyword;
    getline(cin, keyword);
    planner.searchTasks(keyword);
    return;
}

void editTaskAction() {
    if (planner.getTaskCount() > 0) {
        planner.displayAllTasks();
        cout << "Введите номер задачи для редактирования: ";
        size_t index;
        cin >> index;
        cin.ignore();
        planner.editTask(index);
        cout << "Задача отредактирована.\n";
    }
    else {
        cout << "Нет задач для редактирования.\n";
    }
}

int main() {
    system("color F0");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    int choice;

    const MenuItem menuItems[] = {
        {"Добавить задачу", addTaskAction},
        {"Показать все задачи", displayAllTasks},
        {"Отметить задачу как выполненную", markTaskComplete},
        {"Удалить задачу", deleteTask},
        {"Поиск задач", searchTask},
        {"Редактировать задачу", editTaskAction},
        {"Выход"}
    };

    try {
        planner.loadFromFile("task.csv");
        cout << "Задачи успешно загружены из файла.\n";
    }
    catch (const exception& e) {
        cerr << "Ошибка при загрузке: " << e.what() << "\n";
    }

    while (true) {
        cout << "\nМеню:\n";
        for (int i = 0; i < OPTIONS_COUNT; ++i) {
            cout << i + 1 << ". " << menuItems[i].text << "\n";
        }

        int choice;
        cin >> choice;
        if (choice > 0 && choice <= OPTIONS_COUNT) {
            if (choice == 7) {
                exit(0);
            }
            menuItems[choice - 1].action();
            planner.saveToFile("task.csv");
        }
        else
        {
            cout << "Неверный выбор!\n";
        }
    }

    return 0;
}