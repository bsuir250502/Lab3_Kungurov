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
void enter_data_hostel(hostel * p)
{
    char *str;
    int i, j;
    hostel *a;
    a = p;
    str = (char *) calloc(12, sizeof(char));
    printf("Enter floor");
    my_fgets(str, 5, file);
    p->floor = atoi(str);
    printf("Enter number of places");
    my_fgets(str, 10, file);
    p->places = atoi(str);
    printf("Enter number of free places");
    my_fgets(str, 10, file);
    p->free_places = atoi(str);
    for (j = 0; j < (p->places - p->free_places); j++)
        my_fgets(p->list[j], size_surname, file);
    for (i = 0; i < (number_of_floors - 1); i++) {
        a = a->next = (hostel *) calloc(1, sizeof(hostel));
        printf("Enter floor");
        my_fgets(str, 5, file);
        a->floor = atoi(str);
        printf("Enter number of places");
        my_fgets(str, 10, file);
        a->places = atoi(str);
        printf("Enter number of free places");
        my_fgets(str, 10, file);
        a->free_places = atoi(str);
        for (j = 0; j < ((a->places) - (a->free_places)); j++)
            my_fgets(a->list[j], size_surname, file);
    }
}

int settlement(hostel * p, queue * s1)
{
    char str1[size_surname + 3], str2[5];
    int n;
    hostel *a;
    a = p;
    if (!strcmp("end", my_fgets(str1, size_surname + 4, file))) {
        printf("Найден end");
        return 0;
    }
    puts(str1);
    printf("\n\n %s",str1);
    my_fgets(str2, 4, file);
    n = atoi(str2);
    while (1) {
        if (a->floor == n) {
            break;
        }
        a = a->next;
        if (a == NULL) {
            return 0;
        }
    }
    if (a->free_places > 0) {
        puts("\nOOOGOGOGOGOGO\n");
        strcpy(a->list[(a->places) - (a->free_places)], str1);
        a->free_places -= 1;
        return 1;
    }
    else {
        while (1) {
            if (s1->next == NULL) {
                strcpy(s1->surname, str1);
                s1->facult = n;
                s1 = s1->next = (queue *) calloc(1, sizeof(queue));
                break;
            }
        }
        return 1;
    }
}

void display_hostel(hostel * p, queue * s)
{
    hostel *a;
    queue *s1;
    int i, j;
    a = p;
    s1 = s;
    printf("floor: %d\n", p->floor);
    printf("number of places: %d\n", p->places);
    printf("number of free places: %d\n", p->free_places);
    for (j = 0; j < (p->places - p->free_places); j++)
        puts(p->list[j]);
    for (i = 0; i < (number_of_floors - 1); i++) {
        a = a->next;
        printf("floor: %d\n", a->floor);
        printf("number of places: %d\n", a->places);
        printf("number of free places: %d\n", a->free_places);
        for (j = 0; j < (a->places - a->free_places); j++) {
            puts(a->list[j]);
        }
    }
    puts("string of stud");
    while(s1 -> next != NULL){
        puts(s1 -> surname);
        s1 = s1 -> next;
    }
}

int main(int argc, char **argv)
{
    hostel *p, *a;
    queue *s, *s1;
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
    s = (queue *) calloc(1, sizeof(queue));
    s1 = s;
    p = (hostel *) calloc(1, sizeof(hostel));
    a = p->next = (hostel *) calloc(1, sizeof(hostel));
    for (i = 0; i < (number_of_floors - 3); i++)
        a = a->next = (hostel *) calloc(1, sizeof(hostel));
    a->next = NULL;
    enter_data_hostel(p);
    while (1) {
        if (!settlement(p, s1)) {
            break;
        }
    }
    display_hostel(p, s);
    fclose(file);
    return 0;
}
