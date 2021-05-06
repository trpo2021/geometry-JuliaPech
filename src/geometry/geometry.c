#include <libgeometry/library.h>

#define N 30
int main()
{
    struct circle array_circle[10];
    float radius = 0, x = 0, y = 0;
    float area = 0, perimetr = 0;
    int n; // кол-во кругов

    FILE* pointer = NULL;

    pointer = fopen("circle1.txt", "r");
    if (!pointer) {
        printf("Can`t open the file\n");
    } else {
        while (!feof(pointer)) {
            char array_for_numbers_of_radius[N] = {0};
            char array_for_numbers_of_x[N] = {0};
            char array_for_numbers_of_y[N] = {0};
            char array[N] = {0};
            fgets(array, N, pointer);
            printf("\n");
            int space2 = 0; // Проверка на пробелы после запятой пред значением
                            // радиуса
            int space = 0;  // Проверка на разделение x и y
            int brackets = 0;

            int name_figure = 0;

            name_figure = name(array);
            space = check_space_1(array);
            space2 = check_space_2(array);
            brackets = check_in_parenthes(array);

            if (space < 0) {
                for (int i = 0; i < N; i++) {
                    printf("%c", array[i]);
                }
                printf("Divide x and y\n");
            } else {
                if (space2 >= 1) {
                    for (int i = 0; i < N; i++) {
                        printf("%c", array[i]);
                    }
                    printf("error\n");
                } else {
                    if (brackets >= 1) {
                        for (int i = 0; i < N; i++) {
                            printf("%c", array[i]);
                        }
                        printf("error in brackets\n");
                    } else {
                        if (name_figure >= 1) {
                            for (int i = 0; i < N; i++) {
                                printf("%c", array[i]);
                            }
                            printf("incorrect name\n");
                        } else {
                            for (int i = 0; i < N; i++) {
                                if ((array[i] == ',')
                                    && (array[i + 1] == ' ')) {
                                    for (int k = i; array[k + 1] != ')'; k++) {
                                        array_for_numbers_of_radius[k - i]
                                                = array[k + 1];
                                    }
                                }
                                if (array[i] == '(') {
                                    for (int k = i; array[k + 1] != ' '; k++) {
                                        array_for_numbers_of_x[k - i]
                                                = array[k + 1];
                                    }
                                }
                                if (array[i] == ' ') {
                                    for (int k = i - 1; array[k] != ','; k++) {
                                        array_for_numbers_of_y[k - i]
                                                = array[k];
                                    }
                                }
                            }
                            ++n;
                            x = atof(array_for_numbers_of_x);
                            y = atof(array_for_numbers_of_y);
                            radius = atof(array_for_numbers_of_radius);
                            area = area1(radius);
                            perimetr = perimetr1(radius);
                            printf("%d. ", n);
                            printf("\n");
                            for (int i = 0; i < N; i++) {
                                printf("%c", array[i]);
                            }
                            array_circle[n].radius = radius;
                            array_circle[n].x = x;
                            array_circle[n].y = y;
                            printf("\n");
                            printf("area = %.3f\n", area);
                            printf("perimetr = %.3f\n", perimetr);
                        }
                    }
                }
            }
        }
        printf("\n");
        intersects(n, array_circle);
    }
    fclose(pointer);

    return 0;
}