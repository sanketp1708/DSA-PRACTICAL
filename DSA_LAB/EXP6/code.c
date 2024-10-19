CODE
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}node;
void push(struct node** top,int data);
void display(struct node* top);
int isempty(struct node* top);
int peek(struct node* top);
void push(struct node** top,int data){
    struct node* newnode=(struct node*)malloc(sizeof(node));
    if (!newnode){
        printf("Stack overflow\n");
        return;
    }
    newnode->data=data;
    newnode->next=*top;
    *top=newnode;
}
int isempty(struct node * top){
    return top==NULL;}
int pop (struct node ** top){
    if(isempty(*top)){
        printf("Stack underflow\n");
        return -1;
    }
    struct node* temp=*top;
    *top=(*top)->next;
    int popped=temp->data;
    free (temp);
    return popped;
}
int peek(struct node* top){
    if(isempty(top)){
        printf("stack is empty\n");
        return -1;
    }
    return top->data;
}
void display(struct node* top){  
    struct node* temp=top;
    while(temp){
    printf("%d->",temp->data);
    temp=temp->next;}
    printf("NULL\n");
}
int main(){
    struct node* stack= NULL;
    int choice,value;
    do{
        printf("Menu:\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. exit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
         printf("Enter the value to push: ");
         scanf("%d",&value);
         push(&stack,value);
         break;
        case 2:
         value=pop(&stack);
         if(value!=-1){
            printf("Popped value: %d\n",value);
            break;
        }
        case 3:
         value=peek(stack);
         if (value!=-1){
             printf("Top value : %d\n",value);
         }
         break;
        case 4:
         display(stack);
         break;
        case 5:
         printf("Exiting\n");
         break;
        default:
         printf("invalid choice, try again\n");
    }
    }while (choice!=5);
    return 0;
}

OUTPUT
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 1
Enter the value to push: 10
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 1
Enter the value to push: 20
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 1
Enter the value to push: 30
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 2
Popped value: 30
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 3
Top value : 20
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 4
20->10->NULL
Menu:
1. push
2. pop
3. peek
4. display
5. exit
enter your choice : 5
Exiting


=== Code Execution Successful ===
