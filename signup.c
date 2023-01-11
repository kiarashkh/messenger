#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
int Signup(USERS *Users, char *input)
{
    char *name = (char *)malloc(sizeof(char) * 1);
    char *password = (char *)malloc(sizeof(char) * 1);
    int nameStat = 0;
    int passwordStat = 0;
    int i = 0;
    int j = 0;
    while (1)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            nameStat = 1;
            name[i] = '\0';
            break;
        }
        name[i] = input[i];
        name = (char*)realloc(name, i + 2);
        if (name == NULL)
            printf("reallocating failed\n");
        i++;
    }
    int k = i;
    i++;
    while(1)
    {
        if (input[i] == '\0')
        {
            passwordStat = 1;
            password[j] = '\0';
            break;
        }
        password[j] = input[i];
        j++;
        i++;
        password = (char*)realloc(password, i + 100);
    }
    if (nameStat == 0 || k < 3 || j < 3 || passwordStat == 0)
    {
        printf("unacceptable name or password\nname and password shuld be more than 2 characters\n");
        free(name);
        free(password);
        return 1;
    }
    USERS *cur = Users->nextUser;
    if (Users->nextUser == NULL)
        cur = Users;
    while (1)
    {
        if (cur->nextUser != NULL)
        {
        if (strcmp(cur->name, name) == 0)
        {
            printf("The name is allready taken\n");
            free(name);
            free(password);
            return 1;
        }
        }
        else if(cur->nextUser == NULL)
        {
            USERS *newUser = (USERS *)malloc(sizeof(USERS));
            cur->nextUser = newUser;
            newUser->nextUser = NULL;
            newUser->name = malloc(i);
            strcpy(newUser->name, name); 
            newUser->password = malloc(j);
            strcpy(newUser->password, password);
            newUser->post = (Post *)malloc(sizeof(Post));
            newUser->post->nextPost = NULL;
            newUser->post->postID = 0;
            printf("user successfully signed up\n");
            free(name);
            free(password);
            return 0;
        }
        cur = cur->nextUser;
    }
}