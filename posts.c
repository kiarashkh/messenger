#include <stdio.h>
#include "signup.h"
int Posts(USERS *Users)
{
    if(Users->nextUser == NULL)
    {
        printf("no user found\n");
        return 1;
    } 
    USERS *curpos = Users->nextUser;
    FILE *fp = fopen("posts.txt", "w");
    while(1)
    {
        Post *postpos = curpos->post; 
        while(1)
        {
            if (postpos->nextPost == NULL)
                break;
            fprintf(fp, "%s %s %i\n", postpos->nextPost->post, curpos->name, postpos->nextPost->likes);
            postpos = postpos->nextPost;
        }
        if(curpos->nextUser == NULL)
            break;
        curpos = curpos->nextUser;
    }
    printf("posts saved\n");
    fclose(fp);
    return 0;
}