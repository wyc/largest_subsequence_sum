void lss_bf(const int *a, int n, const int **start, int *count)
{
        int best_start, best_end, best_sum, cur_sum;
        int i, j;
        int is_empty = 1;

        best_sum = best_start = best_end = 0;
        for (i = 0; i < n; i++) {
                cur_sum = 0;
                for (j = i; j < n; j++) {
                        cur_sum += a[j];
                        if (cur_sum > best_sum) {
                                best_sum = cur_sum;
                                best_start = i;
                                best_end = j;
                                is_empty = 0;
                        }
                }
        }

        *start = &a[best_start];
        *count = best_end - best_start + !is_empty;
}

