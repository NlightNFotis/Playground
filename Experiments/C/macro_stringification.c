/* This is a simple example of the usage of the ISO stringification
 * operator '#' to stringify the value passed to the macro
 */

#include <stdio.h>

#define FOO    1
#define BAR    2
#define FOOBAR 3

#define STRINGIFY(val) #val

void 
get_value (int val) 
{
    switch (val) {
        case FOO:
            printf ("The value is %s\n", STRINGIFY(FOO)); break;
        case BAR:
            printf ("The value is %s\n", STRINGIFY(BAR)); break;
        case FOOBAR:
            printf ("The value is %s\n", STRINGIFY(BAZ)); break;
    }
}

int
main (void)
{
    get_value (FOOBAR);
    get_value (BAR);
    return 0;
}

