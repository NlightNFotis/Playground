#!/usr/bin/env python3

print("What is your name?")
name = input('--> ')

print("What's your age?")
age = int(input('--> '))

print("What's your reddit username?")
username = input('--> ')

resulting_string = "Your name is {0}, you are {1} years old and your username is {2}".format(name, age, username)
print(resulting_string)

log_file = open("log.txt", 'w')
log_file.write(resulting_string)
log_file.close()
