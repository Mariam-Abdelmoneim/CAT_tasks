#include <stdio.h>
#include <stdlib.h>

#define StackEntry int
#define MAXSTACK 20

typedef struct stack{
    StackEntry entry[MAXSTACK];
    int top;
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
    ps->entry[ps->top++] = e;
}
void pop(StackEntry* pe, Stack* ps)
{
    *pe = ps->entry[--ps->top];
}
void InitializeStack(Stack* ps)
{
    ps->top = 0;
}
void ClearStack(Stack* ps)
{
    ps->top = 0;
}
int StackFull(Stack* ps)
{
    return (ps->top==MAXSTACK-1);
}
int StackEmpty(Stack* ps)
{
    return !ps->top;
}
int StackSize(Stack* ps)
{
    return ps->top+1;
}
void StackTop(StackEntry* pe,Stack* ps)
{
    *pe = ps->entry[ps->top -1];
}
void StackTraverse(Stack* ps,void (*pf)(StackEntry))
{
    for(int i = 0;i < ps->top;i++)
    {
        (*pf)(ps->entry[i]);
    }
}