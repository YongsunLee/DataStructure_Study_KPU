#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define OBJ 'C'
#define OBJ2 'c'
#define BREADTH 20					// 1-1
#define RIGHT 77
#define LEFT 75

int main()
{
	char chr;
	int i, j= 0;
	// while 대신 for로
	for ( j = 0; j < BREADTH; ++j){
		getch();
		chr = getch();
		if( chr == RIGHT ){
			system("cls");
			for( i = 0; i < j; ++i){
				printf(".");			
			}
			if ( j%2 == 0)				
				printf("%c", OBJ);
			else
				printf("%c", OBJ2);	
				Sleep(200);				
			}
			else
				--j;
	}
	/*
	// 반대방향
	for( j = BREADTH; j != 0; --j ){
		getch();
		chr = getch();
		if( chr == LEFT ){
		system("cls");
		for( i = 1; i < j; ++i){
			printf(".");
		}
		printf("%c", OBJ);
		Sleep(200);
		}
	}
	*/
	return 0;
}