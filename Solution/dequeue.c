#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*push_front X: 정수 X를 덱의 앞에 넣는다.

push_back X: 정수 X를 덱의 뒤에 넣는다.

pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

size: 덱에 들어있는 정수의 개수를 출력한다.

empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.

front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/


//사용자의 처음 입력 값을 받아 data 배열의 크기를 결정 짓는다. 
typedef int element;
typedef struct
{
//  element* data = (int*)malloc(sizeof(int) * size); //동적할당
    int *data;
//    struct Data *data;
    int front,rear;
}DequeType;

// typedef struct
// {
//     int data;
// }Data;


int empty(DequeType *q){
    if (q->front == q->rear)
    return 1;
    else
    return 0;
}

void push_front(DequeType *q, int size, element item){
//    if (q -> rear % size == q -> front) return -1;
//    else {
        q->data[q->front] = item;
        q->front = (q->front - 1 + size) % size;
//    }
}

void push_back(DequeType *q, int size, element item){
    //일반적인 queue에서의 삽입과 같다 
//    if (q -> rear % size == q -> front) return -1;
//    else {
        q->rear  = (q->rear - 1 + size) % size;
        q->data[q->rear] = item;
}

int pop_front(DequeType *q, int size){
    //일반적인 queue에서의 삭제와 같다. 
    if(empty)
    return -1;
    else{
    q -> front = (q -> front + 1) % size;
    return q->data[q->front];
    }
}

int pop_back(DequeType *q, int size){
    int rear = q->data[q->rear];

    if(empty)
    return -1;
    else{
    q -> rear = (q -> rear - 1 + size) % size;
    return rear;
    }
}

 int sizeOfQueue(DequeType *q,int size){
     return (q->rear - q->front) % size;
 }

int front(DequeType *q){
    if (empty(q))
    return -1;
    else 
    return q->data[q->front];
}

int back(DequeType *q){
    if (empty(q))
    return -1;
    else 
    return q->data[q->rear];
}


    int size, num;
    char funct[100];

int main()
{
    DequeType queue;


    scanf("%d", &size);    // 값을 입력받음
//    DequeType queue->*data = (int *)malloc(sizeof(int) * size);
//    queue->data = malloc(sizeof(struct)) * size;

//사용자의 명령에 따라 함수를 호출하는 로직

    while(1){

    scanf_s("%s", &funct);

    if (strcmp(funct, "push_back") == 0)
    {
        scanf("%d\n", &num);
        push_back(&queue, size, num);
    } 
    else if (strcmp(funct, "push_front") == 0)
    {
        scanf("%d\n", &num);
        push_front(&queue, size, num);
    }    
    else if (strcmp(funct, "pop_front") == 0)
    {
        printf("%d\n", pop_front(&queue, size));
    }
    else if (strcmp(funct, "pop_back") == 0)
    {
        printf("%d\n", pop_back(&queue, size));
    }
    else if (strcmp(funct, "size") == 0)
    {
        printf("%d\n", sizeOfQueue(&queue, size));
    }
    else if (strcmp(funct, "empty") == 0)
    {
      printf("%d\n", empty(&queue));
    }
    else if (strcmp(funct, "back") == 0)
    {
        printf("%d\n", back(&queue));
    }
    else if (strcmp(funct, "front") == 0)
    {
        printf("%d\n", front(&queue));
    }
}
return 0;
}
