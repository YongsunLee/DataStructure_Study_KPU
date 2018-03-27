#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

#define SIZE 19

#include <time.h>

int BackPlane[SIZE][SIZE];
int temp_x, temp_y, rand_x, rand_y;
int Turn[5];

void Attack(int BackPlane[SIZE][SIZE]);
void Defence(int BackPlane[SIZE][SIZE], int x, int y);

void BlackAttack( int *x, int *y )
{
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			// ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
			/* 세개*****************************************************************************/
			// 가로
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 2] == 2){
				if (BackPlane[i][j - 1] == 0 || BackPlane[i][j + 3] == 0){
					if (j == 0){
						BackPlane[i][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane[i][j + 3] = 6;
					}
					else{
						BackPlane[i][j - 1] = 6;
						BackPlane[i][j + 3] = 7;
					}
				}
			}
			// 세로
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 2][j] == 2){
				if (BackPlane[i - 1][j] == 0 || BackPlane[i + 3][j] == 0){
					if (j == 0){
						BackPlane[i - 1][j] = 6;
					}
					else if (j == 16){
						BackPlane[i + 3][j] = 6;
					}
					else{
						BackPlane[i - 1][j] = 6;
						BackPlane[i + 3][j] = 7;
					}
				}
			}
			// 정대각
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 2][j + 2] == 2){
				if (BackPlane[i - 1][j - 1] == 0 || BackPlane[i + 3][j + 3] == 0){
					if (j == 0){
						BackPlane[i - 1][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane[i + 3][j + 3] = 6;
					}
					else{
						BackPlane[i - 1][j - 1] = 6;
						BackPlane[i + 3][j + 3] = 7;
					}
				}
			}
			// 역대각
			if (BackPlane[i][j] == 2 && BackPlane[i - 1][j + 1] == 2 && BackPlane[i - 2][j + 2] == 2){
				if (BackPlane[i + 1][j - 1] == 0 || BackPlane[i - 3][j + 3] == 0){
					if (j == 0){
						BackPlane[i + 1][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane[i - 3][j + 3] = 6;
					}
					else{
						BackPlane[i + 1][j - 1] = 6;
						BackPlane[i - 3][j + 3] = 7;
					}
				}
			}
			/* 앞에 한칸 *************************************************************************/
			// 가로
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 2] == 2 && BackPlane[i][j + 3] == 2){
				if (BackPlane[i][j - 1] == 0 || BackPlane[i][j + 4] == 0 || BackPlane[i][j + 1] == 0){
					if (BackPlane[i][j - 1] == 0){
						BackPlane[i][j - 1] = 7;
					}
					if (BackPlane[i][j + 4] == 0){
						BackPlane[i][j + 4] = 8;
					}
					if (BackPlane[i][j + 1] == 0){
						BackPlane[i][j + 1] = 6;
					}
				}
			}
			// 세로
			if (BackPlane[i][j] == 2 && BackPlane[i + 2][j] == 2 && BackPlane[i + 3][j] == 2){
				if (BackPlane[i - 1][j] == 0 || BackPlane[i + 4][j] == 0 || BackPlane[i + 1][j] == 0){
					if (BackPlane[i - 1][j] == 0){
						BackPlane[i - 1][j] = 7;
					}
					if (BackPlane[i + 4][j] == 0){
						BackPlane[i + 4][j] = 8;
					}
					if (BackPlane[i + 1][j] == 0){
						BackPlane[i + 1][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane[i][j] == 2 && BackPlane[i + 2][j + 2] == 2 && BackPlane[i + 3][j + 3] == 2){
				if (BackPlane[i - 1][j - 1] == 0 || BackPlane[i + 4][j + 4] == 0 || BackPlane[i + 1][j + 1] == 0){
					if (BackPlane[i - 1][j - 1] == 0){
						BackPlane[i - 1][j - 1] = 7;
					}
					if (BackPlane[i + 4][j + 4] == 0){
						BackPlane[i + 4][j + 4] = 8;
					}
					if (BackPlane[i + 1][j + 1] == 0){
						BackPlane[i + 1][j + 1] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane[i][j] == 2 && BackPlane[i - 2][j + 2] == 2 && BackPlane[i - 3][j + 3] == 2){
				if (BackPlane[i + 1][j - 1] == 0 || BackPlane[i - 4][j + 4] == 0 || BackPlane[i - 1][j + 1] == 0){
					if (BackPlane[i + 1][j - 1] == 0){
						BackPlane[i + 1][j - 1] = 7;
					}
					if (BackPlane[i - 4][j + 4] == 0){
						BackPlane[i - 4][j + 4] = 8;
					}
					if (BackPlane[i - 1][j + 1] == 0){
						BackPlane[i - 1][j + 1] = 6;
					}
				}
			}
			/* 뒤에 한칸******************************************************************************************/
			// 가로
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 3] == 2){
				if (BackPlane[i][j - 1] == 0 || BackPlane[i][j + 4] == 0 || BackPlane[i][j + 2] == 0){
					if (BackPlane[i][j - 1] == 0){
						BackPlane[i][j - 1] = 7;
					}
					if (BackPlane[i][j + 4] == 0){
						BackPlane[i][j + 4] = 8;
					}
					if (BackPlane[i][j + 2] == 0){
						BackPlane[i][j + 2] = 6;
					}
				}
			}
			// 세로
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 3][j] == 2){
				if (BackPlane[i - 1][j] == 0 || BackPlane[i + 4][j] == 0 || BackPlane[i + 2][j] == 0){
					if (BackPlane[i - 1][j] == 0){
						BackPlane[i - 1][j] = 7;
					}
					if (BackPlane[i + 4][j] == 0){
						BackPlane[i + 4][j] = 8;
					}
					if (BackPlane[i + 2][j] == 0){
						BackPlane[i + 2][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 3][j + 3] == 2){
				if (BackPlane[i - 1][j - 1] == 0 || BackPlane[i + 4][j + 4] == 0 || BackPlane[i + 2][j + 2] == 0){
					if (BackPlane[i - 1][j - 1] == 0){
						BackPlane[i - 1][j - 1] = 7;
					}
					if (BackPlane[i + 4][j + 4] == 0){
						BackPlane[i + 4][j + 4] = 8;
					}
					if (BackPlane[i + 2][j + 2] == 0){
						BackPlane[i + 2][j + 2] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane[i][j] == 2 && BackPlane[i - 1][j + 1] == 2 && BackPlane[i - 3][j + 3] == 2){
				if (BackPlane[i + 1][j - 1] == 0 || BackPlane[i - 4][j + 4] == 0 || BackPlane[i - 2][j + 2] == 0){
					if (BackPlane[i + 1][j - 1] == 0){
						BackPlane[i + 1][j - 1] = 7;
					}
					if (BackPlane[i - 4][j + 4] == 0){
						BackPlane[i - 4][j + 4] = 8;
					}
					if (BackPlane[i - 2][j + 2] == 0){
						BackPlane[i - 2][j + 2] = 6;
					}
				}
			}
			// 세개 앞 한칸***********************************************************************
			// 가로
			if (BackPlane[i][j] == 1 && BackPlane[i][j + 2] == 1 && BackPlane[i][j + 3] == 1 && BackPlane[i][j + 4] == 1){
				if (BackPlane[i][j + 1] == 0){
					if (BackPlane[i][j + 1] == 0){
						BackPlane[i][j + 1] = 6;
					}
				}
			}
			// 세로
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j] == 1 && BackPlane[i + 3][j] == 1 && BackPlane[i + 4][j] == 1){
				if (BackPlane[i + 1][j] == 0){
					if (BackPlane[i + 1][j] == 0){
						BackPlane[i + 1][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane[i][j] == 1 && BackPlane[i + 2][j + 2] == 1 && BackPlane[i + 3][j + 3] == 1 && BackPlane[i + 4][j + 4] == 1){
				if (BackPlane[i + 1][j + 1] == 0){
					if (BackPlane[i + 1][j + 1] == 0){
						BackPlane[i + 1][j + 1] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane[i][j] == 1 && BackPlane[i - 2][j + 2] == 1 && BackPlane[i - 3][j + 3] == 1 && BackPlane[i - 4][j + 4] == 1){
				if (BackPlane[i - 1][j + 1] == 0){
					if (BackPlane[i - 1][j + 1] == 0){
						BackPlane[i - 1][j + 1] = 6;
					}
				}
			}

			// 세게 뒤 한칸************************************************************************
			// 가로
			if (BackPlane[i][j] == 2 && BackPlane[i][j + 1] == 2 && BackPlane[i][j + 2] == 2 && BackPlane[i][j + 4] == 2){
				if (BackPlane[i][j + 3] == 0){
					if (BackPlane[i][j + 3] == 0){
						BackPlane[i][j + 3] = 6;
					}
				}
			}
			// 세로
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j] == 2 && BackPlane[i + 2][j] == 2 && BackPlane[i + 4][j] == 2){
				if (BackPlane[i + 3][j] == 0){
					if (BackPlane[i + 3][j] == 0){
						BackPlane[i + 3][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane[i][j] == 2 && BackPlane[i + 1][j + 1] == 2 && BackPlane[i + 2][j + 2] == 2 && BackPlane[i + 4][j + 4] == 2){
				if (BackPlane[i + 3][j + 3] == 0){
					if (BackPlane[i + 3][j + 3] == 0){
						BackPlane[i + 3][j + 3] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane[i][j] == 2 && BackPlane[i - 1][j + 1] == 2 && BackPlane[i - 2][j + 2] == 2 && BackPlane[i - 4][j + 4] == 2){
				if (BackPlane[i + 3][j - 3] == 0){
					if (BackPlane[i + 3][j - 3] == 0){
						BackPlane[i + 3][j - 3] = 6;
					}
				}
			}
		}
	}

	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
				if (BackPlane[j][i] == 3){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[0] = 1;
					break;
				}
				else if (BackPlane[j][i] == 4 && Turn[0] == 1){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[0] = 0;
					Turn[1] = 1;
					break;
				}
				else if (BackPlane[j][i] == 5 && Turn[1] == 1){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[1] = 0;
					Turn[2] = 1;
					break;
				}
				else if (BackPlane[j][i] == 6 && Turn[2] == 1){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[2] = 0;
					Turn[3] = 1;
					break;
				}
				else if (BackPlane[j][i] == 7 && Turn[3] == 1){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[3] = 0;
					Turn[4] = 1;
					break;
				}
				else if (BackPlane[j][i] == 8 && Turn[4] == 1){
					BackPlane[j][i] = 2;
					*x = i;
					*y = j;
					
					Turn[4] = 0;
					break;
				}
		}
	}
		if (BackPlane[temp_y][temp_x + 1] == 0){
			BackPlane[temp_y][temp_x + 1] = 2;
			*x = temp_x + 1;
			*y = temp_y;
			
		}
		else if (BackPlane[temp_y][temp_x - 1] == 0){
			BackPlane[temp_y][temp_x - 1] = 2;
			*x = temp_x - 1;
			*y = temp_y;
			
		}
		else if (BackPlane[temp_y + 1][temp_x] == 0){
			BackPlane[temp_y + 1][temp_x] = 2;
			*x = temp_x;
			*y = temp_y + 1;
			
		}
		else if (BackPlane[temp_y - 1][temp_x] == 0){
			BackPlane[temp_y - 1][temp_x] = 2;
			*x = temp_x;
			*y = temp_y - 1;
			
		}
		else if (BackPlane[temp_y + 1][temp_x - 1] == 0){
			BackPlane[temp_y + 1][temp_x - 1] = 2;
			*x = temp_x - 1;
			*y = temp_y + 1;
			
		}
		else if (BackPlane[temp_y - 1][temp_x + 1] == 0){
			BackPlane[temp_y - 1][temp_x + 1] = 2;
			*x = temp_x + 1;
			*y = temp_y - 1;
			
		}
		else if (BackPlane[temp_y - 1][temp_x - 1] == 0){
			BackPlane[temp_y - 1][temp_x - 1] = 2;
			*x = temp_x - 1;
			*y = temp_y - 1;
			
		}
		else if (BackPlane[temp_y + 1][temp_x + 1] == 0){
			BackPlane[temp_y + 1][temp_x + 1] = 2;
			*x = temp_x + 1;
			*y = temp_y + 1;
			
		}
		else {
			srand((unsigned)time(NULL));
			while (BackPlane[rand_y][rand_x] == 0 || BackPlane[rand_y][rand_x] == 3 ||
				BackPlane[rand_y][rand_x] == 4 || BackPlane[rand_y][rand_x] == 5
				|| BackPlane[rand_y][rand_x] == 6 || BackPlane[rand_y][rand_x] == 7
				|| BackPlane[rand_y][rand_x] == 8){
				rand_x = rand() % temp_x;
				rand_y = rand() % temp_y;
			}
			BackPlane[rand_y][rand_x] = 2;
			*x = rand_x;
			*y = rand_y;

		}
}

void BlackDefence( int x, int y )
{
	for (int x = 0; x < SIZE; ++x){
		for (int y = 0; y < SIZE; ++y){
			// ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
			/* 세개*****************************************************************************/
			// 가로
			if (BackPlane[x][y] == 1 && BackPlane[x][y + 1] == 1 && BackPlane[x][y + 2] == 1){
				if (BackPlane[x][y - 1] == 0 || BackPlane[x][y + 3] == 0){
					if (y == 0){
						BackPlane[x][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane[x][y + 3] = 3;
					}
					else{
						BackPlane[x][y - 1] = 3;
						BackPlane[x][y + 3] = 4;
					}
				}
			}
			// 세로
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y] == 1 && BackPlane[x + 2][y] == 1){
				if (BackPlane[x - 1][y] == 0 || BackPlane[x + 3][y] == 0){
					if (y == 0){
						BackPlane[x - 1][y] = 3;
					}
					else if (y == 16){
						BackPlane[x + 3][y] = 3;
					}
					else{
						BackPlane[x - 1][y] = 3;
						BackPlane[x + 3][y] = 4;
					}
				}
			}
			// 정대각
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y + 1] == 1 && BackPlane[x + 2][y + 2] == 1){
				if (BackPlane[x - 1][y - 1] == 0 || BackPlane[x + 3][y + 3] == 0){
					if (y == 0){
						BackPlane[x - 1][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane[x + 3][y + 3] = 3;
					}
					else{
						BackPlane[x - 1][y - 1] = 3;
						BackPlane[x + 3][y + 3] = 4;
					}
				}
			}
			// 역대각
			if (BackPlane[x][y] == 1 && BackPlane[x - 1][y + 1] == 1 && BackPlane[x - 2][y + 2] == 1){
				if (BackPlane[x + 1][y - 1] == 0 || BackPlane[x - 3][y + 3] == 0){
					if (y == 0){
						BackPlane[x + 1][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane[x - 3][y + 3] = 3;
					}
					else{
						BackPlane[x + 1][y - 1] = 3;
						BackPlane[x - 3][y + 3] = 4;
					}
				}
			}
			/* 앞에 한칸 *************************************************************************/
			// 가로
			if (BackPlane[x][y] == 1 && BackPlane[x][y + 2] == 1 && BackPlane[x][y + 3] == 1){
				if (BackPlane[x][y - 1] == 0 || BackPlane[x][y + 4] == 0 || BackPlane[x][y + 1] == 0){
					if (BackPlane[x][y - 1] == 0){
						BackPlane[x][y - 1] = 4;
					}
					if (BackPlane[x][y + 4] == 0){
						BackPlane[x][y + 4] = 5;
					}
					if (BackPlane[x][y + 1] == 0){
						BackPlane[x][y + 1] = 3;
					}
				}
			}
			// 세로
			if (BackPlane[x][y] == 1 && BackPlane[x + 2][y] == 1 && BackPlane[x + 3][y] == 1){
				if (BackPlane[x - 1][y] == 0 || BackPlane[x + 4][y] == 0 || BackPlane[x + 1][y] == 0){
					if (BackPlane[x - 1][y] == 0){
						BackPlane[x - 1][y] = 4;
					}
					if (BackPlane[x + 4][y] == 0){
						BackPlane[x + 4][y] = 5;
					}
					if (BackPlane[x + 1][y] == 0){
						BackPlane[x + 1][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane[x][y] == 1 && BackPlane[x + 2][y + 2] == 1 && BackPlane[x + 3][y + 3] == 1){
				if (BackPlane[x - 1][y - 1] == 0 || BackPlane[x + 4][y + 4] == 0 || BackPlane[x + 1][y + 1] == 0){
					if (BackPlane[x - 1][y - 1] == 0){
						BackPlane[x - 1][y - 1] = 4;
					}
					if (BackPlane[x + 4][y + 4] == 0){
						BackPlane[x + 4][y + 4] = 5;
					}
					if (BackPlane[x + 1][y + 1] == 0){
						BackPlane[x + 1][y + 1] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane[x][y] == 1 && BackPlane[x - 2][y + 2] == 1 && BackPlane[x - 3][y + 3] == 1){
				if (BackPlane[x + 1][y - 1] == 0 || BackPlane[x - 4][y + 4] == 0 || BackPlane[x - 1][y + 1] == 0){
					if (BackPlane[x + 1][y - 1] == 0){
						BackPlane[x + 1][y - 1] = 4;
					}
					if (BackPlane[x - 4][y + 4] == 0){
						BackPlane[x - 4][y + 4] = 5;
					}
					if (BackPlane[x - 1][y + 1] == 0){
						BackPlane[x - 1][y + 1] = 3;
					}
				}
			}
			/* 뒤에 한칸******************************************************************************************/
			// 가로
			if (BackPlane[x][y] == 1 && BackPlane[x][y + 1] == 1 && BackPlane[x][y + 3] == 1){
				if (BackPlane[x][y - 1] == 0 || BackPlane[x][y + 4] == 0 || BackPlane[x][y + 2] == 0){
					if (BackPlane[x][y - 1] == 0){
						BackPlane[x][y - 1] = 4;
					}
					if (BackPlane[x][y + 4] == 0){
						BackPlane[x][y + 4] = 5;
					}
					if (BackPlane[x][y + 2] == 0){
						BackPlane[x][y + 2] = 3;
					}
				}
			}
			// 세로
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y] == 1 && BackPlane[x + 3][y] == 1){
				if (BackPlane[x - 1][y] == 0 || BackPlane[x + 4][y] == 0 || BackPlane[x + 2][y] == 0){
					if (BackPlane[x - 1][y] == 0){
						BackPlane[x - 1][y] = 4;
					}
					if (BackPlane[x + 4][y] == 0){
						BackPlane[x + 4][y] = 5;
					}
					if (BackPlane[x + 2][y] == 0){
						BackPlane[x + 2][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y + 1] == 1 && BackPlane[x + 3][y + 3] == 1){
				if (BackPlane[x - 1][y - 1] == 0 || BackPlane[x + 4][y + 4] == 0 || BackPlane[x + 2][y + 2] == 0){
					if (BackPlane[x - 1][y - 1] == 0){
						BackPlane[x - 1][y - 1] = 4;
					}
					if (BackPlane[x + 4][y + 4] == 0){
						BackPlane[x + 4][y + 4] = 5;
					}
					if (BackPlane[x + 2][y + 2] == 0){
						BackPlane[x + 2][y + 2] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane[x][y] == 1 && BackPlane[x - 1][y + 1] == 1 && BackPlane[x - 3][y + 3] == 1){
				if (BackPlane[x + 1][y - 1] == 0 || BackPlane[x - 4][y + 4] == 0 || BackPlane[x - 2][y + 2] == 0){
					if (BackPlane[x + 1][y - 1] == 0){
						BackPlane[x + 1][y - 1] = 4;
					}
					if (BackPlane[x - 4][y + 4] == 0){
						BackPlane[x - 4][y + 4] = 5;
					}
					if (BackPlane[x - 2][y + 2] == 0){
						BackPlane[x - 2][y + 2] = 3;
					}
				}
			}
			// 세개 앞 한칸***********************************************************************
			// 가로
			if (BackPlane[x][y] == 1 && BackPlane[x][y + 2] == 1 && BackPlane[x][y + 3] == 1 && BackPlane[x][y + 4] == 1){
				if (BackPlane[x][y + 1] == 0){
					if (BackPlane[x][y + 1] == 0){
						BackPlane[x][y + 1] = 3;
					}
				}
			}
			// 세로
			if (BackPlane[x][y] == 1 && BackPlane[x + 2][y] == 1 && BackPlane[x + 3][y] == 1 && BackPlane[x + 4][y] == 1){
				if (BackPlane[x + 1][y] == 0){
					if (BackPlane[x + 1][y] == 0){
						BackPlane[x + 1][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane[x][y] == 1 && BackPlane[x + 2][y + 2] == 1 && BackPlane[x + 3][y + 3] == 1 && BackPlane[x + 4][y + 4] == 1){
				if (BackPlane[x + 1][y + 1] == 0){
					if (BackPlane[x + 1][y + 1] == 0){
						BackPlane[x + 1][y + 1] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane[x][y] == 1 && BackPlane[x - 2][y + 2] == 1 && BackPlane[x - 3][y + 3] == 1 && BackPlane[x - 4][y + 4] == 1){
				if (BackPlane[x - 1][y + 1] == 0){
					if (BackPlane[x - 1][y + 1] == 0){
						BackPlane[x - 1][y + 1] = 3;
					}
				}
			}

			// 세게 뒤 한칸************************************************************************
			// 가로
			if (BackPlane[x][y] == 1 && BackPlane[x][y + 1] == 1 && BackPlane[x][y + 2] == 1 && BackPlane[x][y + 4] == 1){
				if (BackPlane[x][y + 3] == 0){
					if (BackPlane[x][y + 3] == 0){
						BackPlane[x][y + 3] = 3;
					}
				}
			}
			// 세로
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y] == 1 && BackPlane[x + 2][y] == 1 && BackPlane[x + 4][y] == 1){
				if (BackPlane[x + 3][y] == 0){
					if (BackPlane[x + 3][y] == 0){
						BackPlane[x + 3][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane[x][y] == 1 && BackPlane[x + 1][y + 1] == 1 && BackPlane[x + 2][y + 2] == 1 && BackPlane[x + 4][y + 4] == 1){
				if (BackPlane[x + 3][y + 3] == 0){
					if (BackPlane[x + 3][y + 3] == 0){
						BackPlane[x + 3][y + 3] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane[x][y] == 1 && BackPlane[x - 1][y + 1] == 1 && BackPlane[x - 2][y + 2] == 1 && BackPlane[x - 4][y + 4] == 1){
				if (BackPlane[x + 3][y - 3] == 0){
					if (BackPlane[x + 3][y - 3] == 0){
						BackPlane[x + 3][y - 3] = 3;
					}
				}
			}
		}
	}
}

#endif