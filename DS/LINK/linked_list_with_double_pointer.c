#include<stdio.h>
#include<malloc.h>

typedef struct link {
    int data;
    struct link *next;
}LINK;

//typedef struct link  LINK;

LINK* New_Node(){
    LINK *temp = (LINK *)malloc(sizeof(LINK));
    temp-> next = NULL;
    return temp;
}

void Insert_Front(LINK **Head){
    int data;
    LINK *temp;
    printf("Enter data\n");
    scanf("%d", &data);
    if((*Head)==NULL){
            printf("first node\n");
        (*Head) = New_Node();
        (*Head)->data = data;
        return;
    }else{

        temp = New_Node();
        temp->data=data;
        temp ->next = (*Head);
        (*Head) = temp;
    }
}

void Display(LINK *Head){
    if(Head == NULL){
        printf("Nothing to display\n");
        return;
    }else{
        do{
            printf("%d ", Head->data);
            Head = Head->next;
        }while(Head!= NULL);
    }
}
void Delete_Front(LINK **HEAD){
    LINK *temp;

    if((*HEAD)==NULL){
        printf("Nothing to delete\n");
        return;
    }else if((*HEAD)->next == NULL){
        printf("%d deleted\n", (*HEAD)->data);
        free(*HEAD);
        *HEAD=NULL;
        return;
    }else{
        temp = *HEAD;
        *HEAD=(*HEAD)->next;
        free(temp);
        return;
    }
}

void Creat_Loop(LINK **Head){
	LINK *Front=*Head;
	LINK *Back=*Head;
	int i =4;
	for(;i!=0;i--){
		Back=Back->next;
	}

	while(Front->next != NULL)
		Front=Front->next;
	
	Front->next = Back;
}
int main(void){
    LINK *HEAD =NULL;
    int choice;

    while(1){
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            Insert_Front(&HEAD);
            break;
	case 2:
		Creat_Loop(&HEAD);
        case 4:
            Delete_Front(&HEAD);
            break;
        case 5:
            Display(HEAD);
            break;


        }
    }
}
