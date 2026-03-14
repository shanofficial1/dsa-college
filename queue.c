#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[5];


void insert(int value){
    if(rear==4){
        printf("Queue is full\n");
    }
    else if(rear==-1 && front==-1){
        rear=0;
        front=0;
        queue[rear]=value;
        }
    else{
        rear++;
        queue[rear]=value;
    
    }
    
}



void delete(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
}


void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(){

    while(1){
        int choice,value;
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

}