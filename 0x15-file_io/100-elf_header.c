#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * print_error - prints error message to stderr &exits with status code 98
 * @msg: the error message to print
 *
 * Return: none
 */
void print_error(char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
 * print_header - prints the ELF header information
 * @header: the ELF header to print
 *
 * Return: none
 */
void print_header(Elf64_Ehdr header)
{
int i;

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", header.e_ident[i]);
printf("\n");

printf("  Class:                             %s\n",
header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
header.e_ident[EI_CLASS] == ELFCLASSNONE ? "Invalid class" :
"Unknown class");
printf("  Data:                              %s\n",
header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
header.e_ident[EI_DATA] == ELFDATANONE ? "Invalid data encoding" :
"Unknown data encoding");
printf("  Version:                           %d (current)\n",
header.e_ident[EI_VERSION]);
printf("  OS/ABI:                            %s\n",
header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
header.e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
header.e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
header.e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone (embedded) application" :
"<unknown>");
printf("  ABI Version:                       %d\n",
header.e_ident[EI_ABIVERSION]);
printf("  Type:                              %s\n",
header.e_type == ET_NONE ? "NONE (None)" :
header.e_type == ET_REL ? "REL (Relocatable file)" :
header.e_type == ET_EXEC ? "EXEC (Executable file)" :
header.e_type == ET_DYN ? "DYN (Shared object file)" :
header.e_type == ET_CORE ? "CORE (Core file)" :
"<unknown>");
printf("  Entry point address:               %#lx\n", header.e_entry);
}

/**
 * check_file_type - checks if the file is of the expected type
 * @header: the ELF header to check
 *
 * Return: none
 */
void check_file_type(Elf64_Ehdr header)
{
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
print_error("Error: File is not an ELF file");
}
if (header.e_type != ET_EXEC && header.e_type != ET_DYN)
{
print_error("Error: File is not an executable or shared object file");
}
}

/**
 * open_elf_file - opens the ELF file and returns a file descriptor for it
 * @filename: the name of the ELF file to open
 *
 * Return: the file descriptor for the ELF file
 */
int open_elf_file(char *filename)
{
int fd = open(filename, O_RDONLY);
if (fd < 0)
{
print_error("Error: Cannot open file");
}
return (fd);
}

/**
 * read_elf_header - reads the ELF header from the file and returns it
 * @fd: the file descriptor for the ELF file
 *
 * Return: the ELF header
 */
Elf64_Ehdr read_elf_header(int fd)
{
Elf64_Ehdr header;
if (read(fd, &header, sizeof(header)) != sizeof(header))
{
print_error("Error: Cannot read ELF header");
}
return (header);
}

/**
 * main - entry point of the program
 * @argc: the number of command-line arguments
 * @argv: the command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr header;

if (argc < 2)
{
print_error("Usage: elf_info <file>");
}

fd = open_elf_file(argv[1]);
header = read_elf_header(fd);
close(fd);
check_file_type(header);
print_header(header);

return (0);
}
