#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "task1and2.h"



typedef struct Node {
    int key;
    struct Node* next;
    char list[20];
}Node;

typedef struct List {
    struct Node* head;
}List;


List* createList() {
    List* newlist = malloc(sizeof(List));
    assert(newlist != NULL);

    newlist->head = NULL;

    return newlist;

}

Node* createNode(List* list, int key) {
    Node *newnode = malloc(sizeof(Node));
    assert(newnode != NULL);

    newnode->key = key;
    newnode->next = NULL;

    return newnode;
}

bool isEmpty(List* list) {
    if(list==NULL) {
        return true;
    }
    else {
        return false;
    }
}
void insert(List * list, int key) {
    Node* node = createNode(list,key);

    if(isEmpty(list) == true)
    list->head = node;
    else {
        node->next = list->head;
        list->head = node;
    }
    node->key = key;

}

char* two_d_allocc(int rows, int columns, size_t t) { //rows multiplied with columns and size of an int are the size of our matrix/2dArray
    char* matrix = (char*)malloc(rows * columns * t); //allocate memory for matrix

    assert(matrix != NULL);

    return matrix;
}

void two_d_deallocc(char *matrix) {
    free(matrix);
}

//row major
void two_d_storee(char* matrix, int row, int column, int columns, size_t t, Node* node) { //row and column are where we want to store value
    int *offset = (int*)matrix + (row*columns + column) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    *offset = node->key;
    printf("offsets value = %d\n", *offset);
   //*(int*)(matrix + (row*columns + column) * t) = value; typecasting and assigning to value in one step
    
}
int two_d_fetchh(char* matrix, int row, int column, int columns, size_t t) {
    int *offset = (int*)matrix + (row*columns + column) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    
    return *offset;
}

int main() {

    List* l1 = createList();

    Node* n = createNode(l1, 1);
    Node* n2 = createNode(l1, 2);
    Node* n3 = createNode(l1, 3);
    Node* n4 = createNode(l1, 4);
    Node* n5 = createNode(l1, 5);
    Node* n6 = createNode(l1, 6);
    Node* n7 = createNode(l1, 7);
    Node* n8 = createNode(l1, 8);
    Node* n9 = createNode(l1, 9);
    Node* n10 = createNode(l1, 10);

    int structsize = sizeof(Node);
    printf("size of struct: %d\n", structsize);

    int sizeOfFields1 = sizeof(n->key) + sizeof(n->next) + sizeof(char[20]); //key is int(4bytes), next is pointer(8bytes) and char is 20 bytes. Different order will store differently in memory as memory wants to fit in one word.
    printf("size of fields1: %d\n", sizeOfFields1);

    int sizeOfFields2 = sizeof(n->next) + sizeof(n->key) + sizeof(char[20]);
    printf("size of fields2: %d\n", sizeOfFields2);

    int sizeOfFields3 = sizeof(n->next) + sizeof(char[20]) + sizeof(n->key);
    printf("size of fields3: %d\n\n", sizeOfFields3);

    char * d;
    int y;
    d = two_d_allocc(4,4,sizeof(structsize));
    two_d_storee(d, 1, 2,4, sizeof(structsize),n);
    two_d_storee(d, 1, 2,4, sizeof(structsize),n2);
    two_d_storee(d, 1, 3,4, sizeof(structsize),n3);
    two_d_storee(d, 1, 4,4, sizeof(structsize),n4);
    two_d_storee(d, 2, 1,4, sizeof(structsize),n5);
    two_d_storee(d, 2, 2,4, sizeof(structsize),n6);
    two_d_storee(d, 2, 3,4, sizeof(structsize),n7);
    two_d_storee(d, 2, 4,4, sizeof(structsize),n8);
    two_d_storee(d, 3, 1,4, sizeof(structsize),n9);
    two_d_storee(d, 3, 2,4, sizeof(structsize),n10);
    
    y = two_d_fetchh(d, 1, 2,4, sizeof(int));
    printf("\n%d\n", y);

    memoryDump(d, 4*4*sizeof(int));

    
    
    two_d_deallocc(d);


    return 0;

}
