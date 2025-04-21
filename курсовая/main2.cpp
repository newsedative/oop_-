#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>

// Убираем конфликтующие макросы из Windows.h
#ifdef _WIN32
#define NOMINMAX  // Отключаем min/max макросы
#include <windows.h>
#undef RED        // Отменяем конфликтующие макросы
#undef GREEN
#undef BLUE
#undef YELLOW
#undef MAGENTA
#undef CYAN
#undef BOLD
#endif

// Переопределяем цветовые макросы с префиксом COLOR_
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_BOLD    "\033[1m"

// Включение поддержки ANSI-цветов в Windows
#ifdef _WIN32
void enableANSIColors() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif

// Базовый класс Task
class Task {
protected:
    std::string description;
    std::string deadline;
    bool isCompleted;

public:
    Task(const std::string& desc, const std::string& dl)
        : description(desc), deadline(dl), isCompleted(false) {}

    virtual ~Task() = default;

    virtual void display() const {
        std::cout << "[" << (isCompleted ? "X" : " ") << "] "
            << description << " (до " << deadline << ")";
    }

    virtual void complete() {
        isCompleted = true;
    }

    bool getIsCompleted() const { return isCompleted; }
    const std::string& getDescription() const { return description; }
    const std::string& getDeadline() const { return deadline; }
};

// Производные классы задач
class SimpleTask : public Task {
public:
    SimpleTask(const std::string& desc, const std::string& dl)
        : Task(desc, dl) {}

    void display() const override {
        std::cout << COLOR_CYAN << "[Обычная] " << COLOR_RESET;
        Task::display();
    }
};

class ImportantTask : public Task {
public:
    ImportantTask(const std::string& desc, const std::string& dl)
        : Task(desc, dl) {}

    void display() const override {
        std::cout << COLOR_RED << COLOR_BOLD << "[❗ Важно] " << COLOR_RESET;
        Task::display();
    }
};

class RecurringTask : public Task {
private:
    std::string recurrence;

public:
    RecurringTask(const std::string& desc, const std::string& dl, const std::string& rec)
        : Task(desc, dl), recurrence(rec) {}

    void display() const override {
        std::cout << COLOR_MAGENTA << "[🔄 " << recurrence << "] " << COLOR_RESET;
        Task::display();
    }
};

// Класс Diary
class Diary {
private:
    std::vector<std::unique_ptr<Task>> tasks;

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

public:
    void addTask(std::unique_ptr<Task> task) {
        tasks.push_back(std::move(task));
    }

    void addTaskFromInput() {
        std::cout << "\n" << COLOR_BOLD << "📝 Новая задача" << COLOR_RESET << "\n";
        std::cout << "1. Обычная\n";
        std::cout << "2. Важная\n";
        std::cout << "3. Повторяющаяся\n";
        std::cout << "> ";

        int type;
        std::cin >> type;
        clearInputBuffer();

        if (type < 1 || type > 3) {
            std::cout << COLOR_RED << "Ошибка! Неверный тип.\n" << COLOR_RESET;
            return;
        }

        std::string desc, deadline, recurrence;

        std::cout << "Описание: ";
        std::getline(std::cin, desc);

        std::cout << "Срок (например, 2025-04-30): ";
        std::getline(std::cin, deadline);

        switch (type) {
        case 1: addTask(std::make_unique<SimpleTask>(desc, deadline)); break;
        case 2: addTask(std::make_unique<ImportantTask>(desc, deadline)); break;
        case 3:
            std::cout << "Периодичность (ежедневно/еженедельно): ";
            std::getline(std::cin, recurrence);
            addTask(std::make_unique<RecurringTask>(desc, deadline, recurrence));
            break;
        }

        std::cout << COLOR_GREEN << "Задача добавлена!\n" << COLOR_RESET;
    }

    void displayAllTasks() const {
        if (tasks.empty()) {
            std::cout << COLOR_YELLOW << "Нет задач для отображения.\n" << COLOR_RESET;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            tasks[i]->display();
            std::cout << "\n";
        }
    }

    void markTaskComplete() {
        if (tasks.empty()) {
            std::cout << COLOR_YELLOW << "Нет задач для отметки!\n" << COLOR_RESET;
            return;
        }

        std::cout << "Введите номер задачи: ";
        size_t index;
        std::cin >> index;
        clearInputBuffer();

        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1]->complete();
            std::cout << COLOR_GREEN << "Задача отмечена выполненной!\n" << COLOR_RESET;
        }
        else {
            std::cout << COLOR_RED << "Неверный номер задачи!\n" << COLOR_RESET;
        }
    }

    void removeCompletedTasks() {
        tasks.erase(
            std::remove_if(tasks.begin(), tasks.end(),
                [](const std::unique_ptr<Task>& task) {
                    return task->getIsCompleted();
                }),
            tasks.end()
                    );
    }

    void showMenu() {
#ifdef _WIN32
        enableANSIColors();
#endif

        while (true) {
            std::cout << "\n" << COLOR_BOLD << COLOR_BLUE << "=== ЕЖЕДНЕВНИК ===" << COLOR_RESET << "\n";
            std::cout << "1. 📝 Добавить задачу\n";
            std::cout << "2. 📋 Показать все задачи\n";
            std::cout << "3. ✅ Отметить задачу выполненной\n";
            std::cout << "4. 🗑️ Удалить выполненные задачи\n";
            std::cout << "5. 🚪 Выход\n";
            std::cout << "> ";

            int choice;
            std::cin >> choice;
            clearInputBuffer();

            switch (choice) {
            case 1: addTaskFromInput(); break;
            case 2: displayAllTasks(); break;
            case 3: markTaskComplete(); break;
            case 4: removeCompletedTasks();
                std::cout << COLOR_GREEN << "Готово! Выполненные задачи удалены.\n" << COLOR_RESET;
                break;
            case 5: return;
            default: std::cout << COLOR_RED << "Ошибка! Неверный выбор.\n" << COLOR_RESET;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Diary diary;
    diary.showMenu();
    return 0;
}
