#include<stdio.h>
#include<malloc.h>


struct Queue{
	int capacity;
	int front, rear;	
	int *arr;
};

typedef struct Queue Que;

void Queue(Que **Q, int size){
	*Q = (Que *)malloc(sizeof(Que));
	if(!*Q)
	return;
	
	(*Q)->capacity = size;
	(*Q) ->rear = (*Q) -> front = -1;
	(*Q) ->arr = (int *)malloc(sizeof(int)*size);
	return;
}

int IsEmpty(Que **Q){
	
	return ((*Q)->front == -1);	
}

int IsFull(Que **Q){
	return ((((*Q)->rear+1) % (*Q)->capacity) == (*Q)->front);
}

void EnQueue(Que **Q, int data){
	
	if(IsFull(Q)){
		printf("Que is full\n");
	}else{
		(*Q)->rear = ((*Q)->rear +1 % (*Q)->capacity);
		(*Q)->arr[(*Q)->rear]= data;
		printf("data inserted:%d:%d:%d:capacity:%d\n",(*Q)->arr[(*Q)->rear],(*Q)->rear, (*Q)->front, (*Q)->capacity);
		if((*Q)->front == -1)
		(*Q)->front = (*Q)->rear;
	}	
}

int DeQueue(Que **Q){
	int data = 0;
	if(IsEmpty(Q)){
		printf("Queue is underflow\n");
	}else{
		data = (*Q) ->arr[(*Q)->front];
		
		if((*Q)->front == (*Q)->rear)
		(*Q)->front = (*Q)->rear = -1;
		else
		(*Q)->front= (((*Q)->front + 1 ) % (*Q)-> capacity);
	}
	return data;
}
void Display(Que *Q){

}
int main(void){
	Que *Q =NULL;
	int choice, data;
	Queue(&Q, 5);

	while(1){
		printf("Enter the choice\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter data\n");
				scanf("%d", &data);
				EnQueue(&Q, data);
				break;
			case 2:
				printf("data after dueue:%d\n",DeQueue(&Q));
			case 4:
				Display(Q);
				break;
			case 5:
				//    Display(STACK);
				break;

			default: 
				printf("wrong no\n"); 
		}
	}
}
