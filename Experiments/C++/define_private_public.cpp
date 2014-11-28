/* Before this file begins, this is an experiment conducted to test #define macro magic.
 * I remember reading in a book that the access modifiers protect against stupidity and 
 * not malice, and I thought about running this small experiment of corrupting the 
 * definition of an access modifier right before I import a class, and see what happens.
 */

#include <iostream>

#define private public
#include "rect.hpp"
#undef private

int
main (void)
{
  Rectangle rect;
  
  // I shouldn't be able to do that
  rect.width = 5;
  
  std::cout << "Rectangle's width: " << rect.width << std::endl;
  return 0;  
}

