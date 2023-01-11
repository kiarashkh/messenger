typedef struct PosT
{
    int postID;
    int likes;
    char *post;
    struct PosT *nextPost;
}Post;
typedef struct UserInfo
{
    char *name;
    char *password;
    Post *post;
    struct UserInfo *nextUser;
}USERS;
int Signup(USERS *Users, char *input);