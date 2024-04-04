#include <stdio.h>

int main()
{
    int n = 4;
    struct humen
    {
        char name[20];
        char famil[20];
        int god;
    };
    struct humen unsorting[4] = {{"Igor`", "Ponomarenko", 1987}, {"Erik","Nikulin",1972},{"Afrodita","Velekolepnaya",1962},{"Bella","L`vovna",1990}};
 // Сортировка пузырьком
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (unsorting[j].god > unsorting[j+1].god) {
                struct humen temp = unsorting[j];
                unsorting[j] = unsorting[j+1];
                unsorting[j+1] = temp;
            }
        }
    }
    printf("Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s, god birthday: %d\n", unsorting[i].name, unsorting[i].famil, unsorting[i].god);
    }
}