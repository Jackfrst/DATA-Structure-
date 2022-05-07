#include <stdio.h>
#include <stdlib.h>
typedef struct node Node ;
struct node{
    int data ;
    Node *next ;
};
Node* create_node(Node* node , int data){
    Node *create_node = (Node*)malloc(sizeof(Node));
    create_node->data = data ;
    create_node->next = node ;
    return create_node;
}
void printList(Node* head){
    Node* current_node = head ;
    while(current_node!=NULL){
        printf("%d ",current_node->data);
        current_node = current_node->next;
    }
}
Node* insertBeginning(Node* head,int data){
    Node* new_node = create_node(head,data);
    return new_node;
}
Node* swap(Node* n1 , Node* n2 ){
    Node* temp = n2 ;
    n2 = n1 ;
    n1 = temp ;
    Node* temp2 = n2->next ;
    n2->next = n1->next ;
    n1->next = temp2 ;
  //  bbleShot(Node* head){
}
int main(){
    Node *head ,*n1,*n2,*n3,*n4,*n5;
    Node *swap1 , *swap2 ;
    n1 = create_node(NULL,10);
    head = n1 ;
    head = insertBeginning(head,20);
    swap1 = head ;
    head = insertBeginning(head,30);
    swap2 = head ;
    head = insertBeginning(head,40);
    head = insertBeginning(head,50);
    printList(head);
    swap(swap1,swap2);
    printf("\n");
    printList(head);
}
