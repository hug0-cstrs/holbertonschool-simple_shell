![Holberton School logo](https://user-images.githubusercontent.com/120781178/229278297-98c6e4b7-f15f-4788-a893-15cb97f10351.png)

# :mortar_board: C - Simple Shell

Second group project at Holberton School : implement our own simplified version of a UNIX command line interpreter in C.


## Description :scroll:

The objective of this project is to create from scratch a simple UNIX command interpreter with limited functionality but applying the core concepts of a more robust shell. In simple words, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. It incorporates many features and generally executes other commands.

## Technologies & Tools :computer:

![Ubuntu](https://img.shields.io/badge/≡-Ubuntu-E95420?&style=flat-square&logo=Ubuntu&labelColor=282828)
![Git](https://img.shields.io/badge/≡-Git-F05032?logo=git&style=flat-square&labelColor=282828)
![GNU_Bash](https://img.shields.io/badge/≡-GNU_Bash-4EAA25?logo=GNU-Bash&style=flat-square&labelColor=282828)
![Vim](https://img.shields.io/badge/≡-Vim-019733?logo=Vim&style=flat-square&logoColor=019733&labelColor=282828)
![C](https://img.shields.io/badge/≡-C-A8B9CC?logo=C&style=flat-square&labelColor=282828)
![GitHub](https://img.shields.io/badge/≡-GitHub-181717?logo=GitHub&style=flat-square&labelColor=282828)
![GitHub](https://img.shields.io/badge/≡-Docker-1563FF?logo=Docker&style=flat-square&logoColor=1563FF&labelColor=282828)
![GitHub](https://img.shields.io/badge/≡-Linux-181717?logo=Linux&style=flat-square&labelColor=282828)
![GitHub](https://img.shields.io/badge/≡-Markdown-A8B9CC?logo=Markdown&style=flat-square&labelColor=282828)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Brave](https://img.shields.io/badge/Brave-FB542B?style=for-the-badge&logo=Brave&logoColor=white)
![Google Chrome](https://img.shields.io/badge/Google%20Chrome-4285F4?style=for-the-badge&logo=GoogleChrome&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)
![Trello](https://img.shields.io/badge/Trello-%23026AA7.svg?style=for-the-badge&logo=Trello&logoColor=white)
![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)

---

## Requirements :exclamation:
Installed gcc (GNU Compiler Collection) version 9.4.0 or newer.

---

## Examples :hammer_and_wrench:
### Clone repository using HTTPS
```
git clone https://github.com/v-dav/holbertonschool-simple_shell.git
```

### Compilation
You can compile the files using this command to check that there are no errors:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Valgrind
root@id:~/holbertonschool-simple_shell$ valgrind ./hsh
==23753== Memcheck, a memory error detector
==23753== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23753== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==23753== Command: ./hsh
==23753== 
/bin/ls
README.md  _getline.c  _strtok.c          hsh     path_values.c   simple_shell.h
_free.c    _strfunc.c  execute_command.c  main.c  search_path1.c
==23753== 
==23753== HEAP SUMMARY:
==23753==     in use at exit: 0 bytes in 0 blocks
==23753==   total heap usage: 142 allocs, 142 frees, 18,486 bytes allocated
==23753== 
==23753== All heap blocks were freed -- no leaks are possible
==23753== 
==23753== For lists of detected and suppressed errors, rerun with: -s
==23753== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@id:~/holbertonschool-simple_shell$

---

## Authors
* **Vladimir Davidov** - [Vladimir](https://github.com/v-dav)
* **Hugo CAstéras** - [Hugo](https://github.com/hug0-cstrs)
