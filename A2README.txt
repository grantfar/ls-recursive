Assignment 2, CS 3240, Fall 2018

You are to write a C function that will be sent a single command line argument 
that is the name of a directory (absolute or relative) and will then print out 
the names of all files in the file hierarchy from that directory and below IN 
BREADTH FIRST ORDER. It will first report all regular files, and then report and
recurse into directories afterwards. If there is a failure because of permissions,
report that and proceed. 

Note that you will need to use opendir(), readdir(), chdir() a stat() function 
that does not follow symoblic links, the macros that identify file type, and 
(probably) getcwd() to know the path of the directory you are investigating.

You will (should?) use a queue that contains the directory names that have not 
yet been explored. The full path might be appropriate to store, but be sure your
program works when a relative path is given for argv[1] (e.g. ./3240Assignment2 testdir/)

You will provide your own makefile for this assignment. Be sure you compile with
these flags, -Wall -Werror -g -o 3240Assignment2. Your program should
compile with the simple command 'make'. We will run this program on a directory 
structure of our own design, but be sure to run your program with permission problems.

You MUST compile with the flags -Wall -Werror
