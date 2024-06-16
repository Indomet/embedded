
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MENU_OPTIONS_LENGTH 5
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON* inrecord); // Creates a file and
// writes the first record
void printfile(void); // Prints out all persons in the file
// added parameter to know which one to search by
void search_by_first_or_last(char* name, bool search_by_firstname); // Prints out the person if
void append_file(PERSON* inrecord); // appends a new person to the file
void clear_buffer(void); // function to clear buffer
int main(int argc, char* argv[]) {
    // int c to store choice
    int c;
    // char arrays to store the name
    char fname[20];
    // store fam name
    char famname[20];
    // store personnummer
    char personnummer[13];
    // menu options lsit to iterate over
    const char* MENU_OPTIONS[5] = {
        "Create a new and delete the old file.",
        "Add a new person to the file.",
        "Search for a person in the file.",
        "Print out all in the file.",
        "Exit the program."
    };
    // do while loop. to choose options
    do {
        printf("Choose your option\n");
        // iterate over the menu options and print them
        for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) {
            printf("%d. %s\n", (i + 1), MENU_OPTIONS[i]);
        }
        // get the choice
        scanf("%d", &c);
        clear_buffer();
        // switch case to see the input
        switch (c) {
        // if the choice is 1
        case 1:;
            // create a dummy person
            PERSON dummy_data = { "asim\0", "uwu\0", "942394" };
            // write dummy data to file
            write_new_file(&dummy_data);
            // break out of the switch case
            break;
        case 2:;
            printf("Write your first name, family name, and personummer\n");
            // allocate memory to a new person
            PERSON* data = malloc(sizeof(PERSON));
            // get the input
            scanf("%s %s %s", data->firstname, data->famname, data->pers_number);
            // forward data to append file function
            append_file(data);
            // break out of the switch case
            break;
        case 3:;
            // ask the user if they wanna search by first or last name
            int choice;
            printf("Search by first name or last name? type 0 for first name or 1 for last name\n");
            // get the choice
            int result = scanf("%d", &choice);
            printf("result %d\n", result);

            clear_buffer();
            // clear the buffer
            // if the choice is not 0 or 1 or the result is not 1 then its invalid
            if ((choice != 0 && choice != 1) || result != 1) {
                printf("Invalid input\n");
            } else {
                // allocate memory for the name
                char* name = malloc(sizeof(char) * 20);
                printf("Provide a name to search with\n");
                // get the name
                scanf("%s", name);

                printf("Searching for %s\n", name);
                // forward the name and choice to the search function
                search_by_first_or_last(name, choice == 0);
            }
            // break out of the switch case
            break;
        case 4:
            // print the file
            printfile();
            // break out of the switch case
            break;
        case 5:
            printf("Exit the program.\n");

            // break out of the switch case
            break;
        // default case for unrecognized input
        default:
            printf("Invalid option\n");
        }
        // while c isnt case 5 which is exit
    } while (c != 5);
    // return 0 to exit the program
    return 0;
}

// create a new file and write the first record
void write_new_file(PERSON* inrecord) {
    // creat a file ptr
    FILE* fileptr;
    // open the file in write mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "w")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // write the record to the file
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    // close the file
    fclose(fileptr);
}
// appends a new person to the file
void append_file(PERSON* inrecord) {
    if (strlen(inrecord->firstname) > 20 || strlen(inrecord->famname) > 20 || strlen(inrecord->pers_number) > 20) {
        printf("Invalid input\n");
        return;
    }
    // create a file ptr
    FILE* fileptr;
    // open the file in append mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "a")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // write the record to the file
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    // close the file
    fclose(fileptr);
}

// search for a person in the file. It takes in the name and a bool to know if its first or last name
void search_by_first_or_last(char* name, bool search_by_firstname) {
    // create a file ptr
    FILE* fileptr;
    // open the file in read mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "r")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // create a person to store the data
    PERSON person;
    // while we can read from the file. The fread function continues to read each record until it reaches the end of the file
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {
        // if the search by first name is true and the name matches the first name then print it
        if (search_by_firstname && strcmp(name, person.firstname) == 0) {
            printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
            // if the search by first name is false and the name matches the last name then print it
        } else if (!search_by_firstname && strcmp(name, person.famname) == 0) {
            printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
        }
    }
    // close the file
    fclose(fileptr);
}
// prints out all persons in the file
void printfile(void) {
    // create a file ptr
    FILE* fileptr;
    // open the file in read mode and assign it to the file ptr and also check if it was successful
    if ((fileptr = fopen("people.dat", "r")) == NULL) {
        printf("\n Can not create the file");
        // exit with error code 1
        exit(1);
    }
    // create a person to store the data
    PERSON person;
    // while we can read from the file. The fread function continues to read each record until it reaches the end of the file
    while (fread(&person, sizeof(PERSON), 1, fileptr)) {
        printf("first name: %s last name: %s personnumer: %s\n", person.firstname, person.famname, person.pers_number);
    }
    // close the file
    fclose(fileptr);
}

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcopy
#include <stdbool.h>
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON* inrecord); // Creates a file and writes the first record

void printfile(void); // Prints out all persons in the file

void search_by_firstname(char* name); // Prints out the person if  in list

void append_file(PERSON* inrecord); // appends a new person to the file

int main(void) {
    PERSON ppost;
    int menuInput;
    const char* menu[5] = {
        "1. Create a new and delete the old file.",
        "2. Add a new person to the file.",
        "3. Search for a person in the file.",
        "4. Print out all in the file.",
        "5. Exit the program."
    };

    do{

    for (int i = 0; i < 5; i++) {
        printf("%s\n", menu[i]);
    }

    printf("Choose one of the inputs by writing number from 1 to 5\n");
    scanf("%d", &menuInput);
    switch (menuInput) {
    case 1:;
        write_new_file(&ppost);
        printf("file successfully created\n");
        break;
    case 2:
        append_file(&ppost);
        break;
    case 3:
        {
        char name[20];
        printf("Enter first name or last name of the user to find\n");
        scanf("%s", name);
        search_by_firstname(name);
        }
        break;
    case 4:
        printfile();
        break;
    case 5:
        exit(1);
        break;
    default:
        printf("invalid input");
        break;
    }
    } while(menuInput !=5);
    return (0);
}

void write_new_file(PERSON* inrecord){
    FILE *filePtr;
    if((filePtr= fopen("file.bin","wb")) ==NULL){
        printf("can not create the file");
        exit(1);
    }

    strcpy(inrecord->firstname, "asim");
    strcpy(inrecord->famname, "altinisik");
    strcpy(inrecord->pers_number, "19919");
    
    //inrecord is datathat u want to write, 1 intdicaes how many elements is brung written if i write 2 it will write twice, fileptr is where i want to write the data
    fwrite(inrecord, sizeof(PERSON), 1, filePtr);
    fclose(filePtr);

}
void append_file(PERSON* inrecord){
    FILE *filePtr;
    if((filePtr = fopen("file.bin", "ab"))== NULL){
        printf("could not open the file");
        exit(1);
    }
    *inrecord =input_record();
    fwrite(inrecord,sizeof(PERSON), 1 ,filePtr);
    fclose(filePtr);


}

void search_by_firstname(char* name) {
    FILE* filePtr;
    filePtr = fopen("file.bin", "rb");
    // bool found =false;
    if (filePtr == NULL) {
        printf("could not read the file");
        exit(1);
    }

    PERSON fileBin;
    while (fread(&fileBin, sizeof(PERSON), 1, filePtr)) {
        // bool aa =strcmp(fileBin.firstname, name) == 0;
        if (strcmp(fileBin.firstname, name) == 0||strcmp(fileBin.famname, name) == 0) {
            printf("first name: %s\n", fileBin.firstname);
            printf("Family name: %s\n", fileBin.famname);
            printf("Personnummer: %s\n", fileBin.pers_number);
            // found = true;
        }
        
    }
    // if(!found) {
    //     printf("not found\n");
    // }

    fclose(filePtr);
}

PERSON input_record(void) {
    PERSON person;
    printf("enter first name, family name and personnummer by putting spaces between\n");
    scanf("%s %s %s", person.firstname, person.famname, person.pers_number);
    // printf("fName: %s, famName: %s, pernr:%s\n");
    return person;
}

void printfile(void) {
    FILE *filePtr;

    filePtr= fopen("file.bin", "rb");
    if(filePtr==NULL){
        printf("cant open the file");
        exit(1);
    }

    PERSON fileBin;
    while(fread(&fileBin,sizeof(PERSON), 1, filePtr)){
        printf("first name: %s\n", fileBin.firstname);
        printf("Family name: %s\n", fileBin.famname);
        printf("Personnummer: %s\n", fileBin.pers_number);
        printf("\n");
    }
    
    fclose(filePtr);
}
