#include <stdio.h>

const int MAX = 1000;

int burbuja(int n, int arr[])
{
	int i, j, temp, m = 0;

	for(i = 1; i < n; i++){
		for(j = 0; j < n - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				m++;
			}
		}
	}
	return m;
}

int main()
{
	int i, n, arr[MAX], res;

	while(scanf("%d", &n) != EOF)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		res = burbuja(n, arr);
		printf("Minimum exchange operations : %d\n", res);
	}
	return 0;
}
