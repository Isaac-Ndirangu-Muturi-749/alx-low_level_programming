#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

void print_error(const char *message) {
	dprintf(STDERR_FILENO, "Error: %s\n", message);
}

int main(int argc, char *argv[]) {
	int fd;
	Elf64_Ehdr header;

	/* Check if the number of arguments is correct */
	if (argc != 2) {
		print_error("Usage: elf_header elf_filename");
		exit(98);
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		print_error("Can't open file");
		exit(98);
	}

	/* Read the ELF header */
	ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr)) {
		print_error("Can't read file");
		close(fd);
		exit(98);
	}

	/* Print the information from the ELF header */
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
	       header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],
	       header.e_ident[EI_MAG4], header.e_ident[EI_MAG5], header.e_ident[EI_MAG6], header.e_ident[EI_MAG7],
	       header.e_ident[EI_MAG8], header.e_ident[EI_MAG9], header.e_ident[EI_MAG10], header.e_ident[EI_MAG11],
	       header.e_ident[EI_MAG12], header.e_ident[EI_MAG13], header.e_ident[EI_MAG14], header.e_ident[EI_MAG15]);
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS]) {
        case ELFCLASS32:
		printf("ELF32\n");
		break;
        case ELFCLASS64:
		printf("ELF64\n");
		break;
        default:
		printf("<unknown>\n");
		break;
	}
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA]) {
        case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
        case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
        default:
		printf("<unknown>\n");
		break;
	}
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
        case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
        case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
        default:
		printf("<unknown: %d>\n", header.e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type) {
        case ET_NONE:
		printf("NONE (Unknown type)\n");
		break;
        case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
        case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
        case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
        case ET_CORE:
		printf("CORE (Core file)\n");
		break;
        default:
		printf("<unknown>\n");
		break;
	}
	printf("  Entry point address:               0x%lx\n", (unsigned long) header.e_entry);

	close(fd);
	return 0;
}
