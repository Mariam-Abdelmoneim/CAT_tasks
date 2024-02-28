#include <stdio.h>
#include <stdlib.h>
#define StackEntry int

typedef struct stacknode
{
    StackEntry entry;
    struct stacknode * next;
}StackNode;

typedef struct stack{
    StackNode *top;
    int size;
}Stack;

void push(StackEntry, Stack*);
void pop(StackEntry*, Stack*);
void InitializeStack(Stack*);
void ClearStack(Stack*);
int StackFull(Stack*);
int StackEmpty(Stack*);
int StackSize(Stack*);
void StackTop(StackEntry*,Stack*);
void StackTraverse(Stack*,void (*)(StackEntry));

void display(StackEntry e)
{
    printf("\t%d", e);
}

int main()
{
    Stack s;
    StackEntry e;
    InitializeStack(&s);
    int choice;
    printf("\t(1) Display\n\t(2) Push\n\t(3) Pop\n\t(4) Stack Top\n\t(5) Stack Size\n\t(6) Clear Stack\n");

    do
    {
        printf("\nChoice?(0 to exit): ");
        scanf("%d", &choice);
        switch(choice)
            {
            case 1:
                if(!StackEmpty(&s))
                    StackTraverse(&s,&display);
                else
                    printf("\t!!STACK is EMPTY!!\n");
                break;
            case 2:
                if(!StackFull(&s))
                {
                    printf("Element? ");
                    scanf("%d", &e);
                    push(e, &s); }
                else
                    printf(">>> Overflow\n");
                break;
            case 3:
                if(!StackEmpty(&s))
                {
                    pop(&e,&s);
                    printf("\t%d is Popped\n", e);}
                else
                    printf(">>> Underflow\n");
                break;
            case 4:
                if(!StackEmpty(&s))
                {
                    StackTop(&e,&s);
                    printf("\tTop Stack: %d\n", e);}
                else
                    printf("\t!!STACK is EMPTY!!\n");
                break;
            case 5:
               printf("Stack size: %d\n", StackSize(&s));
               break;
            case 6:
                printf("Clearing Stack in progress...\n");
                ClearStack(&s);
                printf("DONE\n");
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice, try again.\n");
            }


    }while(1);

}


void push(StackEntry e, Stack* ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}
void pop(StackEntry* pe, Stack* ps)
{
    StackNode * pn = ps->top;
    *pe = pn->entry;
    ps->top = pn->next;
    free(pn);
    ps->size--;
}
void InitializeStack(Stack* ps)
{
    ps->top = NULL;
    ps->size = 0;
}
void ClearStack(Stack* ps)
{
    StackNode* pn = ps->top;
    while(pn)
    {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}
int StackFull(Stack* ps)
{
    return 0;
}
int StackEmpty(Stack* ps)
{
    return !ps->top;
}
int StackSize(Stack* ps)
{
    return ps->size;
}
void StackTop(StackEntry* pe,Stack* ps)
{
    *pe = ps->top->entry;
}
void StackTraverse(Stack* ps,void (*pf)(StackEntry))
{

    StackNode * pn = ps->top;
    while(pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}