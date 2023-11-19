#ifndef TASK_H
#define TASK_H

#define TASK_NUM_MIN 10
#define TASK_NUM_MAX 80

typedef struct Task
{
    int key;
    char *name;
} Task;

typedef struct TaskList
{
    Task **elements;
    int taskCount;
    int taskSpace;
} TaskList;


Task *createTask(const char *name, int key);
void destroyTask(Task *t);
void initTaskList(TaskList *tl);
int addTask(TaskList *tl, Task *t);

#endif