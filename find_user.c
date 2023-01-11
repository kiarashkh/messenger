#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
int Find_user(USERS *Users, char *data)
{
    char *name = (char *)malloc(sizeof(char));
    int i = 0;
    while(1)
    {
        name[i] = data[i];
        if (data[i] == '\0')
            break;
        name = (char *)realloc(name, i + 2);
        i++;
    }
    USERS *curpos = Users;
    while(1)
    {
        if(curpos->nextUser == NULL)
        {
            printf("user not found\n");
            free(name);
            return 1;
        }
        else if(strcmp(curpos->nextUser->name, name) == 0)
        {
            printf("%s\n\n", curpos->nextUser->name);
            Post *postpos = curpos->nextUser->post;
            while(1)
            {
                if (postpos->nextPost == NULL)
                   break;
                else if (postpos->nextPost != NULL)
                    printf("post_id:%i\npost:%s\nlikes:%i\n\n", postpos->nextPost->postID, postpos->nextPost->post, postpos->nextPost->likes);
                 postpos = postpos->nextPost;
            }
            free(name);
            return 0;
        }
        curpos = curpos->nextUser;
    }
}