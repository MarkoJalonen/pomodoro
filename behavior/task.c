#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

Task *createTask(const char *name, int key)
{
    Task *t = malloc(sizeof(Task));
    t->name = malloc(strlen(name) + 1);
    strcpy(t->name, name);
    t->key = key;
    return t;
}

void destroyTask(Task *t)
{
    free(t->name);
    free(t);
}


void initTaskList(TaskList *tl)
{
    tl->elements = malloc(sizeof(Task *) * TASK_NUM_MIN);
    tl->taskSpace = TASK_NUM_MIN;
    tl->taskCount = 0;
}

int addTask(TaskList *tl, Task *t)
{
    if(tl->taskCount == tl->taskSpace)
    {
        if(tl->taskSpace * 2 <= TASK_NUM_MAX)
        {
            tl->elements = realloc(tl->elements, sizeof(Task *) * tl->taskSpace * 2);
        } 
        else 
        {
            printf("Task Max Count Reached. Abort.\n");
            return -1;
        }
    }
    tl->elements[tl->taskCount] = t;
    tl->taskCount++;
    return 0;
}