#include "library.h"
#include <stdio.h>
#include <stdlib.h>

int name(char* array)
{
    char name_of_the_shape[6] = "Circle";
    int a = 0;
    for (int i = 0; i < 6; i++) {
        if (array[i] != name_of_the_shape[i]) {
            a = 1;
            break;
        }
    }
    return a;
}
int check_space_1(char* array)
{
    int b = 0;
    for (int i = 6; i < 14; i++) {
        if (array[i] == '(') {
            for (int v = i; array[v] != ','; v++) {
                if (array[v] == ' ') {
                    b = 1;
                    break;
                }
            }
        }
    }
    return b;
}

int check_space_2(char* array)
{
    int c = 0;
    for (int i = 6; i < 14; i++) {
        if ((array[i] == ',') && (array[i + 1] != ' ')) {
            c = 1;
            break;
        }
    }
    return c;
}
int check_in_parenthes(char* array)
{
    int zero = 48;
    int nine = 57;
    int spaceascii = 32;
    int parenthes1 = 40;
    int parenthes2 = 41;
    int dot = 46;
    int comma = 44;
    int z = 0;

    for (int i = 6; i < 14; i++) {
        if (((array[i] < zero) || (array[i] > nine)) && (array[i] != spaceascii)
            && (array[i] != comma) && (array[i] != parenthes1)
            && (array[i] != parenthes2) && (array[i] != dot)) {
            z = 1;
            break;
        }
    }
    return z;
}
float area1(float radius)
{
    return (M_PI * radius * radius);
}

float perimetr1(float radius)
{
    return (2 * M_PI * radius);
}

void intersects(int n, struct circle* array_circle)
{
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n + 1; j++) {
            int w = fabs(array_circle[i].x - array_circle[j].x);
            int q = fabs(array_circle[i].y - array_circle[j].y);
            if (sqrt(w * w + q * q) <= (array_circle[i].radius + array_circle[j].radius)) {
                printf("Circle %d intersects Circle %d \n", i, j);
            }
        }
    }
}