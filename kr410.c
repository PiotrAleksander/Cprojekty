/*qsort: sortuje v[left]...v[right] rosnąco*/
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)	/*nic nie rób, jeżeli tablica zawiera*/
		return;		/*mniej niż dwa elementy*/
	swap(v, left, (left + right) / 2);	/*przenieś element partycji*/
	last = left;				/*do v[0]*/
	for (i = left + 1; i <= right; i++) 	/*partycja*/
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);	/*przywróć element partycji*/
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/*swap: zamienia miejscami v[i] i v[j]*/
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
