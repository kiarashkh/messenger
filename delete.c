
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
int Delete(USERS *User, char * data)
{
    int i = 0;
    int postid = 0;
    int postidStat = 0;
    while(1)
    {
        if (data[i] == '\0')
        {
            postidStat = 1;
            break;
        }
        else if (data[i] > '9' || data[i] < '0')
        {
            printf("wrong type of input\n");
            return 1;
        }
        else if (data[i] >= '0' && data[i] <= '9')
            postid = 10 * postid + ((int)data[i] - 48);
        i++; 
    }
    Post *curpos = User->post;
    while(1)
    {
        if (curpos->nextPost == NULL)
        {
            printf("post not found\n");
            return 1;
        }
        else if(curpos->nextPost->postID == postid)
        {
            Post *prevpost = curpos->nextPost;
            curpos->nextPost = curpos->nextPost->nextPost;
            free(prevpost);
            printf("post deleted\n");
            return 0;
        }
        curpos = curpos->nextPost;
    }
}