#include "QB.h"
#include <time.h>
#include <stdio.h>

int        main(void)
{
    double begin = (double)clock();
    printf("Number of solutions: %d\n", ft_ten_queens_puzzle(10));
    printf("Time : %f\n", (clock() - begin) / CLOCKS_PER_SEC);
    return (0);
}