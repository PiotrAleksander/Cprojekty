/*binsearch: szukaj x wśród v[0] <= v[1] <= ... <= v[n-1]*/
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;	/*znaleziono*/
	else
		return -1;	/*nie znaleziono*/
}
