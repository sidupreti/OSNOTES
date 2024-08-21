#include <stdio.h>
#include "custom.h"
#include <stdbool.h>

int bar (int v1, int v2); 
//you are basically telling the compiler that you are expecting a function
//called bar later on in the code and then once it is recognized it will act on it

char g = 'Z'; //avoid using global variables




typedef struct  {double x;
double y;
double z;
}; point_t //makes a type of structure called point_t

typedef int pid_t;

void allocate_memory(){
   int *x =  malloc(sizeof(int)); //allocates mem on the heap
   int *y = x;
   *x = 0; //go to the addresss at pointer x and assign zero, initializes x basically
   free(x); //deallocates the memory
    point_t * p = malloc(sizeof(point_t));
    (*p).x = 99.9;
    free(p);

    int stack_array[10]; //makes room on the stack for 10 integers
    int * heap_array = malloc(10 * sizeof(int)); //allocates space on the heap for 10 ints
    stack_array[12] = 7; //crashes since array goes from 0-10
    heap_array[12] = 7; //same thing

    initialize_array(heap_array,10);
    free(heap_array);


    
}

void do work(){
    int * a = malloc(sizeof(int));
    *a = 5;
    int *b = malloc(sizeof(int));
    *b = 7;
    int c = work(*a,*b);
    free(a);
    free(b);
}

int work (int *x,int * y){
    return *x + *y;
}



int function_name(double arg1, int arg2, char arg 3){
    int i;
    for (int i =0;i<10; i++){




    }
    struct point p1;
    p1.x = 1.9;
    p1.y = -2.5;
    p1.z = 0.3;

    return 0;

}

point_t add_points (point_t p1,point_t p2, point_t p3){
    point_t result;
    result.x = p1.x +p2.x;
    //notice how u keep have to use the word struct, if u make it a typedef like 
    //above it is a lot easier dont have to keep doing this, so here I changed the code
    //so that i can use point_t instead of struct point that way save space
    return result
}

int foo(){
    return bar(7,11);
}

int bar(int v1, int v2){
    return v1 * v2;
}

