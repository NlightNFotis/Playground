/* This must be compiled with the flag -nostdlib because otherwise the
 * linker will complain about multiple definitions of the symbol _start
 * (one here and one in glibc) and a missing reference to symbol main
 * (that the libc expects to be linked against).
 */

void 
_start ()
{
    /* calling the write system call, with the arguments in this order:
     * 1. the stdout file descriptor
     * 2. the buffer we want to print (Here it's just a string literal).
     * 3. the amount of bytes we want to write.
     */
    asm ("int $0x80"::"a"(4), "b"(1), "c"("Hello world!\n"), "d"(13));
    asm ("int $0x80"::"a"(1), "b"(0)); /* calling exit syscall, with the argument to be 0 */
}
