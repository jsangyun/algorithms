//2016025032_¡§ªÛ¿±_508 

#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	int *arr = new int[N];
	
	//Input
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	
	//Insertion Sort
	int key;
	for (int i = 1; i < N; i++){
		key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	
	//Print
	for(int i=N-1; i>=0; i--){
		printf("%d\n", arr[i]);
	}
}
