/* This particular code is taken from https://jroweboy.github.io/c/asm/2015/01/26/when-is-main-not-a-function.html
 * and I have keeped it here because it demonstrates something very interesting to me. That main doesn't even need
 * to be a function.
 *
 * This will make the compiler complain if you pass -Wmain (or -Wall for that matter).
 */

/* These values are extracted from the decimal representation of the instructions
 * of a hello world program written in asm, that gdb provides.
 */
const int main[] = {
    -443987883, 440, 113408, -1922629632,
    4149, 899584, 84869120, 15544,
    266023168, 1818576901, 1461743468, 1684828783,
    -1017312735
};
