#include <stdio.h>
#include <assert.h>

static const int *a;
static int n, *start, count;

void test_example()
{
        int b[] = {4, -1, 5, 6, -13, 2};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 4);

        lss_dp(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 4);
}

void test_beginning()
{
        int b[] = {1, 1, 1, -1, -1, -1};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 3);

        lss_dp(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 3);
}

void test_middle()
{
        int b[] = {-1, -1, 1, 1, -1, -1};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(start - a == 2);
        assert(count == 2);

        lss_dp(a, n, &start, &count);
        assert(start - a == 2);
        assert(count == 2);
}

void test_ending()
{
        int b[] = {-1, -1, -1, 1, 1, 1};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(start - a == 3);
        assert(count == 3);

        lss_dp(a, n, &start, &count);
        assert(start - a == 3);
        assert(count == 3);
}

void test_none_is_optimal()
{
        int b[] = {-1, -2, -4, -8, -1, -1};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(count == 0);

        lss_dp(a, n, &start, &count);
        assert(count == 0);
}

void test_all_is_optimal()
{
        int b[] = {1, 2, 4, 8, 1, 1};
        a = b, n = 6;

        lss_bf(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 6);

        lss_dp(a, n, &start, &count);
        assert(start - a == 0);
        assert(count == 6);
}

int main()
{

        test_beginning();
        test_middle();
        test_ending();
        test_none_is_optimal();
        test_all_is_optimal();

        /**
         * For debugging:
        printf("BF: Starting at element #%ld for %d elements.\n", start - a, count);
        printf("DP: Starting at element #%ld for %d elements.\n", start - a, count);
        */

        return 0;
}

