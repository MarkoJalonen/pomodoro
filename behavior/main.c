#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

int main(int argc, char **argv)
{
    TaskList newTaskList;
    initTaskList(&newTaskList);

    int i;
    char *front = "Test Task ";
    char *name = NULL;
    for (i = 0; i < 10; i++)
    {
        name = malloc(strlen(front) + 2);
        sprintf(name, "%s%d", front, i); 
        addTask(&newTaskList, createTask(name, i));
        printf("%s\n", newTaskList.elements[i]->name);
    }

    return 0;
}