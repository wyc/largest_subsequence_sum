void lss_dp(const int *a, int n, const int **start, int *count)
{
        int best, best_start, best_end;
        int sum, sum_start, sum_end;
        int is_empty = 1;

        best = best_start = best_end = 0;
        sum = sum_start = sum_end = 0;

        int i;
        for (i = 0; i < n; i++) {
                if (sum + a[i] > 0) {
                        sum += a[i];
                        sum_end = i;
                } else {
                        sum = 0;
                        sum_start = i + 1;
                        sum_end = i + 1;
                }

                if (sum > best) {
                        best = sum;
                        best_start = sum_start;
                        best_end = sum_end;
                        is_empty = 0;
                }
        }

        *start = &a[best_start];
        *count = best_end - best_start + !is_empty;
}

