/* This is a demonstration of Context sensitivity in C. Inspired by an article
 * by Eli Bendersky.
 */

#include <stdio.h>

/* Compile with -DTYPEDEF to see the typedef in place, or -DFUNCTION to see the function
 * effect taking place. Normally, if you compile with both macros you should get an error
 * about a symbol redefinition
 */
#ifdef TYPEDEF
typedef int T;
#endif
#ifdef FUNCTION
int T(int a) { return a; }
#endif

int
main (void)
{
    /* Under normal circumstances, someone might correctly suggest that the code
     * below is a call of function T, with x passed as an argument to the call.
     * Believe it or not, this is a valid declaration of x of the type T. If this
     * is not a known type, it falls back to the standard call to the T function, 
     * with x as argument.
     */

#ifdef FUNCTION
    int x = 10;
    int result = T (x);
    printf("X's value is %d\n", result);
#endif

#ifdef TYPEDEF
    T (x) = 15;
    printf("X's value is %d\n", x);
#endif

    return 0;
}

