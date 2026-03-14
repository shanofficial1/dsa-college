#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[5];


void insert(int value){
    if(front==((rear+1)%5)){
        printf("Queue Full");
    }
    else if(front==-1 && rear ==-1){
        front=0;
        rear=0;
        queue[rear]=value;
    }
    else{
        rear=(rear+1)%5;
        queue[rear]=value;
    }
}



void delete(){
    if(front==-1){
        printf("Queue empty");
    }
    else if(rear==front){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%5;
    }
}




void display(){
    if(front==-1 ){
        printf("Queue is empty\n");
    }
    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % 5;
    }
    printf("\n");
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