#include <stdio.h>
#include <stdlib.h>

#define QueueEntry int

typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode* next;
}QueueNode;

typedef struct queue{
    QueueNode* front;
    QueueNode* rear;
    int size;
}Queue;

void Enqueue(QueueEntry, Queue*);
void Dequeue(QueueEntry*, Queue*);
void CreateQueue(Queue*);
void ClearQueue(Queue*);
int QueueSize(Queue*);
int QueueFull(Queue*);
int QueueEmpty(Queue*);
void QueueTraverse(Queue*, void (*)(QueueEntry));

void display(QueueEntry e)
{
    printf("\t%d", e);
}

int main()
{
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    int choice;
    printf("\t(1) Display\n\t(2) Enqueue\n\t(3) Dequeue\n\t(4) Queue Size\n\t(5) Clear Queue\n");

    do
    {
        printf("\nChoice?(0 to exit): ");
        scanf("%d", &choice);
        switch(choice)
            {
            case 1:
                if(!QueueEmpty(&q))
                    QueueTraverse(&q,&display);
                else
                    printf("\t!!Queue is EMPTY!!\n");
                break;
            case 2:
                if(!QueueFull(&q))
                {
                    printf("Element? ");
                    scanf("%d", &e);
                    Enqueue(e, &q); }
                else
                    printf(">>> Overflow\n");
                break;
            case 3:
                if(!QueueEmpty(&q))
                {
                    Dequeue(&e,&q);
                    printf("\t%d is served\n", e);}
                else
                    printf(">>> Underflow\n");
                break;
            case 4:
               printf("Queue size: %d\n", QueueSize(&q));
               break;
            case 5:
                printf("Clearing Queue is in progress...\n");
                ClearQueue(&q);
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


void Enqueue(QueueEntry e, Queue* pq)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    if(!pq->front)
        pq->front = pn;
    else
        pq->rear->next = pn;
    pq->rear = pn;
    pq->size++;
}
void Dequeue(QueueEntry* pe, Queue* pq)
{
    QueueNode* pn = pq->front;
    *pe = pn->entry;
    pq->front = pn->next;
    free(pn);
    if(!pq->front)
        pq->rear = NULL;
    pq->size--;
}
void CreateQueue(Queue* pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void ClearQueue(Queue* pq)
{
    pq->rear = pq->front;
    while(pq->rear)
    {
        pq->rear = pq->rear->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
int QueueFull(Queue* pq)
{
    return 0;
}
int QueueEmpty(Queue* pq)
{
    return !pq->front;
}
void QueueTraverse(Queue* pq, void (*pf)(QueueEntry))
{
    QueueNode* pn = pq->front;
    for(;pn;pn = pn->next)
    {
        (*pf)(pn->entry);
    }
}
