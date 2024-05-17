#ifndef ASCII_ART_H
#define ASCII_ART_H

typedef struct {
    char **data;
    int rows;
    int cols;
} ASCII_Art;

void input(ASCII_Art *art, const char *filename);
void output(const ASCII_Art *art);
void clean(ASCII_Art *art);
void inverse(ASCII_Art *art);
void dotting(ASCII_Art *art);
void rotate_r(ASCII_Art *art);
void rotate_l(ASCII_Art *art);
void frame(ASCII_Art *art, char c);
void save(const ASCII_Art *art, const char *filename);
void free_art(ASCII_Art *art);

#endif
