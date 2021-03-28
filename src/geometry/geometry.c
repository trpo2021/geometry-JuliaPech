#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <libgeometry/library.h>
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
    fclose(pointer);

    int space2 = 0; // Проверка на пробелы после запятой пред значением радиуса
    int space = 0; // Проверка на разделение x и y
    int brackets = 0; 

   
    int name_figure = 0;

    name_figure = name(array);
    space = check_space_1(array);
    space2 = check_space_2(array);
    brackets = check_in_parenthes(array);

    if(space > 0)
    {
        for (int i = 0; i < N; i++) 
        {
            printf("%c", array[i]);
        }
        printf("Divide x and y\n");
    }
    else
    {
        if(space2 >= 1)
        {
            for (int i = 0; i < N; i++) 
            {
                printf("%c", array[i]);
            }
            printf("error\n");
        }
        else
        {
            if(brackets >= 1)
            {
                for (int i = 0; i < N; i++) 
                {
                    printf("%c", array[i]);
                }
                printf("error in brackets\n");
            }
            else
            {
                if(name_figure >= 1)
                {
                    for (int i = 0; i < N; i++) 
                    {
                        printf("%c", array[i]);
                    }
                    printf("incorrect name\n");
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
                        }
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
            
        }

    }
    return 0;
}