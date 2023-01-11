#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
USERS *Login(USERS * Users, char *data, int *loginStat)
{
    USERS *curPos = Users;
    char *name = (char *)malloc(sizeof(char));
    char *password = (char *)malloc(sizeof(char));
    int nameStat = 0;
    int passwordStat = 0;
    int i = 0;
    int j = 0;
    while (1)
    {
        if (data[i] == ' ' || data[i] == '\0')
        {
            nameStat = 1;
            name[i] = '\0';
            break;
        }
        name[i] = data[i];
        name = (char *)realloc(name, i + 2);
        i++;
    }
    int k = i;
    i++;
    if (data[i-1] != '\0')
    {
    while(1)
    {
        if (data[i] == '\0')
        {
            passwordStat = 1;
            password[j] = '\0';
            break;
        }
        password[j] = data[i];
        password = (char *)realloc(password, j + 2);
        j++;
        i++;
    }
    }
    if (nameStat == 0 || k < 3 || j < 3 || passwordStat == 0)
    {
        printf("unacceptable name or password\nname and password shuld be more than 2 characters\n");
        free(name);
        free(password);
        return curPos;
    }
    if(Users->nextUser == NULL)
    {
        printf("no user found\n");
        return curPos;
    }
    while(1)
    {
        curPos = curPos->nextUser;
        if (strcmp(curPos->name, name) == 0)
        {
            if (strcmp(curPos->password, password) != 0)
            {
                printf("incorrect password\n");
                free(name);
                free(password);
                return Users;
            }
            *loginStat = 1;
            printf("logged in\n");
            free(name);
            free(password);
            return curPos;
        }
        if (curPos->nextUser == NULL)
        {
            printf("user not found\n");
            free(name);
            free(password);
            return Users;
        }
    }
}