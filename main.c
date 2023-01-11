#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
#include "post.h"
#include "login.h"
#include "like.h"
#include "delete.h"
#include "info.h"
#include "find_user.h"
#include "posts.h"
#include "accounts.h"
int main()
{
    int loginStat = 0;
    char login[6] = "login";
    char singup[7] = "signup";
    char delete[7] = "delete";
    char post[5] = "post";
    char logout[7] = "logout";
    char like[5] = "like";
    char info[5] = "info";
    char find_user[10] = "find_user";
    char accounts[9] = "accounts";
    char posts[6] = "posts";
    USERS Users;
    Users.nextUser = NULL;
    USERS *curPos = &Users;
    while (1)
    {
        char *comand = (char *)malloc(sizeof(char));
        char *data = (char *)malloc(sizeof(char));
        int i = 0;
        int j = 0;
        char charactor;
        while(1)
        {
            charactor = getchar();
            if (charactor == ' ' || charactor == '\n')
            {
                comand[i] = '\0';
                break;
            }
            comand[i] = charactor;
            comand = (char *)realloc(comand, i + 2);
            i++;
        }
        if(charactor != '\n')
        {
            while(1)
            {
                charactor = getchar();
                if (charactor == '\n')
                {
                    data[j] = '\0';
                    break;
                }
                data[j] = charactor;
                data = (char *)realloc(data, j + 2);
                j++;
            }
        }
        else if(charactor == '\n')
            data[j] = '\0';
        if (strcmp(comand, login) == 0)
        {
            if (loginStat == 1)
                printf("you should first logout from the account that you are in\n");
            else if (loginStat == 0)
                curPos = Login(&Users, data, &loginStat);
        }
        else if (strcmp(comand, logout) == 0)
        {
            if(data[0] != '\0')
                printf("unacceptable input\n");
            else if(loginStat == 0)
                printf("you are not logged in\n");
            else if(loginStat == 1)
            {
                printf("logged out\n");
                curPos = &Users;
                loginStat = 0;
            }
        }
        else if (strcmp(comand, like) == 0)
        {
            if(loginStat == 0)
                printf("you are not logged in\n");
            else if (loginStat == 1)
                Like(&Users, data);
        }

        else if (strcmp(comand, singup) == 0)
        {
            if(loginStat == 1)
                printf("you need to logout\n");
            else if (loginStat == 0)
                Signup(&Users, data);
        }
        else if (strcmp(comand, delete) == 0)
        {
            if(loginStat == 0)
                printf("you are not logged in\n");
            else if (loginStat == 1)
                Delete(curPos, data);

        }
        else if (strcmp(comand, info) == 0)
        {
            if(data[0] != '\0')
                printf("unacceptable input\n");
            else if(loginStat == 0)
                printf("you are not logged in\n");
            else if(loginStat == 1)
                Info(curPos);
        }
        else if (strcmp(comand, post) == 0)
        {
            if(loginStat == 0)
                printf("you are not logged in\n");
            else if(sizeof(data) == sizeof(char))
                printf("unacceptable input\n");
            else if (loginStat == 1)
                POST(curPos, data);
        }
        else if (strcmp(comand, find_user) == 0)
            Find_user(&Users, data);
        else if (strcmp(comand, posts) == 0)
        {
            if(data[0] != '\0')
                printf("unacceptable input\n");
            else
                Posts(&Users);
        }
        else if (strcmp(comand, accounts) == 0)
        {
            if(data[0] != '\0')
                printf("unacceptable input\n");
            else
                Accounts(&Users);
        }
        else
            printf("invalid command\n");
        free (data);
        free (comand);
    }
}