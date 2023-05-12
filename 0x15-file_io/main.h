1 #ifndef MAIN_H
  2 #define MAIN_H
  3 
  4 #include <stdio.h>
  5 #include <stdlib.h>
  6 #include <unistd.h>
  7 #include <fcntl.h>
  8 #include <sys/types.h>
  9 #include <sys/stat.h>
 10 
 11 int create_file(const char *filename, char *text_content);
 12 int append_text_to_file(const char *filename, char *text_content);
 13 ssize_t read_textfile(const char *filename, size_t letters);
 14 int _putchar(char c);
 15 
 16 #endif /*MAIN_H */

