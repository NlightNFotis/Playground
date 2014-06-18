#include <stdio.h>
#include <string.h>

int
main (void)
{
    char name[256];
    char reddit_username[256];
    int  age;
    char resulting_string[1024]; // A little bit ugly
    char temp;
    FILE *fp;

    printf ("What is your name? ");
    if (fgets (name, sizeof (name), stdin) != NULL) {   
        /* Remove trailing new line that fgets accepts */
        char *pos;
        if ((pos = strchr (name, '\n')) != NULL)
            *pos = '\0';
    }

    printf ("What is your age? ");
    scanf ("%i", &age);
    scanf ("%c", &temp); // FIXME: consume trailing whitespace

    printf ("What is your reddit username? ");
    if (fgets (reddit_username, sizeof (reddit_username), stdin) != NULL) {
        /* Remove trailing new line that fget accepts */
        char *pos;
        if ((pos = strchr (reddit_username, '\n')) != NULL)
            *pos = '\0';
    }

    /* Create a format string to print and log. */
    sprintf (resulting_string, "Your name is %s, you are %d years old and your username is %s\n", 
            name, age, reddit_username);

    /* Print the information the user gave us. */
    printf (resulting_string);

    /* Open a file and log the output of the program. */
    fp = fopen ("log.txt", "w+");
    fprintf (fp, resulting_string);
    fclose (fp);

    return 0;
}
       
