#ifndef NUMBERS_IO_H
#define NUMBERS_IO_H

void create_random_numbers_file();
void read_numbers_from_file(double numbers[100], int *n);
void write_numbers_to_file(const char *filename, const double numbers[100], int n);

#endif
