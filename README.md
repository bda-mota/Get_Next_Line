# Get_Next_Line

## Description
This project involves programming a function in C that returns a line read from a file descriptor. The primary functionality is the ability to read and extract lines from a file, facilitating data manipulation in a programming context.

## Key Features
Line Reading: The developed function is capable of reading a line from the file associated with the provided file descriptor parameter.

## Learned Concepts
During the development of this project, I gained essential programming knowledge, including:
Static Variable: I employed concepts of static variables to preserve state between successive calls to the function.
Memory Management: I learned to handle and address memory leaks, ensuring efficient execution without resource wastage.
Linked List: I developed the function using a linked list structure, demonstrating the practical application of this data structure.

## Main
To test, add the following code to the get_next_line.c file:

```c
int    main(void)
{
    int        fd;
    char    *str;

    fd = open("test.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
    close (fd);
    return (0);
}
```
- **Obs:** you need to create the file 'test.txt' containing what you want get_next_line to read.
  
## Compilation
After adding the main() to the .c file and saving, type the following command in the terminal:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c && ./a.out

- **Obs:** -D BUFFER_SIZE=42 -> define how many bytes will get_next_line read per iteration
