#include <stdio.h>
#define size 50//50
 
void shift_element(int* arr, int i){
for(int j=0;j<i;j++){
	*(arr+j) = *(arr+j+1);
}
}//

void swap(int* a, int* b){
int c = *a;
*a = *b;
*b = c; 
}//

void insertion_sort(int* arr,int len){
int *min;

for(int i=0; i < len-1; i++){
	min = arr+i;
	for(int j=i; j < len; j++ ){
		if( *(arr+j) < *min ){
			min = arr+j;
		}
	}
	swap(arr+i,min);
}
}//

int main(){

int arr[size];
for(int i=0; i<size; i++){
	scanf("%d", arr+i );
}

insertion_sort(arr,size);
for(int i=0;i<size;i++){
	if(i==size-1)
		printf("%d",arr[i]);
	else
		printf("%d,", arr[i]);
}

return 0;
}
