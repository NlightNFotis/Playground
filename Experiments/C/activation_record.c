/* This program demonstrates activation records in C.
 * When you first learn C in school, or via a book or tutorial,
 * or something, the first thing you learn is that if you leave
 * a variable uninitialized, it contains "garbage". 
 *
 * If you learn a little bit more about how C implementations work
 * for that matter, or how programs execute, or delve into reverse
 * engineering a little bit, you learn that it's not garbage at all.
 * The specific implementation may suggest that the value of the 
 * uninitialized variable is undefined, however, most of the time
 * in most of the implementations, it's the specific value that was
 * initialized at that specific activation record (stack frame) by
 * a previous function.
 */

#include <stdio.h>

/* This function's sole purpose is to
 * allocate 4 bytes in the stack (a typical size for an integer
 * in a 32 bit or 64 bit architecture, though still, implementation
 * specific), initialize the space with the integral value of 10,
 * and then proceed to return, effectively deallocating the stack
 * frame.
 */
void 
first (void)
{
    int a = 10;
    return;
}

/* Now, when this function runs, after the first one has run,
 * since both of them have the same header, they will allocate
 * the same amount of space for parameters and local variables.
 * This will result in the function allocating the size of an
 * integer (which was previously occupied by a in first(), and
 * initialized with 10), and avoid to initialize it with a specific
 * value (maintaining the value that was initialized at the previous
 * stack frame), and then proceed with printing that value.
 */
void 
second (void)
{
    int a;
    printf("a is %d\n", a);
    return;
}

int
main (void)
{
    first  ();
    second ();
    return 0;
}
