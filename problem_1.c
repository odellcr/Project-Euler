#include <stdio.h> // printf
#include "minunit.h" // unit test macros

// No point allowing these to be negative
typedef struct
{
    unsigned int sum;
    unsigned int limit;
} multiple_test_t;

static int tests_run = 0;

static const multiple_test_t below_10 = {23, 10};
static const multiple_test_t below_1000 = {233168, 1000};

static char *all_tests(void);
static char *test_FindSumMultiplesOfThreeAndFive(void);
int FindSumMultiplesOfThreeAndFive(unsigned int limit);

static char *all_tests(void)
{
    mu_run_test(test_FindSumMultiplesOfThreeAndFive);
}

static char *test_FindSumMultiplesOfThreeAndFive(void)
{
    int sum = FindSumMultiplesOfThreeAndFive(below_10.limit);
    mu_assert("Error incorrect sum %u\n", (below_10.sum == sum));

    sum = FindSumMultiplesOfThreeAndFive(below_1000.limit);
    mu_assert("Error incorrect sum of %u\n",(below_1000.sum == sum));

    return 0;
}

int FindSumMultiplesOfThreeAndFive(unsigned int limit)
{
    int i;
    unsigned int sum;

    for(i = 0, sum = 0; i < limit; i++)
    {
        if(0 == ((i % 3)) || (0 == (i % 5)))
        {
            sum += i;
        }

    }
    printf("The sum is: %u\n", sum);

    return sum;
}

int main(int argc, char *argv[])
{
    char *result = all_tests();

    if(0 == result)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("ALL TESTS PASSED\n");
    }
    
    return 0;
}