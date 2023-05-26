0x18. C - Dynamic libraries
C
 By: Julien Barbier
 Weight: 1
 Project over - took place from Mar 20, 2023 6:00 AM to Mar 21, 2023 6:00 AM
 An auto review will be launched at the deadline
In a nutshell…
Auto QA review: 0.0/31 mandatory & 0.0/20 optional
Altogether:  0.0%
Mandatory: 0.0%
Optional: 0.0%
Calculation:  0.0% + (0.0% * 0.0%)  == 0.0%
Resources
Read or watch:

What is difference between Dynamic and Static library (Static and Dynamic linking)
create dynamic libraries on Linux
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
What is a dynamic library, how does it work, how to create one, and how to use it
What is the environment variable $LD_LIBRARY_PATH and how to use it
What are the differences between static and shared libraries
Basic usage nm, ldd, ldconfig
Copyright - Plagiarism
You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
You are not allowed to publish any content of this project.
Any form of plagiarism is strictly forbidden and will result in removal from the program.
Requirements
C
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are not allowed to use the standard library. Any use of functions like printf, puts, etc… is forbidden
You are allowed to use _putchar
You don’t have to push _putchar.c, we will use our file. If you do it won’t be taken into account
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions and the prototype of the function _putchar should be included in your header file called main.h
Don’t forget to push your header file
Bash
Allowed editors: vi, vim, emacs
All your scripts will be tested on Ubuntu 20.04 LTS
All your files should end with a new line (why?)
The first line of all your files should be exactly #!/bin/bash
A README.md file, at the root of the folder of the project, describing what each script is doing
All your files must be executable
Tasks
0. A library is not a luxury but one of the necessities of life
mandatory
Score: 0.0% (Checks completed: 0.0%)
Create the dynamic library libdynamic.so containing all the functions listed below:

int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
If you haven’t coded all of the above functions create empty ones, with the right prototype.
Don’t forget to push your main.h file in your repository, containing at least all the prototypes of the above functions.

julien@ubuntu:~/0x18. Dynamic libraries$ ls -la lib*
-rwxrwxr-x 1 julien julien 13632 Jan  7 06:25 libdynamic.so
julien@ubuntu:~/0x18. Dynamic libraries$ nm -D libdynamic.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
                 w __cxa_finalize
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
                 w __gmon_start__
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 w _Jv_RegisterClasses
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
                 U write
julien@ubuntu:~/0x18. Dynamic libraries$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    printf("%d\n", _strlen("My Dyn Lib"));
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/0x18. Dynamic libraries$ gcc -Wall -pedantic -Werror -Wextra -L. 0-main.c -ldynamic -o len
julien@ubuntu:~/0x18. Dynamic libraries$ ldd len 
    linux-vdso.so.1 =>  (0x00007fff5d1d2000)
    libdynamic.so => not found
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f74c6bb9000)
    /lib64/ld-linux-x86-64.so.2 (0x0000556be5b82000)
julien@ubuntu:~/0x18. Dynamic libraries$ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
julien@ubuntu:~/0x18. Dynamic libraries$ ldd len
    linux-vdso.so.1 =>  (0x00007fff41ae9000)
    libdynamic.so => ./libdynamic.so (0x00007fd4bf2d9000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd4beef6000)
    /lib64/ld-linux-x86-64.so.2 (0x0000557566402000)
julien@ubuntu:~/0x18. Dynamic libraries$ ./len 
10
julien@ubuntu:~/0x18. Dynamic libraries$ 
Repo:

GitHub repository: alx-low_level_programming
Directory: 0x18-dynamic_libraries
File: libdynamic.so, main.h
     
1. Without libraries what have we? We have no past and no future
mandatory
Score: 0.0% (Checks completed: 0.0%)
Create a script that creates a dynamic library called liball.so from all the .c files that are in the current directory.

julien@ubuntu:~/0x18. Dynamic libraries$ ls *.c
abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c
atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c
julien@ubuntu:~/0x18. Dynamic libraries$ ./1-create_dynamic_lib.sh 
julien@ubuntu:~/0x18. Dynamic libraries$ nm -D --defined-only liball.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
julien@ubuntu:~/0x18. Dynamic libraries$ 
Repo:

GitHub repository: alx-low_level_programming
Directory: 0x18-dynamic_libraries
File: 1-create_dynamic_lib.sh
how do I Create the dynamic library libdynamic.so containing all the functions listed below:

int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);

ChatGPT
To create the dynamic library libdynamic.so containing the listed functions, you'll need to follow these steps:

Step 1: Implement the functions in a source file
Create a C source file, for example, dynamic.c, and implement the functions mentioned in the question. Here's an example implementation:

c
Copy code
#include <unistd.h>

int _putchar(char c) {
    return write(1, &c, 1);
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _abs(int n) {
    return (n < 0) ? -n : n;
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int length = 0;
    while (*s) {
        length++;
        s++;
    }
    return length;
}

void _puts(char *s) {
    while (*s) {
        _putchar(*s);
        s++;
    }
}

char *_strcpy(char *dest, char *src) {
    char *start = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

int _atoi(char *s) {
    int result = 0;
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s) {
        result = result * 10 + (*s - '0');
        s++;
    }
    return sign * result;
}

char *_strcat(char *dest, char *src) {
    char *start = dest;
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

char *_strncat(char *dest, char *src, int n) {
    char *start = dest;
    while (*dest) {
        dest++;
    }
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
    return start;
}

char *_strncpy(char *dest, char *src, int n) {
    char *start = dest;
    while (*src && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }
    return start;
}

int _strcmp(char *s1, char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *_memset(char *s, char b, unsigned int n) {
    char *start = s;
    while (n > 0) {
        *s = b;
        s++;
        n--;
    }
    return start;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *start = dest;
    while (n > 0) {
        *dest = *




User
continue

ChatGPT
Certainly! Apologies for the incomplete response. Here's the continuation:

c
Copy code
    dest = src;
    dest++;
    src++;
    n--;
}
return start;
}

char *_strchr(char *s, char c) {
    while (*s) {
        if (*s == c) {
            return s;
        }
        s++;
    }
    if (*s == c) {
        return s;
    }
    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;
    while (*s && _strchr(accept, *s)) {
        count++;
        s++;
    }
    return count;
}

char *_strpbrk(char *s, char *accept) {
    while (*s) {
        if (_strchr(accept, *s)) {
            return s;
        }
        s++;
    }
    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    while (*haystack) {
        char *h = haystack;
        char *n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) {
            return haystack;
        }
        haystack++;
    }
    return NULL;
}
Step 2: Compile the source file into a dynamic library
To compile the source file dynamic.c into a dynamic library libdynamic.so, use the following command:

csharp
Copy code
gcc -shared -o libdynamic.so dynamic.c
Make sure you have the necessary development libraries installed on your system, and adjust the command if needed (e.g., adding compiler flags or library paths).

After successful compilation, you should have the libdynamic.so dynamic library file.

Note: The above steps assume you are using a Linux or Unix-like system. The process may differ slightly for other operating systems.

That's it! You have now created the dynamic library libdynamic.so containing the listed functions. You can link this library to your programs that require these functions by specifying the library during the compilation process.





User
gcc -shared -o libdynamic.so dynamic.c
dynamic.c: In function ‘_memcpy’:
dynamic.c:135:10: warning: assignment to ‘char’ from ‘char *’ makes integer from pointer without a cast [-Wint-conversion]
  135 |     dest = src;
      |          ^

ChatGPT
Apologies for the mistake in the code. The warning you received is because of an incorrect assignment in the _memcpy function. Here's the corrected version of the _memcpy function:

c
Copy code
char *_memcpy(char *dest, char *src, unsigned int n) {
    char *start = dest;
    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    return start;
}
Please make sure to replace the _memcpy function in your dynamic.c file with the corrected version. After that, you can recompile the code using the command:

csharp
Copy code
gcc -shared -o libdynamic.so dynamic.c
This should resolve the warning and create the libdynamic.so dynamic library successfully.





User
Let's call C functions from Python
#advanced
Score: 0.0% (Checks completed: 0.0%)
I know, you’re missing C when coding in Python. So let’s fix that!

Create a dynamic library that contains C functions that can be called from Python. See example for more detail.

julien@ubuntu:~/0x18$ cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
julien@ubuntu:~/0x16. Doubly linked lists$ python3 100-tests.py 
66 + -76 = -10
66 - -76 = 142
66 x -76 = -5016
66 / -76 = 0
66 % -76 = 66
julien@ubuntu:~/0x18$ python3 100-tests.py 
-34 + -57 = -91
-34 - -57 = 23
-34 x -57 = 1938
-34 / -57 = 0
-34 % -57 = -34
julien@ubuntu:~/0x18$ python3 100-tests.py 
-5 + -72 = -77
-5 - -72 = 67
-5 x -72 = 360
-5 / -72 = 0
-5 % -72 = -5
julien@ubuntu:~/0x18$ python3 100-tests.py 
39 + -62 = -23
39 - -62 = 101
39 x -62 = -2418
39 / -62 = 0
39 % -62 = 39
julien@ubuntu:~/0x18$ 

ChatGPT
To create a dynamic library containing C functions that can be called from Python, follow these steps:

Step 1: Implement the C functions in a source file
Create a C source file, for example, 100-operations.c, and implement the functions mentioned in the example. Here's an example implementation:

c
Copy code
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int mod(int a, int b) {
    return a % b;
}
Step 2: Compile the source file into a dynamic library
To compile the source file 100-operations.c into a dynamic library 100-operations.so, use the following command:

vbnet
Copy code
gcc -shared -o 100-operations.so 100-operations.c
Make sure you have the necessary development libraries installed on your system, and adjust the command if needed (e.g., adding compiler flags or library paths).

After successful compilation, you should have the 100-operations.so dynamic library file.

Step 3: Use the dynamic library in Python
Now you can use the dynamic library in Python by loading it using the ctypes module. Here's an example:

python
Copy code
import random
import ctypes

# Load the dynamic library
cops = ctypes.CDLL('./100-operations.so')

# Generate random numbers
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions and print the results
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
Make sure to replace 100-operations.so with the correct path if it's located in a different directory.

That's it! You can now execute the Python script, and it will call the C functions from the dynamic library and print the results based on random numbers generated.





User
To create a dynamic library containing C functions that can be called from Python, follow these steps:

Step 1: Implement the C functions in a source file
Create a C source file, for example, 100-operations.c, and implement the functions mentioned in the example. Here's an example implementation: >>>add these in betty style comments in c

ChatGPT
Certainly! Here's the updated code with Betty style comments:

c
Copy code
/* 100-operations.c */

/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 * Return: Result of addition
 */
int add(int a, int b)
{
    return a + b;
}

/**
 * sub - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 * Return: Result of subtraction
 */
int sub(int a, int b)
{
    return a - b;
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 * Return: Result of multiplication
 */
int mul(int a, int b)
{
    return a * b;
}

/**
 * div - Divides two integers
 * @a: First integer
 * @b: Second integer
 * Return: Result of division
 */
int div(int a, int b)
{
    return a / b;
}

/**
 * mod - Computes the modulo of two integers
 * @a: First integer
 * @b: Second integer
 * Return: Result of modulo operation
 */
int mod(int a, int b)
{
    return a % b;
}
Please note that these comments follow the general guidelines of the Betty style, but you may need to adjust them to match any specific requirements or variations that you have for the coding style.

Once you have made the necessary adjustments, you can proceed to the next steps to compile the source file into a dynamic library and use it in Python.

