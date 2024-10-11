#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//task1
char* two_d_alloc(int rows, int columns, size_t t) { //rows multiplied with columns and size of an int are the size of our matrix/2dArray
    char* matrix = (char*)malloc(rows * columns * t); //allocate memory for matrix

    if(matrix != NULL)
    printf("Memory succesfully allocated\n");

    return matrix;
}

void two_d_dealloc(char *matrix) {
    free(matrix);
}

//row major
void two_d_store(char* matrix, int row, int column, int columns, size_t t, int value) { //row and column are where we want to store value
    int *offset = (int*)matrix + (row*columns + column) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    *offset = value;
    printf("offsets value = %d\n", *offset);
   //*(int*)(matrix + (row*columns + column) * t) = value; typecasting and assigning to value in one step
    
}
int two_d_fetch(char* matrix, int row, int column, int columns, size_t t) {
    int *offset = (int*)matrix + (row*columns + column) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    
    return *offset;
}

//column major
/*
void two_d_store(char* matrix, int row, int column, int rows, size_t t, int value) { //row and column are where we want to store value
    int *offset = matrix + (row*columns + rows) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    *offset = value;
    printf("offsets value = %d\n", *offset);
   //*(int*)(matrix + (row*columns + column) * t) = value; typecasting and assigning to value in one step
    
}
int two_d_fetch(char* matrix, int row, int column, int rows, size_t t) {
    int *offset = matrix + (row*columns + rows) * t; //from the beginning of the address of the matrix we will offset by certain bytes according to the formula to get to where we want to store our value
    
    return *offset;
}

*/

//task2
void memoryDump(char *arr, size_t t) {
    for(int i = 0; i < t; i += 16) { // Grouping by 16 bytes per line
        printf("%p ", &arr[i]); // Print memory address of the first byte on the line
        
        // Print hexadecimal notation for each word (4 bytes)
        for(int j = 0; j < 16; j += 4) {
            for(int k = 0; k < 4; k++) {
                printf("%02x", arr[i + j + k]); // Print hexadecimal notation for each byte
            }
            printf(" "); // Space between words
        }
        
        //ASCII
        printf(" ");
        for(int j = 0; j < 16; j++) {
            if(isprint(arr[i + j])) { // Check if byte is printable
                printf("%c", arr[i + j]); // Print ASCII character
            } else {
                printf("."); //Dot for non-printable characters
            }
        }
        
        printf("\n");
    }
    
}

int main() {

    char *d = two_d_alloc(4,4,sizeof(int));
    two_d_store(d, 1, 1,4, sizeof(int),4);
    two_d_store(d, 1, 1,4 , sizeof(int),3);
    int y = two_d_fetch(d, 1, 1,4, sizeof(int)) + two_d_fetch(d, 1, 1,4, sizeof(int));
    printf("\n\n");

    memoryDump(d, 4*4*sizeof(int));

    two_d_dealloc(d);

    return 0;
}
