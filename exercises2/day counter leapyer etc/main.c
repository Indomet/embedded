/******************************************************************************

Write a program that, given a date, three ints (for example, 11 27 1997), will print the number of
that day within its year: i.e. Jan 1st is always 1, Dec 31st is either 365 or 366.
The months of the year have lengths according to the following rules:
" The odd months up to and including month 7 have 31 days.
" The even months from 8 upwards, have 31 days.
" Month 2 has 28 days except in a leap year when it has 29 days.
" The rest of the months have 30 days.
*******************************************************************************/
#include <stdio.h>
void calculate ();
int
main ()
{

  calculate ();
  return 0;
}

void
calculate ()
{
  int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int month;
  int day;
  int year;
  printf ("month day and year:");
  scanf ("%d %d %d", &month, &day, &year);

  for (int i = 1; i < month + 1; i++)
	{
	  day += months[i];
	}
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
	  day + 1;
	}
  printf ("%d", day);
}

// #include <stdio.h>

// // Function to check if a given year is a leap year
// int isLeapYear(int year) {
//     // Leap year is divisible by 4 but not divisible by 100 unless divisible by 400
//     if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//         return 1; // Leap year
//     } else {
//         return 0; // Not a leap year
//     }
// }

// // Function to calculate the day number within the year
// int dayOfYear(int month, int day, int year) {
//     // Array to hold the number of days in each month
//     int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int leapYear = isLeapYear(year); // Check if the year is a leap year
//     int dayNumber = 0; // Initialize the day number

//     // Add days of months passed in the year
//     for (int i = 1; i < month; i++) {
//         dayNumber += daysInMonth[i]; // Add days of each month before the current month
//     }

//     // Add one day if current month is February and it's a leap year
//     if (month > 2 && leapYear) {
//         dayNumber += 1;
//     }

//     // Add current day
//     dayNumber += day;

//     return dayNumber; // Return the calculated day number within the year
// }

// int main() {
//     int month, day, year;

//     // Input date from user
//     printf("Enter the date (month day year): ");
//     scanf("%d %d %d", &month, &day, &year);

//     // Validate month and day
//     if (month < 1 || month > 12 || day < 1 || day > 31) {
//         printf("Invalid date\n");
//         return 1; // Exit program with error code 1
//     }

//     // Validate February in leap years
//     if (month == 2 && day > 29 && isLeapYear(year)) {
//         printf("Invalid date\n");
//         return 1; // Exit program with error code 1
//     }

//     // Calculate and print the day number within the year
//     printf("Day number within the year: %d\n", dayOfYear(month, day, year));

//     return 0; // Exit program successfully
// }
