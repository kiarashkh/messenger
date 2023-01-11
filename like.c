#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
int Like(USERS * Users, char *data)
{
    char *name = (char *)malloc(sizeof(char));
    int POstid = 0;
    char *postid = (char *)malloc(sizeof(char));
    int nameStat = 0;
    int postIDStat = 0;
    int i = 0;
    int j = 0;
    while(1)
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
    if (data[i-1] !='\0')
    {
    while(1)
    {
        if (data[i] == '\0')
        {
            postIDStat = 1;
            postid[j] = '\0';
            break;
        }
        postid[j] = data[i];
        if(postid[j] <= '9' && postid[j] >= '0')
            POstid = 10 * POstid + ((int)postid[j] - 48);
        else if(postid[j] > '9' || postid[j] < '0')
        {
            printf("unacceptable input\n");
            free(name);
            free(postid);
            return 1;
        }
        postid = (char *)realloc(postid, j + 2);
        j++;
        i++;
    }
    }
    if (nameStat == 0 || k < 3 || postIDStat == 0)
    {
        printf("unacceptable name or postID\nname shuld be more than 2 characters\n");
        free(name);
        free(postid);
        return 1;
    }
    USERS *curpos = Users;
    while(1)
    {
        if (curpos->nextUser == NULL)
        {
            printf("no user found\n");
            free(name);
            free(postid);
            return 1;
        }
        if(strcmp(curpos->nextUser->name, name) == 0)
        {
            Post * postpos = curpos->nextUser->post;
            while (1)
            {
                if(postpos->nextPost == NULL)
                {
                    printf("post not found\n");
                    break;
                }
                else if(postpos->nextPost->postID == POstid)
                {    
                    postpos->nextPost->likes += 1;
                    printf("post liked\n");
                    break;
                }
                postpos = postpos->nextPost;
            }
            free(name);
            free(postid);
            return 0;
        }
        curpos = curpos->nextUser;
    }
}