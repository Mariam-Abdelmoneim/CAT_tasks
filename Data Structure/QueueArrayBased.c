#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 20
#define QueueEntry int

typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
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
    pq->rear = (pq->rear +1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}
void Dequeue(QueueEntry* pe, Queue* pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}
void CreateQueue(Queue* pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
void ClearQueue(Queue* pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}
int QueueSize(Queue* pq)
{
    return pq->size;
}
int QueueFull(Queue* pq)
{
    return (pq->size==MAXQUEUE);
}
int QueueEmpty(Queue* pq)
{
    return !pq->size;
}
void QueueTraverse(Queue* pq, void (*pf)(QueueEntry))
{
    int pos,s;
    for(pos = pq->front, s = 0;s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos+1)%MAXQUEUE;
    }
}