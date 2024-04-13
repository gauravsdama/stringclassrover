#Rover Command Processor

The Rover Command Processor is a simple program written in C++ that simulates a rover's command execution based on input commands provided in text files. It utilizes a custom implementation of a string class (MyString) and a Rover class to process commands such as printing, reading, clearing, joining strings, testing, and finding substrings.

Purpose

The purpose of this project is to create a fun custom version of a string class specifically tailored for usage in a Mars rover environment. As traditional string manipulation libraries may not be suitable for the unique challenges and constraints of space exploration missions, this project aims to develop a lightweight, efficient, and reliable string handling solution optimized for the rover's operations.

Command Files

  The input command files contain commands to be executed by the Rover. Each command file should have one command per line, with each command consisting of an operation and optional data.

  Command Operations

    SCAN: Scans a string.
    PRINT: Prints the current string.
    READ: Reads a character at the specified index.
    CLEAR: Clears the current string.
    JOIN: Joins a string to the current string.
    TEST: Tests a new string by joining it to the current string.
    FIND: Finds a substring in the current string.

Classes

    MyString: Custom implementation of a string class.
    Rover: Class to process rover commands using the MyString class.
