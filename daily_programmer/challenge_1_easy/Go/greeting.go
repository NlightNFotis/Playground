package main

import (
	"fmt"
	"os"
)

func main() {
	var name string
	var age int
	var reddit_username string

	fmt.Println("What is your name?")
	fmt.Scanln(&name)

	fmt.Println("What is your age?")
	fmt.Scan(&age)

	fmt.Println("What is your username in Reddit?")
	fmt.Scanln(&reddit_username)

	// create a format string to use for logging and stdoutput
	resulting_string := fmt.Sprintf("Your name is %s, you are %d years old, and your username is %s",
		name, age, reddit_username)

	fmt.Println(resulting_string)

	// Write the resulting string to a log file.
	f, err := os.Create("log.txt")
	if err != nil {
		panic(err)
	}
	f.WriteString(resulting_string)
	defer f.Close()
}
