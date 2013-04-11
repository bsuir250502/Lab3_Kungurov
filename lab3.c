#include <stdio.h>
#include "mystdlib.h"
#define number_of_floors 3
#define number_of_places 10
#define size_surname 15
FILE *file;
typedef struct hostel {
    int floor;
    int places;
    int free_places;
    char list[number_of_places][size_surname];
    struct hostel *next;
} hostel;
typedef struct queue {
    char surname[size_surname];
    int facult;
    struct queue *next;
} queue;
void enter_data_hostel(hostel * floor_queue_first)
{
    char *str;
    int i, j;
    hostel *floor_queue_current;
    floor_queue_current = floor_queue_first;
    str = (char *) calloc(12, sizeof(char));
    printf("Enter floor");
    my_fgets(str, 5, file);
    floor_queue_first->floor = atoi(str);
    printf("Enter number of places");
    my_fgets(str, 10, file);
    floor_queue_first->places = atoi(str);
    printf("Enter number of free places");
    my_fgets(str, 10, file);
    floor_queue_first->free_places = atoi(str);
    for (j = 0; j < (floor_queue_first->places - floor_queue_first->free_places); j++)
        my_fgets(floor_queue_first->list[j], size_surname, file);
    for (i = 0; i < (number_of_floors - 1); i++) {
        floor_queue_current = floor_queue_current->next = (hostel *) calloc(1, sizeof(hostel));
        printf("Enter floor");
        my_fgets(str, 5, file);
        floor_queue_current->floor = atoi(str);
        printf("Enter number of places");
        my_fgets(str, 10, file);
        floor_queue_current->places = atoi(str);
        printf("Enter number of free places");
        my_fgets(str, 10, file);
        floor_queue_current->free_places = atoi(str);
        for (j = 0; j < ((floor_queue_current->places) - (floor_queue_current->free_places)); j++)
            my_fgets(floor_queue_current->list[j], size_surname, file);
    }
}

int settlement(hostel * floor_queue_first, queue * settelment_queue_current)
{
    char str1[size_surname + 3], str2[5];
    int n;
    hostel *floor_queue_current;
    floor_queue_current = floor_queue_first;
    if (!strcmp("end", my_fgets(str1, size_surname + 4, file))) {
        printf("Найден end");
        return 0;
    }
    puts(str1);
    printf("\n\n %s",str1);
    my_fgets(str2, 4, file);
    n = atoi(str2);
    while (1) {
        if (floor_queue_current->floor == n) {
            break;
        }
        floor_queue_current = floor_queue_current->next;
        if (floor_queue_current == NULL) {
            return 0;
        }
    }
    if (floor_queue_current->free_places > 0) {
        puts("\nOOOGOGOGOGOGO\n");
        strcpy(floor_queue_current->list[(floor_queue_current->places) - (floor_queue_current->free_places)], str1);
        floor_queue_current->free_places -= 1;
        return 1;
    }
    else {
        while (1) {
            if (settelment_queue_current->next == NULL) {
                strcpy(settelment_queue_current->surname, str1);
                settelment_queue_current->facult = n;
                settelment_queue_current = settelment_queue_current->next = (queue *) calloc(1, sizeof(queue));
                break;
            }
        }
        return 1;
    }
}

void display_hostel(hostel * floor_queue_first, queue * settelment_queue_first)
{
    hostel *floor_queue_current;
    queue *settelment_queue_current;
    int i, j;
    floor_queue_current = floor_queue_first;
    settelment_queue_current = settelment_queue_first;
    printf("floor: %d\n", floor_queue_first->floor);
    printf("number of places: %d\n", floor_queue_first->places);
    printf("number of free places: %d\n", floor_queue_first->free_places);
    for (j = 0; j < (floor_queue_first->places - floor_queue_first->free_places); j++)
        puts(floor_queue_first->list[j]);
    for (i = 0; i < (number_of_floors - 1); i++) {
        floor_queue_current = floor_queue_current->next;
        printf("floor: %d\n", floor_queue_current->floor);
        printf("number of places: %d\n", floor_queue_current->places);
        printf("number of free places: %d\n", floor_queue_current->free_places);
        for (j = 0; j < (floor_queue_current->places - floor_queue_current->free_places); j++) {
            puts(floor_queue_current->list[j]);
        }
    }
    puts("string of stud");
    while(settelment_queue_current -> next != NULL){
        puts(settelment_queue_current -> surname);
        settelment_queue_current = settelment_queue_current -> next;
    }
}

int main(int argc, char **argv)
{
    hostel *floor_queue_first, *floor_queue_current;
    queue *settelment_queue_first, *settelment_queue_current;
    int i;
    if (argc == 2) {
        if ((strcmp(argv[1], "-h")) == 0) {
            puts("Instructions for use:");

            /* any instuctions */
            return 0;
        }
    }
    if (!(file = fopen("test.txt", "r")))
        puts("NOOOOOOOOB");

    else
        puts("");
    settelment_queue_first = (queue *) calloc(1, sizeof(queue));
    settelment_queue_current = settelment_queue_first;
    floor_queue_first = (hostel *) calloc(1, sizeof(hostel));
    floor_queue_current = floor_queue_first->next = (hostel *) calloc(1, sizeof(hostel));
    for (i = 0; i < (number_of_floors - 3); i++)
        floor_queue_current = floor_queue_current->next = (hostel *) calloc(1, sizeof(hostel));
    floor_queue_current->next = NULL;
    enter_data_hostel(floor_queue_first);
    while (1) {
        if (!settlement(floor_queue_first, settelment_queue_current)) {
            break;
        }
    }
    display_hostel(floor_queue_first, settelment_queue_first);
    fclose(file);
    return 0;
}
