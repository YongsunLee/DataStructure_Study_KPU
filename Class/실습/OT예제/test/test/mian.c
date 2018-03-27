#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define OBJ 'C'
#define OBJ2 '.'
int main()
{
	int i = 0;
	int a[20] = {1, };

	for( i = 0; i < 20 ; ++i){
		if( a[i] == 1 ){
			printf("%c", OBJ);
		}
		else{
			printf("%c", OBJ2);
		}
	}
	return 0;
}
