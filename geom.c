#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 30
int main()
{
    float radius = 0;
    float area = 0, perimetr = 0;
    char array_for_numbers_of_radius[N];
    char array[N] = {0};
    FILE *pointer = NULL;

    pointer = fopen("circle1.txt", "r");
    if (!pointer)
    {
        printf("Can`t open the file\n");
    }
    else
    {
        int i = 0;

        while (i < N)
        {
            fscanf(pointer, "%c", &array[i]);
            ++i;
        }
    }
    
    int space = 1; // Проверка на пробелы после запятой пред значением радиуса
    int space2 = 0; // Проверка на разделение x и y
    
    int zero = 48;
    int nine = 57;
    int spaceascii = 32;
    int parenthes1 = 40;
    int parenthes2 = 41;
    int dot = 46;
    int comma = 44;

    fclose(pointer);
    char name_of_the_shape[6] = "Circle";
    int name_figure = 0, digits = 0; // Счетчики для проверки имени фигуры и части параметров в скобках
    for(int i = 0; i < 6; i++)
    {
        if(array[i] != name_of_the_shape[i])
        {
            name_figure++;
            break;
        }
    }
    for(int i = 6; i < 14; i++)
    {
        if(array[i] == '(')
        {
            for(int v = i; array[v] != ','; v++)
            {
            if(array[v] == ' ') 
                {
                    ++space2;
                }
            }
        }
        if(space2 == 0)
        {
            printf("Divide x and y\n");
            digits = 1;
            break;
        }
        if(array[i] == '.')
        {
            array[i] = ',';
        }
        if((array[i] == ',') && (space == 1))
        {
           if(array[i+1] != ' ')
            {
                digits = 1;
                break;
            }
            space = 0;
        }
        if(((array[i] < zero) || (array[i] > nine)) && (array[i] != spaceascii) && (array[i] != comma) && 
        (array[i] != parenthes1) && (array[i] != parenthes2) && (array[i] != dot))
        {
            digits = 1;
            break;
        }
    }
    if (name_figure > 0)
    {
         for(int i = 0; i < N; i++)
        {
            printf("%c", array[i]);
        }
        printf("The wrong name of the shape\n");
        printf("Please, fix the error\n");
    }
    else
    {
        if (digits == 1)
        {
            for(int i = 0; i < N; i++)
            {
                printf("%c", array[i]);
            }
            printf("Incorrect parameters of the figure\n");
            printf("Please, fix the error\n");
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                if ((array[i] == ',') && (array[i + 1] == ' '))
                {
                    for (int k = i; array[k + 1] != ')'; k++)
                    {
                        array_for_numbers_of_radius[k - i] = array[k + 1];
                    }
                };
            }
            radius = atoi(array_for_numbers_of_radius);
            area = M_PI * radius * radius;
            perimetr = 2 * M_PI * radius;
            printf("\n");
            for(int i = 0; i < N; i++)
            {
                printf("%c", array[i]);
            }
            printf("\n");
            printf("area = %.3f\n",area);
            printf("perimetr = %.3f\n", perimetr);
        }
    }
    return 0;
}