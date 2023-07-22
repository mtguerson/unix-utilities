## **Overview**

The commands "cat", "grep", "unzip" and "zip" are very used
on Linux and Unix systems for file manipulation. In C, it is
possible to write programs that perform the same tasks as
these commands.

These are four programs doing such commands.


#### **INSTALLATION GUIDE**

- Clone this repository

- Ensure that you are working from the main branch, it is the most stable at any given time for this project.

- Open a terminal and navigate to the directory where the Makefile is located.

- Run the command `make all` to compile all programs. This will create four executable files: wcat, wgrep, wzip, and wunzip.

- To run the wcat program, run the command `./wcat [filename]`, where filename is the name of the file you want to read.

- To run the wgrep program, run the command `./wgrep [search_term] [filename]`, where search_term is the term you want to search for and filename is the name of the file you want to search.

- To run the wzip program, run the command `./wzip [filename]`, where filename is the name of the file you want to compress.

- To run the wunzip program, run the command `./wunzip [filename]`, where filename is the name of the file you want to decompress.

- To remove all executable files, run the command `make clean`.

#### **AUTHOR**

- Matheus Guerson - Computer Science student at UFMS - Brazil - MS

I am always open to receiving constructive criticism and suggestions for improvement in our developed code. I believe that feedback is an essential part of the learning and growth process, and I am eager to learn from others and make my code the best it can be. Whether it's a minor tweak or a major overhaul, I am willing to consider all suggestions and implement the changes that will benefit my code and its users.
