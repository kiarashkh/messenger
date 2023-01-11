#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signup.h"
void POST(USERS *User, char * data)
{
    Post *curPos = User->post;
    int postid = curPos->postID;
    int numOfChar = 0;
    while(1)
    {
        if (data[numOfChar] == '\0')
        {
            numOfChar++;
            break;
        }
        numOfChar++;
    }
    while(1)
    {
        if (curPos->nextPost == NULL)
        {
            Post *newPost = (Post *)malloc(sizeof(Post));
            curPos->nextPost = newPost;
            newPost->nextPost = NULL;
            newPost->likes = 0;
            newPost->postID = postid + 1;
            newPost->post = (char *)malloc(sizeof(char) * numOfChar);
            strcpy(newPost->post, data);
            printf("post saved\n");
            break;
        }
        curPos = curPos->nextPost;
        postid = curPos->postID;
    } 
}