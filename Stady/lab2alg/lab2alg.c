#include <stdio.h>
#include <stdlib.h>

#define MAX_GLYPHS 50000
#define MAX_AREA_PIXELS 10000 // Максимальное количество пикселей в области

typedef struct point {
    int x;
    int y;
} Point;

typedef struct glyph {
    int id;
    int w;
    int h;
    int count; // количество черных пикселей
    unsigned char *data; // битовая карта
    int connected_areas_count; // количество связных областей
    int largest_area_diameter; // диаметр наибольшей области
} Glyph;

Glyph glyphs[MAX_GLYPHS];
int num_glyphs = 0;

int visited[MAX_AREA_PIXELS][MAX_AREA_PIXELS];
int area_pixels_count; // количество пикселей в текущей области

int is_black_pixel(unsigned char *data, int x, int y, int width) {
    int byte_index = y * ((width + 7) / 8) + x / 8;
    int bit_index = 7 - (x % 8);
    return (data[byte_index] >> bit_index) & 1;
}

void dfs(Glyph *glyph, int x, int y) {
    if (x < 0 || x >= glyph->w || y < 0 || y >= glyph->h)
        return;
    if (visited[x][y] || !is_black_pixel(glyph->data, x, y, glyph->w))
        return;

    visited[x][y] = 1;
    area_pixels_count++;

    dfs(glyph, x + 1, y);
    dfs(glyph, x - 1, y);
    dfs(glyph, x, y + 1);
    dfs(glyph, x, y - 1);
}

void find_connected_areas(Glyph *glyph) {
    int largest_area = 0;

    for (int y = 0; y < glyph->h; y++) {
        for (int x = 0; x < glyph->w; x++) {
            if (!visited[x][y] && is_black_pixel(glyph->data, x, y, glyph->w)) {
                area_pixels_count = 0;
                dfs(glyph, x, y);
                glyph->connected_areas_count++;

                if (area_pixels_count > largest_area)
                    largest_area = area_pixels_count;
            }
        }
    }

    glyph->largest_area_diameter = largest_area;
}

Glyph *load_img(int id, char *s) {
    FILE *F;
    Glyph *I;
    I = (Glyph *)malloc(sizeof(Glyph));
    F = fopen(s, "rb");
    fread(&(I->w), sizeof(int), 1, F);
    fread(&(I->h), sizeof(int), 1, F);
    I->count = 0;
    I->id = id;
    I->data = (unsigned char *)calloc(((I->w + 7) / 8) * I->h, 1);
    fread(I->data, 1, ((I->w + 7) / 8) * I->h, F);
    fclose(F);
    return I;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        Glyph *glyph = load_img(i, argv[i]);
        if (glyph == NULL) {
            printf("Ошибка при загрузке глифа из файла: %s\n", argv[i]);
            continue;
        }

        find_connected_areas(glyph);

        printf("Глиф %d:\n", glyph->id);
        printf("Количество черных пикселей: %d\n", glyph->count);
        printf("Количество связных областей: %d\n", glyph->connected_areas_count);
        printf("Диаметр наибольшей области: %d\n", glyph->largest_area_diameter);

        free(glyph->data);
        free(glyph);
    }

    return 0;
}
