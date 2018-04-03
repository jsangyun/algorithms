//2016025032_Á¤»óÀ±_508

#include <stdio.h>

int main(){
	int N, M, K;
	//Input
	scanf("%d %d %d", &N, &M, &K);
	
	int* A = new int[K];
	int* B = new int[K];
	int* C = new int[M];
	int* key = new int[N];
	for(int i=0; i<K; i++){
		scanf("%d %d", &A[i], &B[i]);
	}	
	for(int i=0; i<=M; i++){
		C[i] = 0;
	}
	for(int i=0; i<N; i++){
		scanf("%d", &key[i]);
		C[key[i]]++;
	}
	//C->C'
	for(int i=1; i<=M; i++){
		C[i] += C[i-1];
	}
	for(int i=0; i<K; i++){
		printf("%d\n", C[B[i]] - C[A[i] - 1]);
	}
	
	delete A,B,C,key;
	return 0;
}
