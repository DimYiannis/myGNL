# Get Next Line

> A 42 School project that implements a function to read a line from a file descriptor — one line at a time, with proper memory management.

---

##  Project Overview

The goal of **Get Next Line** is to write a function that returns a line read from a file descriptor, ending with a newline (`'\n'`) if one is present.

This project helps you understand:
- Static variables and persistent state between function calls
- File descriptors and the `read()` system call
- Memory management (allocation, freeing, and leaks)
- String manipulation and dynamic concatenation

---

## Function Prototype
char *get_next_line(int fd);

## Description

Reads a single line from the file descriptor fd.

Successive calls return subsequent lines from the same file.

The function uses a static variable to preserve data between calls.

Returns NULL when there’s nothing more to read or an error occurs.

## How It Works

get_next_line reads chunks of text of size BUFFER_SIZE from a file descriptor using read(), and builds complete lines dynamically.

## Main steps:

Read into a temporary buffer.

Join it with any leftover data (stash).

Extract a full line (up to \n).

Save the remaining text for the next call.
