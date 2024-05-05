/*
Write a calendar program using enums. 

 

Your task is to write a program that will use separate enums for days of the week (Mon, Tue, etc) and Weeks (week 1, week 2, ..., week 5). 
The program should increment the day every second. After Sunday, the week should increment as well and the counting should start from the beginning. 
Once it gets to week 5, it should stop. 

The program should ask the user to provide the start day and week. Every time the program increments the day, it should write the week and day on the console.

For example the interaction should be:

Provide starting week: 

1
Provide starting day number 1 for monday two for tuesday etc.: 

1
Output: 

Week 1, Monday
Week 1, Tuesday
...
You are NOT allowed to use strings to store the days and weeks. Your program should also check for the correct input from the user.
*/

#include <stdio.h> //this is for printing
#include <unistd.h> // this is for sleep
#include <stdlib.h> // this is for atoi 

// enum for weekdays 
enum weekday{Mon=1, Tue, Wed, Thu, Fri, Sat, Sun};

int main(){
    // im using char to store integer to get rid of new line
    char startingWeekString[6];
    // scanning the user input
    scanf("%s", startingWeekString);
    // turning it into integer
    int startingWeek= atoi(startingWeekString);
    
    // im using char to store integer to get rid of new line
    char startingDayString[6];
    // scanning the user input
    scanf("%s", startingDayString);
    // turning it into integer
    int startingDay= atoi(startingDayString);

    // if the starting is in invalid rand and startingday is in invalid print invalid
    if ((startingWeek > 5|| startingWeek <= 0) && (startingDay > 7|| startingDay <= 0)) {
        printf("invalid");
        // if only startingweek is iin invalid range print invalid week
    } else if (startingWeek > 5 || startingWeek <= 0) {
        printf("invalid week");
         // if only startingDay is in invalid range  print invalid day
    } else if (startingDay > 7|| startingDay <= 0) {
        printf("invalid day");
    }
    // here we have for loop that goes through weeks from given week until week 5
    for(int weekcounter =startingWeek; weekcounter <=5; weekcounter++){
        // here we have loop that goes from given day until week 5
        for(int dayIterator = startingDay; dayIterator<= Sun; dayIterator++){
             printf("Week %d, ", weekcounter);
             //if the dayitteratior is in mon print monday, tue tuesday etc.
             switch (dayIterator) {
                case Mon:
                    printf("Monday");
                    break;
                case Tue:
                    printf("Tuesday");
                    break;
                case Wed:
                    printf("Wednesday");
                    break;
                case Thu:
                    printf("Thursday");
                    break;
                case Fri:
                    printf("Friday");
                    break;
                case Sat:
                    printf("Saturday");
                    break;
                case Sun:
                    printf("Sunday");
                    break;
            }
            // after each loop reset the startingpoint of week
            startingDay=Mon;
            printf("\n");
            // waiting one second between weeks
            sleep(1);
        }
    }
    // returning zero indicating that it is successfull
    return 0;
}