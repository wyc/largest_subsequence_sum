#ifndef _LSS_H_
#define _LSS_H_
/**
 * The following functions find the largets subsequence.
 * We assume:
 *   - the largest sum value is less than MAX_INT.
 *   - a subsequence of 0-length is a valid output
 *   - when there are multiple subsequences adding up to the max value, one
 *     shall suffice
 */

#define MAX(a, b) (a > b) ? a : b

/**
 * Uses brute force to find the subsequence yielding the largest sum.
 * Runtime is O(n^2) as we will have to evaluate every single
 * subsequence. It could have O(n^3), but we made the optimization
 * of caching the value of the previous subsequence.
 *
 * @param a input int array of positive and negative elements, size >= n
 * @param n number of elements in array
 * @param start output pointer to the start of the sequence
 * @param count output of how many elements
 */
void lss_bf(int n, const int* a, const int **start, int *count);

/**
 * Uses dynamic programming to find the subsequence yielding the largest sum.
 * Runtime is O(n) because we cache the current largest subsequence. Memory
 * is constant.
 *
 * @param a input int array of positive and negative elements, size >= n
 * @param n number of elements in array
 * @param start output pointer to the start of the sequence
 * @param count output of how many elements
 */
void lss_dp(int n, const int* a, const int **start, int *count);

#endif

