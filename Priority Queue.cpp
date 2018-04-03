//¡§ªÛ¿±_508

#include <stdio.h>

void array_swap(int arr[], int a, int b){
	int temp = 0;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Heapify(int a[], int present, int length){
	int left, right, max;
	left = present * 2;
	right = present * 2 + 1;

	if ((right <= length) && (a[right] > a[present])){
		max = right;
	}
	else{
		max = present;
	}

	if ((left <= length) && (a[left] > a[max])){
		max = left;
	}

	if (max != present){
		array_swap(a, present, max);
		Heapify(a, max, length);
	}
}

void Increase_key(int a[], int index, int key){
	while (index > 1 && a[index / 2] < a[index]){
		array_swap(a, index, index / 2);
		index /= 2;
	}
}

int main(){
	int arr[100000];
	int temp[100000];
	int check, n, index, length = 0, t_length = 0;

	while (1){
		scanf("%d", &check);

		switch (check){
		case 0:
			for (int i = 1; i <= t_length; i++){
				printf("%d ", temp[i]);
			}
			printf("\n");

			for (int i = 1; i <= length; i++){
				printf("%d ", arr[i]);
			}

			return 0;

		case 1:
			scanf("%d", &n);
			length++;
			arr[length] = n;
			Increase_key(arr, length, n);
			break;

		case 2:
			temp[++t_length] = arr[1];

			array_swap(arr, 1, length);

			Heapify(arr, 1, --length);
			break;

		case 3:
			scanf("%d %d", &index, &n);
			arr[index] = n;
			if (index != 1 && arr[index] > arr[index / 2]){
				Increase_key(arr, index, n);
			}
			else{
				Heapify(arr, index, length);
			}
			break;

		default:
			break;
		}
	}
}
