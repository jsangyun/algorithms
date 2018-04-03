//¡§ªÛ¿±_508

#include <stdio.h>

void Merge(int a[], int startIndex, int middleIndex, int endIndex){
	int leftIndex = startIndex;
	int rightIndex = middleIndex + 1;
	int mergeIndex = 0;
	
	int* mergeArray = new int[endIndex - startIndex +1];
	
	//sort and copy
	while(leftIndex <= middleIndex && rightIndex <= endIndex){
		if(a[leftIndex] < a[rightIndex]){
			mergeArray[mergeIndex] = a[leftIndex];
			leftIndex++;
		}
		else{
			mergeArray[mergeIndex] = a[rightIndex];
			rightIndex++;
		}
		mergeIndex++;
	}
	
	//putting remaining elements
	while(leftIndex <= middleIndex){
		mergeArray[mergeIndex++] = a[leftIndex++];
	}
	while(rightIndex <= endIndex){
		mergeArray[mergeIndex++] = a[rightIndex++];
	}
	
	//put sorted array to original array
	mergeIndex = 0;
	for(int i=startIndex; i<=endIndex; i++){
		a[i] = mergeArray[mergeIndex++];
	}
	delete mergeArray;
}

void MergeSort(int a[], int startIndex, int endIndex){
	int middleIndex = 0;
	if(endIndex - startIndex < 1){
		return;
	}
	middleIndex = (startIndex + endIndex) / 2;
	MergeSort(a, startIndex, middleIndex);
	MergeSort(a, middleIndex+1, endIndex);
	Merge(a, startIndex, middleIndex, endIndex);
}

int main(){
	int N;
	scanf("%d", &N);
	int arr[10000];
	//Input
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	//Merge
	MergeSort(arr,0,N-1);
	
	//Print
	for(int i=N-1; i>=0; i--){
		printf("%d\n", arr[i]);
	}
}
