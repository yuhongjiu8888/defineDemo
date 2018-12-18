#include <stdio.h>
#include <stdlib.h>

#define LL_ADD(item,list)   do{     \
    item->prev = NULL;              \
    item->next = list;              \
    list = item;                    \
}while(0)


#define LL_REMOVE(item,list)    do{                         \
    if(item->prev != NULL) item->prev->next = item->next;   \
    if(item->next != NULL) item->next->prev = item->prev;   \
    if(item == list)  list = item->next;                    \
    item->prev = item->next = NULL;                         \
}while(0)

#define LL_PRINTF(list) do{             \
    iNode *temp = list;                 \
    while(temp != NULL)                 \
    {                                   \
        printf("[%d]->",temp->data);    \
        temp = temp->next;              \
    }                                   \
    printf("\n");                       \
}while(0)


typedef struct INODE{
    int data;
    struct INODE *prev;
    struct INODE *next;
}iNode;

int main(int argc, char const *argv[])
{
    printf("define function demo!\n");

    iNode *head = NULL;
    iNode *node = (iNode *)malloc(sizeof(iNode));
    if(NULL==node)
    {
        printf("malloc node* pointer error!\n");
        return -1;
    }
    node->data = 12;
    LL_ADD(node,head);

    iNode *node2 = (iNode *)malloc(sizeof(iNode));
    if(NULL==node2)
    {
        printf("malloc node2* pointer error!\n");
        return -1;
    }
    node2->data = 22;
    LL_ADD(node2,head);


    iNode *node3 = (iNode *)malloc(sizeof(iNode));
    if(NULL==node3)
    {
        printf("malloc node3* pointer error!\n");
        return -1;
    }
    node3->data = 12;
    LL_ADD(node3,head);

    LL_PRINTF(head);

    free(node);
    free(node2);
    free(node3);

    return 0;
}

