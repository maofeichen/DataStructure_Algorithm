/*
 * *****************************************************************************
 * file: common.c
 * author: mchen
 *
 * common functions might be needed by other files.
 * *****************************************************************************
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
