#ifndef _ATTACK_2_H_
#define _ATTACK_2_H_

#define SIZE 19

#include <time.h>

int BackPlane_2013182034[SIZE][SIZE];
int temp_x_2013182034, temp_y_2013182034, rand_x_2013182034, rand_y_2013182034;
int Turn_2013182034[5];

void Attack_2013182034(int BackPlane_2013182034[SIZE][SIZE]);
void Defence_2013182034(int BackPlane_2013182034[SIZE][SIZE], int x, int y);

void WhiteAttack(int *x, int *y)
{
	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			// ○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○
			/* 세개*****************************************************************************/
			// 가로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i][j + 1] == 1 && BackPlane_2013182034[i][j + 2] == 1){
				if (BackPlane_2013182034[i][j - 1] == 0 || BackPlane_2013182034[i][j + 3] == 0){
					if (j == 0){
						BackPlane_2013182034[i][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane_2013182034[i][j + 3] = 6;
					}
					else{
						BackPlane_2013182034[i][j - 1] = 6;
						BackPlane_2013182034[i][j + 3] = 7;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j] == 1 && BackPlane_2013182034[i + 2][j] == 1){
				if (BackPlane_2013182034[i - 1][j] == 0 || BackPlane_2013182034[i + 3][j] == 0){
					if (j == 0){
						BackPlane_2013182034[i - 1][j] = 6;
					}
					else if (j == 16){
						BackPlane_2013182034[i + 3][j] = 6;
					}
					else{
						BackPlane_2013182034[i - 1][j] = 6;
						BackPlane_2013182034[i + 3][j] = 7;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j + 1] == 1 && BackPlane_2013182034[i + 2][j + 2] == 1){
				if (BackPlane_2013182034[i - 1][j - 1] == 0 || BackPlane_2013182034[i + 3][j + 3] == 0){
					if (j == 0){
						BackPlane_2013182034[i - 1][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane_2013182034[i + 3][j + 3] = 6;
					}
					else{
						BackPlane_2013182034[i - 1][j - 1] = 6;
						BackPlane_2013182034[i + 3][j + 3] = 7;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i - 1][j + 1] == 1 && BackPlane_2013182034[i - 2][j + 2] == 1){
				if (BackPlane_2013182034[i + 1][j - 1] == 0 || BackPlane_2013182034[i - 3][j + 3] == 0){
					if (j == 0){
						BackPlane_2013182034[i + 1][j - 1] = 6;
					}
					else if (j == 16){
						BackPlane_2013182034[i - 3][j + 3] = 6;
					}
					else{
						BackPlane_2013182034[i + 1][j - 1] = 6;
						BackPlane_2013182034[i - 3][j + 3] = 7;
					}
				}
			}
			/* 앞에 한칸 *************************************************************************/
			// 가로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i][j + 2] == 1 && BackPlane_2013182034[i][j + 3] == 1){
				if (BackPlane_2013182034[i][j - 1] == 0 || BackPlane_2013182034[i][j + 4] == 0 || BackPlane_2013182034[i][j + 1] == 0){
					if (BackPlane_2013182034[i][j + 1] == 0){
						BackPlane_2013182034[i][j + 1] = 6;
					}
					if (BackPlane_2013182034[i][j - 1] == 0){
						BackPlane_2013182034[i][j - 1] = 7;
					}
					if (BackPlane_2013182034[i][j + 4] == 0){
						BackPlane_2013182034[i][j + 4] = 8;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 2][j] == 1 && BackPlane_2013182034[i + 3][j] == 1){
				if (BackPlane_2013182034[i - 1][j] == 0 || BackPlane_2013182034[i + 4][j] == 0 || BackPlane_2013182034[i + 1][j] == 0){
					if (BackPlane_2013182034[i - 1][j] == 0){
						BackPlane_2013182034[i - 1][j] = 7;
					}
					if (BackPlane_2013182034[i + 4][j] == 0){
						BackPlane_2013182034[i + 4][j] = 8;
					}
					if (BackPlane_2013182034[i + 1][j] == 0){
						BackPlane_2013182034[i + 1][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 2][j + 2] == 1 && BackPlane_2013182034[i + 3][j + 3] == 1){
				if (BackPlane_2013182034[i - 1][j - 1] == 0 || BackPlane_2013182034[i + 4][j + 4] == 0 || BackPlane_2013182034[i + 1][j + 1] == 0){
					if (BackPlane_2013182034[i - 1][j - 1] == 0){
						BackPlane_2013182034[i - 1][j - 1] = 7;
					}
					if (BackPlane_2013182034[i + 4][j + 4] == 0){
						BackPlane_2013182034[i + 4][j + 4] = 8;
					}
					if (BackPlane_2013182034[i + 1][j + 1] == 0){
						BackPlane_2013182034[i + 1][j + 1] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i - 2][j + 2] == 1 && BackPlane_2013182034[i - 3][j + 3] == 1){
				if (BackPlane_2013182034[i + 1][j - 1] == 0 || BackPlane_2013182034[i - 4][j + 4] == 0 || BackPlane_2013182034[i - 1][j + 1] == 0){
					if (BackPlane_2013182034[i + 1][j - 1] == 0){
						BackPlane_2013182034[i + 1][j - 1] = 7;
					}
					if (BackPlane_2013182034[i - 4][j + 4] == 0){
						BackPlane_2013182034[i - 4][j + 4] = 8;
					}
					if (BackPlane_2013182034[i - 1][j + 1] == 0){
						BackPlane_2013182034[i - 1][j + 1] = 6;
					}
				}
			}
			/* 뒤에 한칸******************************************************************************************/
			// 가로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i][j + 1] == 1 && BackPlane_2013182034[i][j + 3] == 1){
				if (BackPlane_2013182034[i][j - 1] == 0 || BackPlane_2013182034[i][j + 4] == 0 || BackPlane_2013182034[i][j + 2] == 0){
					if (BackPlane_2013182034[i][j - 1] == 0){
						BackPlane_2013182034[i][j - 1] = 7;
					}
					if (BackPlane_2013182034[i][j + 4] == 0){
						BackPlane_2013182034[i][j + 4] = 8;
					}
					if (BackPlane_2013182034[i][j + 2] == 0){
						BackPlane_2013182034[i][j + 2] = 6;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j] == 1 && BackPlane_2013182034[i + 3][j] == 1){
				if (BackPlane_2013182034[i - 1][j] == 0 || BackPlane_2013182034[i + 4][j] == 0 || BackPlane_2013182034[i + 2][j] == 0){
					if (BackPlane_2013182034[i - 1][j] == 0){
						BackPlane_2013182034[i - 1][j] = 7;
					}
					if (BackPlane_2013182034[i + 4][j] == 0){
						BackPlane_2013182034[i + 4][j] = 8;
					}
					if (BackPlane_2013182034[i + 2][j] == 0){
						BackPlane_2013182034[i + 2][j] = 6;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j + 1] == 1 && BackPlane_2013182034[i + 3][j + 3] == 1){
				if (BackPlane_2013182034[i - 1][j - 1] == 0 || BackPlane_2013182034[i + 4][j + 4] == 0 || BackPlane_2013182034[i + 2][j + 2] == 0){
					if (BackPlane_2013182034[i - 1][j - 1] == 0){
						BackPlane_2013182034[i - 1][j - 1] = 7;
					}
					if (BackPlane_2013182034[i + 4][j + 4] == 0){
						BackPlane_2013182034[i + 4][j + 4] = 8;
					}
					if (BackPlane_2013182034[i + 2][j + 2] == 0){
						BackPlane_2013182034[i + 2][j + 2] = 6;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i - 1][j + 1] == 1 && BackPlane_2013182034[i - 3][j + 3] == 1){
				if (BackPlane_2013182034[i + 1][j - 1] == 0 || BackPlane_2013182034[i - 4][j + 4] == 0 || BackPlane_2013182034[i - 2][j + 2] == 0){
					if (BackPlane_2013182034[i + 1][j - 1] == 0){
						BackPlane_2013182034[i + 1][j - 1] = 7;
					}
					if (BackPlane_2013182034[i - 4][j + 4] == 0){
						BackPlane_2013182034[i - 4][j + 4] = 8;
					}
					if (BackPlane_2013182034[i - 2][j + 2] == 0){
						BackPlane_2013182034[i - 2][j + 2] = 6;
					}
				}
			}
			// 세개 앞 한칸***********************************************************************
			// 가로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i][j + 2] == 1 && BackPlane_2013182034[i][j + 3] == 1 && BackPlane_2013182034[i][j + 4] == 1){
				if (BackPlane_2013182034[i][j + 1] == 0){
					if (BackPlane_2013182034[i][j + 1] == 0){
						BackPlane_2013182034[i][j + 1] = 7;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 2][j] == 1 && BackPlane_2013182034[i + 3][j] == 1 && BackPlane_2013182034[i + 4][j] == 1){
				if (BackPlane_2013182034[i + 1][j] == 0){
					if (BackPlane_2013182034[i + 1][j] == 0){
						BackPlane_2013182034[i + 1][j] = 7;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 2][j + 2] == 1 && BackPlane_2013182034[i + 3][j + 3] == 1 && BackPlane_2013182034[i + 4][j + 4] == 1){
				if (BackPlane_2013182034[i + 1][j + 1] == 0){
					if (BackPlane_2013182034[i + 1][j + 1] == 0){
						BackPlane_2013182034[i + 1][j + 1] = 7;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i - 2][j + 2] == 1 && BackPlane_2013182034[i - 3][j + 3] == 1 && BackPlane_2013182034[i - 4][j + 4] == 1){
				if (BackPlane_2013182034[i - 1][j + 1] == 0){
					if (BackPlane_2013182034[i - 1][j + 1] == 0){
						BackPlane_2013182034[i - 1][j + 1] = 7;
					}
				}
			}

			// 세게 뒤 한칸************************************************************************
			// 가로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i][j + 1] == 1 && BackPlane_2013182034[i][j + 2] == 1 && BackPlane_2013182034[i][j + 4] == 1){
				if (BackPlane_2013182034[i][j + 3] == 0){
					if (BackPlane_2013182034[i][j + 3] == 0){
						BackPlane_2013182034[i][j + 3] = 7;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j] == 1 && BackPlane_2013182034[i + 2][j] == 1 && BackPlane_2013182034[i + 4][j] == 1){
				if (BackPlane_2013182034[i + 3][j] == 0){
					if (BackPlane_2013182034[i + 3][j] == 0){
						BackPlane_2013182034[i + 3][j] = 7;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i + 1][j + 1] == 1 && BackPlane_2013182034[i + 2][j + 2] == 1 && BackPlane_2013182034[i + 4][j + 4] == 1){
				if (BackPlane_2013182034[i + 3][j + 3] == 0){
					if (BackPlane_2013182034[i + 3][j + 3] == 0){
						BackPlane_2013182034[i + 3][j + 3] = 7;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[i][j] == 1 && BackPlane_2013182034[i - 1][j + 1] == 1 && BackPlane_2013182034[i - 2][j + 2] == 1 && BackPlane_2013182034[i - 4][j + 4] == 1){
				if (BackPlane_2013182034[i + 3][j - 3] == 0){
					if (BackPlane_2013182034[i + 3][j - 3] == 0){
						BackPlane_2013182034[i + 3][j - 3] = 7;
					}
				}
			}
		}
	}

	for (int i = 0; i < SIZE; ++i){
		for (int j = 0; j < SIZE; ++j){
			//if (CheckStone_2013182034 == 1){
				if (BackPlane_2013182034[j][i] == 3){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[0] = 1;
					break;
				}
				else if (BackPlane_2013182034[j][i] == 4 && Turn_2013182034[0] == 1){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[0] = 0;
					Turn_2013182034[1] = 1;
					break;
				}
				else if (BackPlane_2013182034[j][i] == 5 && Turn_2013182034[1] == 1){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[1] = 0;
					Turn_2013182034[2] = 1;
					break;
				}
				else if (BackPlane_2013182034[j][i] == 6 && Turn_2013182034[2] == 1){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[2] = 0;
					Turn_2013182034[3] = 1;
					break;
				}
				else if (BackPlane_2013182034[j][i] == 7 && Turn_2013182034[3] == 1){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[3] = 0;
					Turn_2013182034[4] = 1;
					break;
				}
				else if (BackPlane_2013182034[j][i] == 8 && Turn_2013182034[4] == 1){
					BackPlane_2013182034[j][i] = 1;
					*x = i;
					*y = j;
					Turn_2013182034[4] = 0;
					break;
				}
			//}
		}
	}
	//if (CheckStone_2013182034 == 1) {
		if (BackPlane_2013182034[temp_y_2013182034][temp_x_2013182034 + 1] == 0){
			BackPlane_2013182034[temp_y_2013182034][temp_x_2013182034 + 1] = 1;
			*x = temp_x_2013182034 + 1;
			*y = temp_y_2013182034;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034][temp_x_2013182034 - 1] == 0){
			BackPlane_2013182034[temp_y_2013182034][temp_x_2013182034 - 1] = 1;
			*x = temp_x_2013182034 - 1;
			*y = temp_y_2013182034;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034] == 0){
			BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034] = 1;
			*x = temp_x_2013182034;
			*y = temp_y_2013182034 + 1;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034] == 0){
			BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034] = 1;
			*x = temp_x_2013182034;
			*y = temp_y_2013182034 - 1;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034 - 1] == 0){
			BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034 - 1] = 1;
			*x = temp_x_2013182034 - 1;
			*y = temp_y_2013182034 + 1;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034 + 1] == 0){
			BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034 + 1] = 1;
			*x = temp_x_2013182034 + 1;
			*y = temp_y_2013182034 - 1;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034 - 1] == 0){
			BackPlane_2013182034[temp_y_2013182034 - 1][temp_x_2013182034 - 1] = 1;
			*x = temp_x_2013182034 - 1;
			*y = temp_y_2013182034 - 1;
			
		}
		else if (BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034 + 1] == 0){
			BackPlane_2013182034[temp_y_2013182034 + 1][temp_x_2013182034 + 1] = 1;
			*x = temp_x_2013182034 + 1;
			*y = temp_y_2013182034 + 1;
			
		}
		else {
			//srand((unsigned)time(NULL));
			while (BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 0 || BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 3 ||
				BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 4 || BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 5
				|| BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 6 || BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 7
				|| BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] == 8){
				rand_x_2013182034 = rand() % temp_x_2013182034;
				rand_y_2013182034 = rand() % temp_y_2013182034;
			}
			BackPlane_2013182034[rand_y_2013182034][rand_x_2013182034] = 1;
			*x = rand_x_2013182034;
			*y = rand_y_2013182034;
			
		}
	//}
}

void WhiteDefence(int x, int y)
{
	for (int x = 0; x < SIZE; ++x){
		for (int y = 0; y < SIZE; ++y){
			// ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
			/* 세개*****************************************************************************/
			// 가로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x][y + 1] == 2 && BackPlane_2013182034[x][y + 2] == 2){
				if (BackPlane_2013182034[x][y - 1] == 0 || BackPlane_2013182034[x][y + 3] == 0){
					if (y == 0){
						BackPlane_2013182034[x][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane_2013182034[x][y + 3] = 3;
					}
					else{
						BackPlane_2013182034[x][y - 1] = 3;
						BackPlane_2013182034[x][y + 3] = 4;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y] == 2 && BackPlane_2013182034[x + 2][y] == 2){
				if (BackPlane_2013182034[x - 1][y] == 0 || BackPlane_2013182034[x + 3][y] == 0){
					if (y == 0){
						BackPlane_2013182034[x - 1][y] = 3;
					}
					else if (y == 16){
						BackPlane_2013182034[x + 3][y] = 3;
					}
					else{
						BackPlane_2013182034[x - 1][y] = 3;
						BackPlane_2013182034[x + 3][y] = 4;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y + 1] == 2 && BackPlane_2013182034[x + 2][y + 2] == 2){
				if (BackPlane_2013182034[x - 1][y - 1] == 0 || BackPlane_2013182034[x + 3][y + 3] == 0){
					if (y == 0){
						BackPlane_2013182034[x - 1][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane_2013182034[x + 3][y + 3] = 3;
					}
					else{
						BackPlane_2013182034[x - 1][y - 1] = 3;
						BackPlane_2013182034[x + 3][y + 3] = 4;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x - 1][y + 1] == 2 && BackPlane_2013182034[x - 2][y + 2] == 2){
				if (BackPlane_2013182034[x + 1][y - 1] == 0 || BackPlane_2013182034[x - 3][y + 3] == 0){
					if (y == 0){
						BackPlane_2013182034[x + 1][y - 1] = 3;
					}
					else if (y == 16){
						BackPlane_2013182034[x - 3][y + 3] = 3;
					}
					else{
						BackPlane_2013182034[x + 1][y - 1] = 3;
						BackPlane_2013182034[x - 3][y + 3] = 4;
					}
				}
			}
			/* 앞에 한칸 *************************************************************************/
			// 가로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x][y + 2] == 2 && BackPlane_2013182034[x][y + 3] == 2){
				if (BackPlane_2013182034[x][y - 1] == 0 || BackPlane_2013182034[x][y + 4] == 0 || BackPlane_2013182034[x][y + 1] == 0){
					if (BackPlane_2013182034[x][y - 1] == 0){
						BackPlane_2013182034[x][y - 1] = 4;
					}
					if (BackPlane_2013182034[x][y + 4] == 0){
						BackPlane_2013182034[x][y + 4] = 5;
					}
					if (BackPlane_2013182034[x][y + 1] == 0){
						BackPlane_2013182034[x][y + 1] = 3;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 2][y] == 2 && BackPlane_2013182034[x + 3][y] == 2){
				if (BackPlane_2013182034[x - 1][y] == 0 || BackPlane_2013182034[x + 4][y] == 0 || BackPlane_2013182034[x + 1][y] == 0){
					if (BackPlane_2013182034[x - 1][y] == 0){
						BackPlane_2013182034[x - 1][y] = 4;
					}
					if (BackPlane_2013182034[x + 4][y] == 0){
						BackPlane_2013182034[x + 4][y] = 5;
					}
					if (BackPlane_2013182034[x + 1][y] == 0){
						BackPlane_2013182034[x + 1][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 2][y + 2] == 2 && BackPlane_2013182034[x + 3][y + 3] == 2){
				if (BackPlane_2013182034[x - 1][y - 1] == 0 || BackPlane_2013182034[x + 4][y + 4] == 0 || BackPlane_2013182034[x + 1][y + 1] == 0){
					if (BackPlane_2013182034[x - 1][y - 1] == 0){
						BackPlane_2013182034[x - 1][y - 1] = 4;
					}
					if (BackPlane_2013182034[x + 4][y + 4] == 0){
						BackPlane_2013182034[x + 4][y + 4] = 5;
					}
					if (BackPlane_2013182034[x + 1][y + 1] == 0){
						BackPlane_2013182034[x + 1][y + 1] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x - 2][y + 2] == 2 && BackPlane_2013182034[x - 3][y + 3] == 2){
				if (BackPlane_2013182034[x + 1][y - 1] == 0 || BackPlane_2013182034[x - 4][y + 4] == 0 || BackPlane_2013182034[x - 1][y + 1] == 0){
					if (BackPlane_2013182034[x + 1][y - 1] == 0){
						BackPlane_2013182034[x + 1][y - 1] = 4;
					}
					if (BackPlane_2013182034[x - 4][y + 4] == 0){
						BackPlane_2013182034[x - 4][y + 4] = 5;
					}
					if (BackPlane_2013182034[x - 1][y + 1] == 0){
						BackPlane_2013182034[x - 1][y + 1] = 3;
					}
				}
			}
			/* 뒤에 한칸******************************************************************************************/
			// 가로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x][y + 1] == 2 && BackPlane_2013182034[x][y + 3] == 2){
				if (BackPlane_2013182034[x][y - 1] == 0 || BackPlane_2013182034[x][y + 4] == 0 || BackPlane_2013182034[x][y + 2] == 0){
					if (BackPlane_2013182034[x][y - 1] == 0){
						BackPlane_2013182034[x][y - 1] = 4;
					}
					if (BackPlane_2013182034[x][y + 4] == 0){
						BackPlane_2013182034[x][y + 4] = 5;
					}
					if (BackPlane_2013182034[x][y + 2] == 0){
						BackPlane_2013182034[x][y + 2] = 3;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y] == 2 && BackPlane_2013182034[x + 3][y] == 2){
				if (BackPlane_2013182034[x - 1][y] == 0 || BackPlane_2013182034[x + 4][y] == 0 || BackPlane_2013182034[x + 2][y] == 0){
					if (BackPlane_2013182034[x - 1][y] == 0){
						BackPlane_2013182034[x - 1][y] = 4;
					}
					if (BackPlane_2013182034[x + 4][y] == 0){
						BackPlane_2013182034[x + 4][y] = 5;
					}
					if (BackPlane_2013182034[x + 2][y] == 0){
						BackPlane_2013182034[x + 2][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y + 1] == 2 && BackPlane_2013182034[x + 3][y + 3] == 2){
				if (BackPlane_2013182034[x - 1][y - 1] == 0 || BackPlane_2013182034[x + 4][y + 4] == 0 || BackPlane_2013182034[x + 2][y + 2] == 0){
					if (BackPlane_2013182034[x - 1][y - 1] == 0){
						BackPlane_2013182034[x - 1][y - 1] = 4;
					}
					if (BackPlane_2013182034[x + 4][y + 4] == 0){
						BackPlane_2013182034[x + 4][y + 4] = 5;
					}
					if (BackPlane_2013182034[x + 2][y + 2] == 0){
						BackPlane_2013182034[x + 2][y + 2] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x - 1][y + 1] == 2 && BackPlane_2013182034[x - 3][y + 3] == 2){
				if (BackPlane_2013182034[x + 1][y - 1] == 0 || BackPlane_2013182034[x - 4][y + 4] == 0 || BackPlane_2013182034[x - 2][y + 2] == 0){
					if (BackPlane_2013182034[x + 1][y - 1] == 0){
						BackPlane_2013182034[x + 1][y - 1] = 4;
					}
					if (BackPlane_2013182034[x - 4][y + 4] == 0){
						BackPlane_2013182034[x - 4][y + 4] = 5;
					}
					if (BackPlane_2013182034[x - 2][y + 2] == 0){
						BackPlane_2013182034[x - 2][y + 2] = 3;
					}
				}
			}
			// 세개 앞 한칸***********************************************************************
			// 가로
			if (BackPlane_2013182034[x][y] == 1 && BackPlane_2013182034[x][y + 2] == 1 && BackPlane_2013182034[x][y + 3] == 1 && BackPlane_2013182034[x][y + 4] == 1){
				if (BackPlane_2013182034[x][y + 1] == 0){
					if (BackPlane_2013182034[x][y + 1] == 0){
						BackPlane_2013182034[x][y + 1] = 3;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[x][y] == 1 && BackPlane_2013182034[x + 2][y] == 1 && BackPlane_2013182034[x + 3][y] == 1 && BackPlane_2013182034[x + 4][y] == 1){
				if (BackPlane_2013182034[x + 1][y] == 0){
					if (BackPlane_2013182034[x + 1][y] == 0){
						BackPlane_2013182034[x + 1][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[x][y] == 1 && BackPlane_2013182034[x + 2][y + 2] == 1 && BackPlane_2013182034[x + 3][y + 3] == 1 && BackPlane_2013182034[x + 4][y + 4] == 1){
				if (BackPlane_2013182034[x + 1][y + 1] == 0){
					if (BackPlane_2013182034[x + 1][y + 1] == 0){
						BackPlane_2013182034[x + 1][y + 1] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[x][y] == 1 && BackPlane_2013182034[x - 2][y + 2] == 1 && BackPlane_2013182034[x - 3][y + 3] == 1 && BackPlane_2013182034[x - 4][y + 4] == 1){
				if (BackPlane_2013182034[x - 1][y + 1] == 0){
					if (BackPlane_2013182034[x - 1][y + 1] == 0){
						BackPlane_2013182034[x - 1][y + 1] = 3;
					}
				}
			}

			// 세게 뒤 한칸************************************************************************
			// 가로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x][y + 1] == 2 && BackPlane_2013182034[x][y + 2] == 2 && BackPlane_2013182034[x][y + 4] == 2){
				if (BackPlane_2013182034[x][y + 3] == 0){
					if (BackPlane_2013182034[x][y + 3] == 0){
						BackPlane_2013182034[x][y + 3] = 3;
					}
				}
			}
			// 세로
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y] == 2 && BackPlane_2013182034[x + 2][y] == 2 && BackPlane_2013182034[x + 4][y] == 2){
				if (BackPlane_2013182034[x + 3][y] == 0){
					if (BackPlane_2013182034[x + 3][y] == 0){
						BackPlane_2013182034[x + 3][y] = 3;
					}
				}
			}
			// 정대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x + 1][y + 1] == 2 && BackPlane_2013182034[x + 2][y + 2] == 2 && BackPlane_2013182034[x + 4][y + 4] == 2){
				if (BackPlane_2013182034[x + 3][y + 3] == 0){
					if (BackPlane_2013182034[x + 3][y + 3] == 0){
						BackPlane_2013182034[x + 3][y + 3] = 3;
					}
				}
			}
			// 역대각
			if (BackPlane_2013182034[x][y] == 2 && BackPlane_2013182034[x - 1][y + 1] == 2 && BackPlane_2013182034[x - 2][y + 2] == 2 && BackPlane_2013182034[x - 4][y + 4] == 2){
				if (BackPlane_2013182034[x + 3][y - 3] == 0){
					if (BackPlane_2013182034[x + 3][y - 3] == 0){
						BackPlane_2013182034[x + 3][y - 3] = 3;
					}
				}
			}
		}
	}
}

#endif