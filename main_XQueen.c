#include <time.h>
#include <stdio.h>

int        ft_ten_queens_puzzle(void);

int        main(void)
{
    double total = 0;
    for (int i = 0; i < 10; i++)
    {
        double begin = (double)clock();
        printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
        total += (clock() - begin) / CLOCKS_PER_SEC;
    }
    printf("%f", total / 10);
    return (0);
}