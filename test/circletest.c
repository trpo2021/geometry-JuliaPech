#include "ctest.h"
#include "libgeometry/library.h"

// CTEST(suite, system_testing)
// {
//     ASSERT_EQUAL(1 + 2, 3);
// }

CTEST(area_search, area_1)
{
    float radius = 0;

    int real = area1(radius);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_2)
{
    float radius = 1;

    int real = area1(radius);

    int exp = 3.1416;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_3)
{
    float radius = 2;

    int real = area1(radius);

    int exp = 12.5664;

    ASSERT_EQUAL(exp, real);
}

CTEST(area_search, area_4)
{
    float radius = 10;

    int real = area1(radius);

    int exp = 314.16;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_1)
{
    float radius = 0;

    int real = perimetr1(radius);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_2)
{
    float radius = 1;

    int real = perimetr1(radius);

    int exp = 6.2832;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_3)
{
    float radius = 2;

    int real = perimetr1(radius);

    int exp = 12.5664;

    ASSERT_EQUAL(exp, real);
}

CTEST(perimetr_search, perimetr_4)
{
    float radius = 10;

    int real = perimetr1(radius);

    int exp = 62.832;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, part_of_name)
{
    char str[2] = {"c"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, empty_name)
{
    char str[1] = {""};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char str[8] = {"8circle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_2)
{
    char str[8] = {"Cicle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_3)
{
    char str[8] = {"Circl"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_4)
{
    char str[8] = {"Oval"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_5)
{
    char str[8] = {"8848"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char str[7] = {"Circle"};

    int real = name(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error)
{
    char str[8] = {" Circle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_2)
{
    char str[8] = {"C ircle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, space_error_3)
{
    char str[8] = {"Cir cle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, small_letter)
{
    char str[7] = {"circle"};

    int real = name(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, empty_data_2)
{
    char str[9] = {"Circle()"};

    int real = check_space_1(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, correct_data)
{
    char str[16] = {"Circle(0 0, 8)"};

    int real = check_space_2(str);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space)
{
    char str[16] = {"Circle( 0 0, 8)"};

    int real = check_space_1(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_space_2)
{
    char str[17] = {"Circle (0 0, 8)"};

    int real = check_space_1(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_lost_number)
{
    char str[16] = {"Circle(   0, 8)"};

    int real = check_space_1(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_2)
{
    char str[16] = {"Circle(0 0 ,8)"};

    int real = check_space_2(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_comma_3)
{
    char str[20] = {"Circle(0[[[0, 8)"};

    int real = check_in_parenthes(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_bracket)
{
    char str[16] = {"Circle(0 0as, 8"};

    int real = check_in_parenthes(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_minus)
{
    char str[15] = {"Circle(-0 0, 8)"};

    int real = check_in_parenthes(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_excess)
{
    char str[17] = {"Circle( 0+0 0, 8)"};

    int real = check_in_parenthes(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(datacheck, incorrect_data_7)
{
    char str[16] = {"Circle(0 - 0, 8)"};

    int real = check_in_parenthes(str);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}