#include <stdio.h>
#include <stdlib.h>
typedef struct node Node ;
struct node {
    int data  ;
    Node *next ;
};

void create_node(Node *head){

    printf("Enter a node data : (-1 to exit)\n");
    scanf("%d",&head->data);
    if(head->data ==-1){
        head->next = 0 ;
    }else{
        Node *new_node = (Node*)malloc(sizeof(Node));
        head->next = new_node ;
        create_node(new_node);
    }
}
void printList(Node *head){
    printf("Elements Are :\n");
    while(head!=0){
        printf("%d ",head->data);
        head = head->next ;
    }
}
int main(){
    Node *head ;
    head = (Node*)malloc(sizeof(Node));
    create_node(head);
    return 0;
}
