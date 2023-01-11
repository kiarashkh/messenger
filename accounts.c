#include <stdio.h>
#include "signup.h"
int Accounts(USERS *Users)
{
    if(Users->nextUser == NULL)
    {
        printf("no user found\n");
        return 1;
    } 
    USERS *curpos = Users->nextUser;
    FILE *fp = fopen("accounts.txt", "w");
    while (1)
    {
        int numOfPosts = 0;
        Post *postpos = curpos->post;
        while(1)
        {
            if(postpos->nextPost == NULL)
                break;
            numOfPosts++;
            postpos = postpos->nextPost;
        }
        fprintf(fp, "%s %s %i\n", curpos->name, curpos->password, numOfPosts);
        if(curpos->nextUser == NULL)
            break;
        curpos = curpos->nextUser;
    }
    printf("accounts saved\n");
    fclose(fp);
    return 0;
}