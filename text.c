#include <stdio.h>
#include "Data Structures/Queue.h"


int main(){
    struct Queue list = queue_constructor();

    // for (int i=0; i<10; i++){
    //     int x[3] = {i, i+1, i+2};
    //     list.push(&list, &x, Int , 3);
    // }

//     for (int i = 0; i < 10; i++) {
//     int *x = malloc(3 * sizeof(int));
//     if (x == NULL) {
//         fprintf(stderr, "Memory allocation failed\n");
//         exit(1);
//     }
//     x[0] = i;
//     x[1] = i + 1;
//     x[2] = i + 2;
//     list.push(&list, x, Int, 3);
// }

    for(int i=0; i<10; i++){
        int * x = malloc(sizeof(int));
        if (x == NULL){
            printf("error while allocating memory");
        }
        *x = i;
        list.push(&list, x, Int, sizeof(int));
    }

    // for (int i=0; i<10; i++){
    //     printf("[%d, %d, %d]\n", ((int*)list.peek(&list))[0], ((int*)list.peek(&list))[1], ((int*)list.peek(&list))[2]);
    //     list.pop(&list);
    // }

    for(int i=0; i<10; i++){
        printf("%d\n", *((int*)list.peek(&list)));
        list.pop(&list);
    }
    queue_destructor(&list);
}