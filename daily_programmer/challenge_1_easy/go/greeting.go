package main

import (
    "fmt"
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

    fmt.Println("Your name is", name, ", you are ", age, 
        " years old, and your username is ", reddit_username)
}
