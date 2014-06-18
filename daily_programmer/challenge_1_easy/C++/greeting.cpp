#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int
main (void)
{
    std::string name;
    std::string username;
    int age;
    std::ofstream log_file;

    std::cout << "What's your name?" << std::endl;
    std::cin >> name;

    std::cout << "What's your age?" << std::endl;
    std::cin >> age;

    std::cout << "What's your reddit username?" << std::endl;
    std::cin >> username;

    // Construct something like a format string to use with output and logging
    std::stringstream ss;
    ss << "Your name is " << name << " you are " << age << " years old and your username is " << username;
    std::string resulting_string = ss.str();

    std::cout << resulting_string << std::endl;

    // Log the output in a file
    log_file.open ("log.txt");
    log_file << resulting_string;
    log_file.close ();
    
    return 0;
}
