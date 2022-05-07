#include <stdio.h>
#include <stdlib.h>
typedef struct node Node ;
struct node{
    int data ;
    Node *next ;
};
Node* create_node(int data , Node *node){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data ;
    new_node->next = node ;

    return new_node;
}
Node* prepend(Node *head , int item){
    Node *new_node = create_node(item,head);
    return new_node;
}
Node* append(Node *head , int item){
    Node *new_node = create_node(item , NULL);
    if(head == NULL){
        return new_node;
    }
    Node *current_node = head ;
    while(current_node->next!=NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head ;
}
void traversing(Node *head){
    Node *current_node = head ;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}
int count(Node *head){
    int count = 0 ;
    Node *current_node = head ;
    while(current_node!=NULL){
        count++;
        current_node = current_node->next;
    }
    return count ;
}
Node* search(Node *head , int item){
    Node *current_node = head ;
    while(current_node!=NULL){
        if(current_node->data==item){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}
void insert(Node *node , int data){
    Node *new_node = create_node(data , node->next);
    node->next = new_node ;
}
Node* remove_node(Node *head , Node *delNode){
    if(delNode==head){
        head = delNode->next ;
        free(delNode);
        return head;
    }
    Node *current_node = head ;
    while(current_node!=NULL){
        if(current_node->next == delNode){
            break ;
        }
        current_node = current_node->next ;
    }
    if(current_node==NULL){
        return head ;
    }
    current_node->next = delNode->next;
    free(delNode);
    return head;
}
int main(){
    Node *n1 , *n2 , *head , *n3 , *n4 ;
    n1 = create_node(10,NULL);//creating a node n1
    head = n1 ;//declareing n1 as its first node
    head = prepend(head,20);//adding a node in the first position
    n4 = append(head,50);//a node added in the end of the list
    insert(n1,100);//inserted a new node after node n1

    traversing(head);//Traverse the whole node and printed it's value
    printf("Total Node : %d\n",count(head));
    //searching
    Node *found = search(head,70);//searching a particular data in the list
    if(found!=NULL){
        printf("Found in %p",found);
    }else{
        printf("Not Found\n");
    }
    //removing a node
    printf("After Removing 2nd Node :\n");
    head = remove_node(head , n1);
    //after removing;
    traversing(head);

    return 0;
}
