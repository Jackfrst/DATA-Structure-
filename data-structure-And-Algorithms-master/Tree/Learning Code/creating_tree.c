#include <stdio.h>
#include <stdlib.h>
typedef struct node Node ;
struct node {
    int data ;
    Node *right ;
    Node *left ;
};

Node *create_node(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! Could not Create a node \n");
        exit(1);
    }
    new_node->data = item ;
    new_node->left = NULL;
    new_node->right = NULL ;

    return new_node ;
}

void add_left_node (Node *node , Node *child){
    node->left = child ;
}

void add_right_node (Node *node , Node *child){
    node->right = child ;
}

void *create_tree(){
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_node(two,seven);
    add_right_node(two,nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_node(seven,one);
    add_right_node(seven,six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_node(six,five);
    add_right_node(six,ten);

    Node *eight = create_node(8);
    add_right_node(nine,eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_node(eight , three);
    add_right_node(eight,four);
}
