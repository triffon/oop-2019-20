#ifndef TASK_H
#define TASK_H
#define MAX_TITLE_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 128

class Task {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

public:
    Task();
    Task(char* title, char* description);
    operator=(Task task);
    const char* getTitle();
    const char* getDescription();
    void printInfo();
};

#endif // TASK_H
