#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "mystdlib.h"
#define number_of_floors 3
#define number_of_places 4
#define size_surname 15
FILE *file;


typedef struct hostel {
    int floor;
    int places;
    int free_places;
    char list[number_of_places][size_surname+4];
    struct hostel *next;
} hostel;
typedef struct queue {
    char surname[size_surname];
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
    for (j = 0; floor_queue_first->free_places != 0 ; j++){
        my_fgets(str, size_surname, file);
		if (strcmp("end",str)==0) { break;}
		strcpy(floor_queue_first->list[j],str);
		floor_queue_first->free_places-=1;
	}
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
        for (j = 0;floor_queue_current->free_places != 0 ; j++){
			my_fgets(str, size_surname, file);
			if (strcmp("end",str)==0) { break;}
			strcpy(floor_queue_current->list[j],str);
			floor_queue_current->free_places-=1;
		}
    }
    floor_queue_current -> next = NULL;
}

int settlement(hostel * floor_queue_first, queue * settelment_queue_current)
{
    char *str1;
    hostel *floor_queue_current;
	str1 = (char*)calloc(size_surname,sizeof(char));
    floor_queue_current = floor_queue_first;
    my_fgets(str1, size_surname, file);
    if (!strcmp("end", str1)) {
        return 0;
    }
    while (1) {
        if (floor_queue_current->free_places > 0) {
            break;
        }
        if (floor_queue_current -> next == NULL) {
            break;}
        floor_queue_current = floor_queue_current->next;
    }
    if (floor_queue_current -> next == NULL) {
        while (1) {
            if (settelment_queue_current->next == NULL) {
                strcpy(settelment_queue_current->surname, str1);
                settelment_queue_current = settelment_queue_current->next = (queue *) calloc(1, sizeof(queue));
                break;
            }
            else {
                settelment_queue_current = settelment_queue_current -> next;
            }
        }
        return 1;
    }
    else {
        strcpy(floor_queue_current->list[(floor_queue_current->places) - (floor_queue_current->free_places)], str1);
        floor_queue_current->free_places -= 1;
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
    printf("    floor: %d\n", floor_queue_first->floor);
    printf("    number of places: %d\n", floor_queue_first->places);
    printf("    number of free places: %d\n", floor_queue_first->free_places);
    for (j = 0; j < (floor_queue_first->places - floor_queue_first->free_places); j++)
        puts(floor_queue_first->list[j]);
    for (i = 0; i < (number_of_floors - 1); i++) {
        floor_queue_current = floor_queue_current->next;
        printf("    floor: %d\n", floor_queue_current->floor);
        printf("    number of places: %d\n", floor_queue_current->places);
        printf("    number of free places: %d\n", floor_queue_current->free_places);
        for (j = 0; j < (floor_queue_current->places - floor_queue_current->free_places); j++) {
            puts(floor_queue_current->list[j]);
        }
    }
    puts("    List of students:");
    while(settelment_queue_current -> next != NULL){
        puts(settelment_queue_current -> surname);
        settelment_queue_current = settelment_queue_current -> next;
    }
}

int main(int argc, char **argv)
{
    hostel *floor_queue_first, *floor_queue_current;
    queue *settelment_queue_first, *settelment_queue_current;
    if (argc == 2) {
        if ((strcmp(argv[1], "-h")) == 0) {
            puts("Instructions for use:");
            puts("Open test.txt in the program's folder");
            puts("2.Enter the information in the following format (for 3 floors): ");
            puts("floor");
            puts("number of places");
            puts("number of free places");
            puts("surname of student (every name on a new line. If you want to enter the names of less than the number of available seats, enter 'end')");
            puts("floor");
            puts("number of places");
            puts("number of free places");
            puts("surname of student (every name on a new line. If you want to enter the names of less than the number of available seats, enter 'end')");
            puts("floor");
            puts("number of places");
            puts("number of free places");
            puts("surname of student (every name on a new line. If you want to enter the names of less than the number of available seats, enter 'end')");
            puts("surname of student to settlement (every name on a new line. If you want to enter the names of less than the number of available seats, enter 'end')");
            puts("Save and run program");
            return 0;
        }
    }
    if (!(file = fopen("test.txt", "rt")))
        puts("NOOOOOOOOB");

    else
        puts("");
    settelment_queue_first = (queue *) calloc(1, sizeof(queue));
    settelment_queue_current = settelment_queue_first;
    floor_queue_first = (hostel *) calloc(1, sizeof(hostel));
    floor_queue_current = floor_queue_first;
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

#ifdef __cplusplus
}
#endif
