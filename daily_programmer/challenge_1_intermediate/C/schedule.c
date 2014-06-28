#include <stdio.h>
#include <stdlib.h>
#include "schedule.h"

// The start of the events list
event_t *head = NULL;

void
help (void)
{
    printf ("Event organizer v0.1\n");
    printf ("Enter 1 in the prompt, to add an event.\n");
    printf (" - Adding an event will prompt you to enter a name for it,\n");
    printf ("   a description, and a date for it.\n");
    printf ("Enter 2 in the prompt, to delete an event.\n");
    printf (" - You will be prompted to enter the event's name.\n");
    printf ("Enter 3 in the prompt, to edit an event.\n");
    printf (" - You will be prompted to enter the event's name.\n");
    printf ("Enter 4 in the prompt to see all events.\n");
    printf ("Enter 0 to exit the program.\n");
    printf ("\n");
}

int
main (void)
{
    help ();
    parse_choice ();

    return 0;
}

void
parse_choice (void)
{
    int user_choice;
    char temp;

    // print a user prompt
    printf ("Enter a number to perform an operation.\n");
    printf ("> ");

    scanf ("%d", &user_choice);
    scanf ("%c", &temp); // consume trailing whiteline that seems to confuse add_event()

    switch (user_choice) {
        case -1:
            help ();
            break;
        case 1:
            add_event ();
            printf ("[DEBUG] Got a 1.\n");
            break;
        case 2:
//            delete_event ();
            printf ("[DEBUG] Got a 2.\n");
            break;
        case 3:
//            edit_event ();
            printf ("[DEBUG] Got a 3.\n");
            break;
        case 4:
//            view_events ();
            printf ("[DEBUG] Got a 4.\n");
            break;
        case 0:
//            exit(0);
            printf("[DEBUG] Exiting...\n");
            exit (0);
        default:
            printf ("That's not valid input, unfortunately.\n");
            printf ("Enter a number from 0 up to 4.\n");
            printf ("If you want to take a look at what those choices offer,");
            printf ("enter -1 for help.\n");
    }

    // This function acts as the program's loop,
    // so naturally, we are going to call it again, to continue
    // processing events.
    parse_choice ();
}

void
add_event (void)
{
    char name[256];
    char description[1024];
    event_t *current;

    // date vars
    int year;
    int month;
    int day;
    int hour;

    printf ("Enter a name for the event.\n");
    fgets  (name, sizeof (name), stdin);
    printf ("[DEBUG] Entered name %s\n", name);

    printf ("Enter a description for the event.\n");
    fgets  (description, sizeof (description), stdin);
    printf ("[DEBUG] Entered description %s\n", description);

    printf ("Enter a date for the event.\n");
    printf (" - Enter the year: ");
    scanf  ("%d", &year);
    printf ("\n - Enter the month: ");
    scanf  ("%d", &month);
    printf ("\n - Enter the day: ");
    scanf  ("%d", &day);
    printf ("\n - Enter the hour: ");
    scanf  ("%d", &hour);

    if (month < 1 || month > 12) {
        printf ("Invalid input on month. Aborting.\n");
        exit   (-1);
    }

    if (day < 1 || day > 30) {
        printf ("Invalid input on day. Aborting.\n");
        exit   (-1);
    }

    if (hour < 1 || hour > 24) {
        printf ("Invalid input on hour. Aborting.\n");
        exit   (-1);
    }

    printf ("[DEBUG] Entered %d-%d-%d:%d", day, month, year, hour);
    
    //XXX List adding logic should be decoupled.
    //XXX I am assigning to heap objects stack based ones
    //XXX it's extremely error prone, and I'm gonna pay for it soon
    //XXX Maybe I should create heap based objects, copy the strings
    //XXX on them and then assign them to the struct members
    // Add the event on the list;
    if (head == NULL) {
        head = malloc (sizeof (event_t));
        head->name        = name;
        head->description = description;
        head->date->year  = year;
        head->date->month = month;
        head->date->day   = day
        head->date->hour  = hour;
        head->next        = NULL;
    } else {
        current = head->next;
        while (current->next != null) {
            current = current->next;
        }
        current = malloc (sizeof (event_t));
        current->name        = name;
        current->description = description;
        current->date->year  = year;
        current->date->month = month;
        current->date->day   = day;
        current->date->hour  = hour;
        current->next        = NULL;
    }
}

