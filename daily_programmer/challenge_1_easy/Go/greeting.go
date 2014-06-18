package main

import (
    "fmt"
    "io/ioutil"
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
    resulting_bytes := []byte(resulting_string)
    
    fmt.Println(resulting_string)
    err := ioutil.WriteFile("log.txt", resulting_bytes, 0644)
    if err != nil { panic(err) } 
}

