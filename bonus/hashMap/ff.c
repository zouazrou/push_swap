#include <stdio.h>

void    func1(char *s)
{
    printf("-->%s\n", s);
}
void    func2(char *s)
{
    printf("2\n");
}
void    func3(char *s)
{
    printf("3\n");
}
void    func4(void)
{
    printf("4\n");
}

void hh(void (*f)(int))
{
    int nb = 42;
    f(nb);
}
int main(void)
{
    void (*function[12])(char *);

    function[0] = func1;
    function[1] = NULL;
    function[2] = func3;
    // function[0]("hmd llah!");
    if (function[1] != NULL)
        function[1]("hmd llah!");
    else
        printf("NN\n");
    // function[2]("hmd llah!");
    return (0);
}