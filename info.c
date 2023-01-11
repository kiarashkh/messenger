#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
int Info(USERS *User)
{
    printf("%s\n%s\n", User->name, User->password);
    Post *postpos = User->post;
    while(1)
    {
        if (postpos->nextPost == NULL)
            return 1;
        else if (postpos->nextPost != NULL)
            printf("post_id:%i\npost:%s\nlikes:%i\n\n", postpos->nextPost->postID, postpos->nextPost->post, postpos->nextPost->likes);
        postpos = postpos->nextPost;
    }
}