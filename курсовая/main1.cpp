#include <iostream>
#include <string>
#include <vector>
#include <memory> // для умных указателей


class Task {
protected:
    std::string description;
    std::string deadline; // дата/время выполнения
    bool isCompleted;

public:
    Task(const std::string& desc, const std::string& dl)
        : description(desc), deadline(dl), isCompleted(false) {}

    virtual ~Task() = default;

    // Виртуальные методы (полиморфизм)
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

class SimpleTask : public Task {
public:
    SimpleTask(const std::string& desc, const std::string& dl)
        : Task(desc, dl) {}

    void display() const override {
        std::cout << "[Простая задача] ";
        Task::display();
    }
};

class ImportantTask : public Task {
public:
    ImportantTask(const std::string& desc, const std::string& dl)
        : Task(desc, dl) {}

    void display() const override {
        std::cout << "[❗ Важная задача] ";
        Task::display();
    }
};

class RecurringTask : public Task {
private:
    std::string recurrence; // "ежедневно", "еженедельно" и т.д.

public:
    RecurringTask(const std::string& desc, const std::string& dl, const std::string& rec)
        : Task(desc, dl), recurrence(rec) {}

    void display() const override {
        std::cout << "[🔄 " << recurrence << "] ";
        Task::display();
    }
};

class Diary {
private:
    std::vector<std::unique_ptr<Task>> tasks; // инкапсуляция + умные указатели

public:
    void addTask(std::unique_ptr<Task> task) {
        tasks.push_back(std::move(task));
    }
    void addTaskFromInput() {
        std::cout << "\nВыберите тип задачи:\n"
            << "1. Обычная задача\n"
            << "2. Важная задача\n"
            << "3. Повторяющаяся задача\n"
            << "> ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера

        std::string description, deadline, recurrence;

        std::cout << "Введите описание задачи: ";
        std::getline(std::cin, description);

        std::cout << "Введите срок выполнения (например, 2025-04-25): ";
        std::getline(std::cin, deadline);

        switch (choice) {
        case 1:
            addTask(std::make_unique<SimpleTask>(description, deadline));
            break;
        case 2:
            addTask(std::make_unique<ImportantTask>(description, deadline));
            break;
        case 3:
            std::cout << "Введите периодичность (например, ежедневно, еженедельно): ";
            std::getline(std::cin, recurrence);
            addTask(std::make_unique<RecurringTask>(description, deadline, recurrence));
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    }

    void displayAllTasks() const {
        if (tasks.empty()) {
            std::cout << "Задач нет.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            tasks[i]->display(); // полиморфизм (вызовется нужный display)
            std::cout << "\n";
        }
    }

    void completeTask(size_t index) {
        if (index < tasks.size()) {
            tasks[index]->complete();
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
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    setlocale(LC_ALL, "RU");
    /*Diary diary;

    // Добавляем задачи разных типов
    diary.addTask(std::make_unique<SimpleTask>("Купить молоко", "2025-04-23"));
    diary.addTask(std::make_unique<ImportantTask>("Сдать проект", "2025-04-25"));
    diary.addTask(std::make_unique<RecurringTask>("Уборка", "2025-04-24", "еженедельно"));

    // Выводим все задачи
    diary.displayAllTasks();

    // Отмечаем задачу выполненной
    diary.completeTask(0);

    // Удаляем выполненные задачи
    diary.removeCompletedTasks();

    std::cout << "\nПосле удаления выполненных задач:\n";
    diary.displayAllTasks();

    return 0;*/

    Diary diary;
    int choice;

    while (true) {
        std::cout << "\n=== Ежедневник ===\n"
            << "1. Добавить задачу\n"
            << "2. Показать все задачи\n"
            << "3. Отметить задачу выполненной\n"
            << "4. Удалить выполненные задачи\n"
            << "5. Выход\n"
            << "> ";

        std::cin >> choice;
        clearInputBuffer(); // очищаем буфер после ввода числа

        switch (choice) {
        case 1:
            diary.addTaskFromInput();
            break;
        case 2:
            diary.displayAllTasks();
            break;
        case 3: {
            std::cout << "Введите номер задачи для отметки: ";
            size_t index;
            std::cin >> index;
            clearInputBuffer();
            diary.completeTask(index - 1); // -1, т.к. нумерация с 0
            break;
        }
        case 4:
            diary.removeCompletedTasks();
            std::cout << "Выполненные задачи удалены.\n";
            break;
        case 5:
            return 0;
        default:
            std::cout << "Неверный выбор!\n";
        }
    }
}
