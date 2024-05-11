#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const;

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person);

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count);
private:
    map<string, TasksInfo> person_task_info_;
};

void TeamTasks::AddNewTask(const string& person){
    ++person_task_info_[person][TaskStatus::NEW];
}

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const{
    return person_task_info_.at(person);
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int task_count){
    TasksInfo updated_tasks;
    TasksInfo untouched_tasks = person_task_info_[person];
    vector<TaskStatus> statuses = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING}; 
    for (auto& status:statuses){
        TaskStatus next_status = static_cast<TaskStatus>(static_cast<int>(status) + 1);
         while (untouched_tasks[status] > 0 && task_count > 0) {
            ++updated_tasks[next_status];
            --untouched_tasks[status];
            ++person_task_info_[person][next_status];
            --person_task_info_[person][status];
            --task_count;
        }
    }
    untouched_tasks[TaskStatus::DONE] = 0;
    return {updated_tasks, untouched_tasks};

}

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь.
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks"s
         << ", "s << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"s
         << ", "s << tasks_info[TaskStatus::TESTING] << " tasks are being tested"s
         << ", "s << tasks_info[TaskStatus::DONE] << " tasks are done"s << endl;
}

int main() {
    TeamTasks tasks;
    //tasks.AddNewTask("Ilia"s);
    
    for (int i = 0; i < 13; ++i) {
        tasks.AddNewTask("Ivan"s);
    }
    //cout << "Ilia's tasks: "s;
    //PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    
    TasksInfo updated_tasks, untouched_tasks;
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
    cout <<"---------------------------------------------------------"s << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 5);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));
}