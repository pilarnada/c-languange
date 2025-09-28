#include<stdio.h>
#include<string.h>


int main(){
	int i;
	char arr[110];
	scanf("%s", arr);
	int len = strlen(arr);
	
	for(i=len-1;i>=0;i-- ){
		if(arr[i] >= 'A' && arr[i] <= 'Z'){
			arr[i] += 32;
		}
		else if(arr[i] >= 'a' && arr[i] <= 'z'){
			arr[i] -= 32;
		}
		printf("%c", arr[i]);
	}
	printf("\n");
	
	return 0;
}
