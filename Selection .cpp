//2016025032_¡§ªÛ¿±_508

#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	int arr[10000];
	//Input
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	//Selection Sort
	int key;
	for(int i=0; i<M; i++){
		int minIndex = i;
		for(int j=i+1; j<N; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		key = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = key;
	}
	
	//Print
	for(int i=0; i<N; i++){
		printf("%d\n", arr[i]);
	}
}
