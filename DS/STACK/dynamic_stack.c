#include<stdio.h>
#include<malloc.h>


struct stack{
	int top;
	int *arr;
	int capacity;
};

typedef struct stack STACK;


/*void Creat_Stack(STACK **stack){
  if(NULL == (*stack)){
  (*stack) = (STACK *)malloc(sizeof(STACK));	
  (*stack)->top = -1;
  (*stack)->arr = (int *)malloc(sizeof(int) * 5);
  (*stack)->no_ele = 5;
  }else{

  (*stack)->arr=(int *)realloc((*stack)->arr,((*stack)->no_ele)*2);
  (*stack)->no_ele = ((*stack)->no_ele)+(2 * ((*stack)-> no_ele));
  printf("stack_No:%d\n", (*stack)->no_ele);
  }

  }*/
void Global_Data(STACK *stack){

	printf("top:%d\ncapacity:%d\n", stack->top, stack->capacity);
}
void Creat_Stack(STACK **stack){

	(*stack) = (STACK *)malloc(sizeof(STACK));	
	if(!*stack)
		return;

	(*stack)->top = -1;
	(*stack)->capacity=1;
	(*stack)->arr = malloc(sizeof(STACK)* (*stack)->capacity);

	if(!((*stack)->arr))		
		return;
}
void Double_Stack(STACK **stack){
	(*stack)->capacity *= 2;
	(*stack)->arr=realloc((*stack)->arr, (*stack)->capacity);
}
int isfull(STACK *stack){
	if(stack->top == ((stack->capacity)-1))
		return 1;
	else 
		return 0;
}

int isempty(STACK *stack){
	if(stack->top == -1)
		return 1;
	else 
		return 0;
}


void Push(STACK **stack, int data){

	if(isfull(*stack)){
		Double_Stack(stack);
		printf("stack is full try again\n");
		printf("%d:%d is pushed top:%d\n",(*stack)->top, *((*stack)->arr+(++(*stack)->top))= data, (*stack)->top);

	}else{
//		++(*stack)->top;
		printf("%d:%d is pushed top:%d\n",(*stack)->top, *((*stack)->arr+(++(*stack)->top))= data, (*stack)->top);
		//(*stack)->arr[++(*stack)->top] = data;
		Global_Data(*stack);
	}
}

void Pop(STACK **stack){
	if(isempty(*stack)){
		printf("Nothing to pop\n");
	}else{
		printf("%d is poped\n", *((*stack)->arr+(*stack)->top));
		(*stack)->top--;
		Global_Data(*stack);	
	}
}
int main(void){
	STACK *STACK =NULL;
	int choice, data;
	Creat_Stack(&STACK);

	while(1){
		printf("Enter the choice\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter data\n");
				scanf("%d", &data);
				Push(&STACK, data);
				break;
			case 2:
				Pop(&STACK);
			case 4:
				// Delete_Front(&STACK);
				break;
			case 5:
				//    Display(STACK);
				break;

			default: 
				printf("wrong no\n"); 
		}
	}
}
