//2016025032_¡§ªÛ¿±_508

#include <stdio.h>

int main(){
   int N,M;
   int sameKey = 0;
   int A[100000];
   int B[100000];
   int temp[100000];
   //Input
   scanf("%d %d", &N, &M);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   for(int j=0; j<M; j++){
      scanf("%d", &B[j]);
   }
   for(int k=0; k<100000; k++){
      temp[k] = 0;
   }
   //Finding same keys
   for(int i=0; i<N; i++){
      temp[A[i]]++;
   }
   for(int j=0; j<M; j++){
      if(temp[B[j]] > 0){
         temp[B[j]] = -1;
         sameKey++;
      }
      else temp[B[j]]++;
   }
   //Print
   printf("%d", sameKey);
   
   return 0;
}
