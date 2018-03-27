#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

int pan[20][20] = { 0 };

void BlackAttack( int *x, int *y )
{
	int x_, y_;
	//네 개 짜리 공격이 보이면 바로 공격시작
	//가로 네 개
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1 && pan[x_ + 2][y_] == 1 && pan[x_ + 3][y_] == 1){
				if (pan[x_ - 1][y_] == 0 && x_ > 1){
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				else if (pan[x_ + 4][y_] == 0 && x_ < 16){
					*x = x_ + 4;
					*y = y_;
					pan[x_ + 4][y_] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//세로 네개
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1 && pan[x_][y_ + 2] == 1 && pan[x_][y_ + 3] == 1){
				if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_][y_ + 4] == 0 && y_ < 16){
					*x = x_;
					*y = y_ + 4;
					pan[x_][y_ + 4] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 네개 \ 방향
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_ + 2] == 1 && pan[x_ + 3][y_ + 3] == 1){
				if (pan[x_ - 1][y_ - 1] == 0 && x_>1 && y_>1){
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_ + 4][y_ + 4] == 0 && x_ < 16 && y_ < 16){
					*x = x_ + 4;
					*y = y_ + 4;
					pan[x_ + 4][y_ + 4] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			if (pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 1 && pan[x_ + 2][y_ + 1] == 1 && pan[x_ + 3][y_] == 1){
				if (pan[x_ - 1][y_ + 4] == 0 && x_>1 && y_ < 16){
					*x = x_ - 1;
					*y = y_ + 4;
					pan[x_ - 1][y_ + 4] = 1;
					goto end;
				}
				else if (pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
					*x = x_ + 4;
					*y = y_ - 1;
					pan[x_ + 4][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//----------------------승리 공격 끝
	//가로 O O O O +
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 15; ++x_){
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2 && pan[x_ + 2][y_] == 2 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_] == 0){
				*x = x_ + 4;
				*y = y_;
				pan[x_ + 4][y_] = 1;
				goto end;
			}
		}
	}
	//세로 O O O O +
	for (y_ = 1; y_ < 15; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 2 && pan[x_][y_ + 2] == 2 && pan[x_][y_ + 3] == 2 && pan[x_][y_ + 4] == 0){
				*x = x_;
				*y = y_ + 4;
				pan[x_][y_ + 4] = 1;
				goto end;
			}
		}
	}



	//--------------------O O O + O 최종 승리 막기

	//가로
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 15; ++x_){
			//O O O + O
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2 && pan[x_ + 2][y_] == 2 && pan[x_ + 3][y_] == 0 && pan[x_ + 4][y_] == 2){
				*x = x_ + 3;
				*y = y_;
				pan[x_ + 3][y_] = 1;
				goto end;
			}
			else if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 0 && pan[x_ + 2][y_] == 2 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_] == 2){
				*x = x_ + 1;
				*y = y_;
				pan[x_ + 1][y_] = 1;
				goto end;
			}
		}
	}
	//세로
	for (y_ = 1; y_ < 15; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			// O O O + O
			if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 2 && pan[x_][y_ + 2] == 2 && pan[x_][y_ + 3] == 0 && pan[x_][y_ + 4] == 2){
				*x = x_;
				*y = y_ + 3;
				pan[x_][y_ + 3] = 1;
				goto end;
			}
			else if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 0 && pan[x_][y_ + 2] == 2 && pan[x_][y_ + 3] == 2 && pan[x_][y_ + 4] == 2){
				*x = x_;
				*y = y_ + 1;
				pan[x_][y_ + 1] = 1;
				goto end;
			}
		}
	}
	//대각선 \ 모양
	for (y_ = 1; y_ < 15; ++y_){
		for (x_ = 1; x_ < 15; ++x_){
			// O O O + O
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 2 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 3] == 0 && pan[x_ + 4][y_ + 4] == 2){
				*x = x_ + 3;
				*y = y_ + 3;
				pan[x_ + 3][y_ + 3] = 1;
				goto end;
			}
			// O + O O O
			else if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 0 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 3] == 2 && pan[x_ + 4][y_ + 4] == 2){
				*x = x_ + 1;
				*y = y_ + 1;
				pan[x_ + 1][y_ + 1] = 1;
				goto end;
			}
		}
	}
	//대각선 / 모양
	for (y_ = 1; y_ < 15; ++y_){
		for (x_ = 1; x_ < 15; ++x_){
			//O O O + O
			if (pan[x_][y_ + 4] == 2 && pan[x_ + 1][y_ + 3] == 2 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 1] == 0 && pan[x_ + 4][y_] == 2){
				*x = x_ + 3;
				*y = y_ + 1;
				pan[x_ + 3][y_ + 1] = 1;
				goto end;
			}//O + O O O
			else if (pan[x_][y_ + 4] == 2 && pan[x_ + 1][y_ + 3] == 0 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 1] == 2 && pan[x_ + 4][y_] == 2){
				*x = x_ + 1;
				*y = y_ + 3;
				pan[x_ + 1][y_ + 3] = 1;
				goto end;
			}
		}
	}
	//-----------------최종승리 막기 끝

	//하이퍼 어택 +	O O + O + //하지마 그냥



	//--------------------방어----------------------------------------------------------------------------------

	//세개 짜리 막을때 한곳이 막혀있으면 당장은 막을 필요가 없다.

	//방어는 어느정도 완성 2014.5.31 오후 4시<<<<<<<<<<<<<<<<<<<<


	//-----------------------------빵꾸 매우기 (급선무)---------------------------------------
	// O O + O 방어
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2 && pan[x_ + 2][y_] == 0 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_] == 0 && x_ < 16){
				*x = x_ + 2;
				*y = y_;
				pan[x_ + 2][y_] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_] == 0 && pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2 && pan[x_ + 2][y_] == 0 && pan[x_ + 3][y_] == 2 && x_ > 1){
				*x = x_ + 2;
				*y = y_;
				pan[x_ + 2][y_] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 0 && pan[x_ + 2][y_] == 2 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_] == 0 && x_ < 16){
				*x = x_ + 1;
				*y = y_;
				pan[x_ + 1][y_] = 1;
				goto end;
			}
			// + O + O O 
			else if (pan[x_ - 1][y_] == 0 && pan[x_][y_] == 2 && pan[x_ + 1][y_] == 0 && pan[x_ + 2][y_] == 2 && pan[x_ + 3][y_] == 2 && x_ > 1){
				*x = x_ + 1;
				*y = y_;
				pan[x_ + 1][y_] = 1;
				goto end;
			}
			else
				continue;
		}
	}
	//O
	//O
	//+
	//O 방어
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			//O
			//O
			//+
			//O
			//+
			if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 2 && pan[x_][y_ + 2] == 0 && pan[x_][y_ + 3] == 2 && pan[x_][y_ + 4] == 0 && y_ < 16){
				*x = x_;
				*y = y_ + 2;
				pan[x_][y_ + 2] = 1;
				goto end;
			}
			//+
			//O
			//O
			//+
			//O
			else if (pan[x_][y_ - 1] == 0 && pan[x_][y_] == 2 && pan[x_][y_ + 1] == 2 && pan[x_][y_ + 2] == 0 && pan[x_][y_ + 3] == 2 && y_ > 1){
				*x = x_;
				*y = y_ + 2;
				pan[x_][y_ + 2] = 1;
				goto end;
			}
			//O
			//+
			//O
			//O
			//+
			else if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 0 && pan[x_][y_ + 2] == 2 && pan[x_][y_ + 3] == 2 && pan[x_][y_ + 4] == 0 && y_ < 16){
				*x = x_;
				*y = y_ + 1;
				pan[x_][y_ + 1] = 1;
				goto end;
			}
			//+
			//O
			//+
			//O
			//O
			else if (pan[x_][y_ - 1] == 0 && pan[x_][y_] == 2 && pan[x_][y_ + 1] == 0 && pan[x_][y_ + 2] == 2 && pan[x_][y_ + 3] == 2 && y_>1){
				*x = x_;
				*y = y_ + 1;
				pan[x_][y_ + 1] = 1;
				goto end;
			}
			else
				continue;
		}
	}

	//대각 O O + O \모양
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 2 && pan[x_ + 2][y_ + 2] == 0 && pan[x_ + 3][y_ + 3] == 2 && pan[x_ + 4][y_ + 4] == 0 && x_ < 16 && y_ < 16){
				*x = x_ + 2;
				*y = y_ + 2;
				pan[x_ + 2][y_ + 2] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_ - 1] == 0 && pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 2 && pan[x_ + 2][y_ + 2] == 0 && pan[x_ + 3][y_ + 3] == 2 && x_>1 && y_>1){
				*x = x_ + 2;
				*y = y_ + 2;
				pan[x_ + 2][y_ + 2] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 0 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 3] == 2 && pan[x_ + 4][y_ + 4] == 0 && x_ < 16 && y_ < 16){
				*x = x_ + 1;
				*y = y_ + 1;
				pan[x_ + 1][y_ + 1] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_ - 1][y_ - 1] == 0 && pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 0 && pan[x_ + 2][y_ + 2] == 2 && pan[x_ + 3][y_ + 3] == 2 && x_>1 && y_>1){
				*x = x_ + 1;
				*y = y_ + 1;
				pan[x_ + 1][y_ + 1] = 1;
				goto end;
			}
		}
	}

	//대각 빵꾸 O O + O / 모양
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_ + 3] == 2 && pan[x_ + 1][y_ + 2] == 2 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 2;
				*y = y_ + 1 ;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 2 && pan[x_ + 1][y_ + 2] == 2 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 2 && x_>1 && y_ < 16){
				*x = x_ + 2;
				*y = y_ + 1;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_ + 3] == 2 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 2 && pan[x_ + 3][y_] == 2 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 1;
				*y = y_ + 2;
				pan[x_ + 1][y_ + 2] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 2 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 2 && pan[x_ + 3][y_] == 2 && x_>1 && y_ < 16){
				*x = x_ + 1;
				*y = y_ + 2;
				pan[x_ + 1][y_ + 2] = 1;
				goto end;
			}
		}
	}
	//---------------------------------------빵꾸 매우기 끝-------------------------------------//

	//가로 (3개)
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2 && pan[x_ + 2][y_] == 2){
				if (pan[x_ - 1][y_] == 1 || pan[x_ + 3][y_] == 1){
					continue;
				}
				if (pan[x_ - 1][y_] == 0 && x_ > 1){
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_] == 0 && x_ < 17){
					*x = x_ + 3;
					*y = y_;
					pan[x_ + 3][y_] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//세로 (3개)
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 2 && pan[x_][y_ + 1] == 2 && pan[x_][y_ + 2] == 2){
				if (pan[x_][y_ - 1] == 1 || pan[x_][y_ + 3] == 1){
					continue;
				}
				if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_][y_ + 3] == 0 && y_ < 17){
					*x = x_;
					*y = y_ + 3;
					pan[x_][y_ + 3] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 \  모양 (3개)
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 2 && pan[x_ + 2][y_ + 2] == 2){
				if (pan[x_ - 1][y_ - 1] == 1 || pan[x_ + 3][y_ + 3] == 1){
					continue;
				}
				if (pan[x_ - 1][y_ - 1] == 0 && x_ > 1 && y_ > 1){
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_ + 3] == 0 && x_ < 17 && y_ < 17){
					*x = x_ + 3;
					*y = y_ + 3;
					pan[x_ + 3][y_ + 3] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 / 모양(3개)
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_ + 2] == 2 && pan[x_ + 1][y_ + 1] == 2 && pan[x_ + 2][y_] == 2){
				if (pan[x_ - 1][y_ + 3] == 1 || pan[x_ + 3][y_ - 1] == 1){
					continue;
				}
				if (pan[x_ - 1][y_ + 3] == 0 && y_ < 17 && x_ > 1){
					*x = x_ - 1;
					*y = y_ + 3;
					pan[x_ - 1][y_ + 3] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_ - 1] == 0 && x_ < 17 && y_ > 1){
					*x = x_ + 3;
					*y = y_ - 1;
					pan[x_ + 3][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}

	//가로 (2개)
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_] == 2){
				if (pan[x_ - 1][y_] != 0 || pan[x_ + 2][y_] != 0){
					continue;
				}
				if (pan[x_ - 1][y_] == 0 && x_ > 1){
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				else if (pan[x_ + 2][y_] == 0 && x_ < 17){
					*x = x_ + 2;
					*y = y_;
					pan[x_ + 2][y_] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 \ 모양 (2개)
	for (y_ = 1; y_ < 19; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_] == 2 && pan[x_ + 1][y_ + 1] == 2){
				if (pan[x_ + 2][y_ + 2] != 0 || pan[x_ - 1][y_ - 1] != 0){
					continue;
				}
				if (pan[x_ + 2][y_ + 2] == 0 && x_ < 18 && y_ < 18){
					*x = x_ + 2;
					*y = y_ + 2;
					pan[x_ + 2][y_ + 2] = 1;
					goto end;
				}
				else if (pan[x_ - 1][y_ - 1] == 0 && x_ > 1 && y_ > 1){
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 /모양 (2개)
	for (y_ = 1; y_ < 19; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_ + 1] == 2 && pan[x_ + 1][y_] == 2){
				if (pan[x_ - 1][y_ + 2] != 0 || pan[x_ + 2][y_ - 1] != 0){
					continue;
				}
				if (pan[x_ - 1][y_ + 2] == 0 && x_>1 && y_ < 18){
					*x = x_ - 1;
					*y = y_ + 2;
					pan[x_ - 1][y_ + 2] = 1;
					goto end;
				}
				else if (pan[x_ + 2][y_ - 1] == 0 && x_<18 && y_>1){
					*x = x_ + 2;
					*y = y_ - 1;
					pan[x_ + 2][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//-------------------방어 끝------------------------------

	//-----------------------공격-------------------
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>빵꾸 공격 구현해야함 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//(2014 . 05 .31 오후 6시 30분 경)

	//가로 빵꾸
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1 && pan[x_ + 2][y_] == 0 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_] == 0 && x_ < 16){
				*x = x_ + 2;
				*y = y_;
				pan[x_ + 2][y_] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_] == 0 && pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1 && pan[x_ + 2][y_] == 0 && pan[x_ + 3][y_] == 1 && x_ > 1){
				*x = x_ + 2;
				*y = y_;
				pan[x_ + 2][y_] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 0 && pan[x_ + 2][y_] == 1 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_] == 0 && x_ < 16){
				*x = x_ + 1;
				*y = y_;
				pan[x_ + 1][y_] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_ - 1][y_] == 0 && pan[x_][y_] == 1 && pan[x_ + 1][y_] == 0 && pan[x_ + 2][y_] == 1 && pan[x_ + 3][y_] == 1 && x_>1){
				*x = x_ + 1;
				*y = y_;
				pan[x_ + 1][y_] = 1;
				goto end;
			}
		}
	}
	//세로 빵꾸
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			// O O + O +
			if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1 && pan[x_][y_ + 2] == 0 && pan[x_][y_ + 3] == 1 && pan[x_][y_ + 4] == 0 && y_ < 16){
				*x = x_;
				*y = y_ + 2;
				pan[x_][y_ + 2] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_][y_ - 1] == 0 && pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1 && pan[x_][y_ + 2] == 0 && pan[x_][y_ + 3] == 1 && y_ > 1){
				*x = x_;
				*y = y_ + 2;
				pan[x_][y_ + 2] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 0 && pan[x_][y_ + 2] == 1 && pan[x_][y_ + 3] == 1 && pan[x_][y_ + 4] == 0 && y_ < 16){
				*x = x_;
				*y = y_ + 1;
				pan[x_][y_ + 1] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_][y_ - 1] == 0 && pan[x_][y_] == 1 && pan[x_][y_ + 1] == 0 && pan[x_][y_ + 2] == 1 && pan[x_][y_ + 3] == 1 && y_>1){
				*x = x_;
				*y = y_ + 1;
				pan[x_][y_ + 1] = 1;
				goto end;
			}
		}
	}
	//대각 빵꾸 \ 모양
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_ + 2] == 0 && pan[x_ + 3][y_ + 3] == 1 && pan[x_ + 4][y_ + 4] == 0 && y_ < 16){
				*x = x_ + 2;
				*y = y_ + 2;
				pan[x_ + 2][y_ + 2] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_ - 1] == 0 && pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_ + 2] == 0 && pan[x_ + 3][y_ + 3] == 1 && x_>1 && y_>1){
				*x = x_ + 2;
				*y = y_ + 2;
				pan[x_ + 2][y_ + 2] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 0 && pan[x_ + 2][y_ + 2] == 1 && pan[x_ + 3][y_ + 3] == 1 && pan[x_ + 4][y_ + 4] == 0 && x_ < 16 && y_ < 16){
				*x = x_ + 1;
				*y = y_ + 1;
				pan[x_ + 1][y_ + 1] = 1;
				goto end;
			}
			// + O + O O 
			else if (pan[x_ - 1][y_ - 1] == 0 && pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 0 && pan[x_ + 2][y_ + 2] == 1 && pan[x_ + 3][y_ + 3] == 1 && x_>1 && y_>1){
				*x = x_ + 1;
				*y = y_ + 1;
				pan[x_ + 1][y_ + 1] = 1;
				goto end;
			}
		}
	}
	//대각 빵꾸 / 모양 
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 1 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 2;
				*y = y_ + 1;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// + O O + O
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 1 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 1 && x_>1 && y_ < 16){
				*x = x_ + 2;
				*y = y_ + 1;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 1 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 4;
				*y = y_ - 1;
				pan[x_ + 4][y_ - 1] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 1 && pan[x_ + 3][y_] == 1 && x_>1 && x_ < 16){
				*x = x_ + 1;
				*y = y_ + 2;
				pan[x_ + 1][y_ + 2] = 1;
				goto end;
			}
		}
	}
	//대각 빵꾸 / 모양
	for (y_ = 1; y_ < 17; ++y_){
		for (x_ = 1; x_ < 17; ++x_){
			// O O + O +
			if (pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 1 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 2;
				*y = y_ + 1;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// + O O + O 
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 1 && pan[x_ + 2][y_ + 1] == 0 && pan[x_ + 3][y_] == 1 && x_>1 && y_ < 16){
				*x = x_ + 2;
				*y = y_ + 1;
				pan[x_ + 2][y_ + 1] = 1;
				goto end;
			}
			// O + O O +
			else if (pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 1 && pan[x_ + 3][y_] == 1 && pan[x_ + 4][y_ - 1] == 0 && x_<16 && y_>1){
				*x = x_ + 1;
				*y = y_ + 2;
				pan[x_ + 1][y_ + 2] = 1;
				goto end;
			}
			// + O + O O
			else if (pan[x_ - 1][y_ + 4] == 0 && pan[x_][y_ + 3] == 1 && pan[x_ + 1][y_ + 2] == 0 && pan[x_ + 2][y_ + 1] == 1 && pan[x_ + 3][y_] == 1 && x_>1 && y_ < 16){
				*x = x_ + 1;
				*y = y_ + 2;
				pan[x_ + 1][y_ + 2] = 1;
				goto end;
			}
		}
	}
	//----빵꾸 공격 끝----

	//가로 공격(3개)
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1 && pan[x_ + 2][y_] == 1){
				//세개 짜리 연속된 돌 발견
				if (pan[x_ - 1][y_] == 0 && x_>1){//연속된 돌의 맨 앞이 비었을 때
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				//연속된 돌의 맨 앞이 비어있지 않고 뒤에 비면
				else if (pan[x_ + 3][y_] == 0 && x_ < 17){
					*x = x_ + 3;
					*y = y_;
					pan[x_ + 3][y_] = 1;
					goto end;
				}
				else//앞뒤가 다 막힘 그러면 
					continue;
			}
		}
	}
	//세로 공격 (3개)
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1 && pan[x_][y_ + 2] == 1){
				//세로로 세번 연속된 돌을 발견
				if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
				//연속된 돌의 위에가 막힘 
				//아래에 돌 두기.
				else if (pan[x_][y_ + 3] == 0 && y_ < 17){
					*x = x_;
					*y = y_ + 3;
					pan[x_][y_ + 3] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 세개 공격 \ 모양
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			// \모양 세개 연속 
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_ + 2] == 1){
				if (pan[x_ - 1][y_ - 1] == 0 && x_>1 && y_>1){//위에가 안 막힘
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_ + 3] == 0 && x_ < 17 && y_ < 17){//위에가 막힘 -> 아래에다가 두기
					*x = x_ + 3;
					*y = y_ + 3;
					pan[x_ + 3][y_ + 3] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 세개 공격 / 모양
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_ + 2] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_] == 1){
				if (pan[x_ - 1][y_ + 3] == 0 && y_ < 17 && x_ > 1){
					*x = x_ - 1;
					*y = y_ + 3;
					pan[x_ - 1][y_ + 3] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_ - 1] == 0 && x_ < 17 && y_ > 1){
					*x = x_ + 3;
					*y = y_ - 1;
					pan[x_ + 3][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//두개짜리 공격 시작
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1){
				if (pan[x_ - 1][y_] == 0 && x_>1){
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				else if (pan[x_ + 2][y_] == 0 && x_ < 18){
					*x = x_ + 2;
					*y = y_;
					pan[x_ + 2][y_] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//세로 공격 (2개)
	for (y_ = 1; y_ < 19; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1){
				if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_][y_ + 2] == 0 && y_ < 18){
					*x = x_;
					*y = y_ + 2;
					pan[x_][y_ + 2] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 공격 \ 모양 (2개)
	for (y_ = 1; y_ < 19; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1){
				if (pan[x_ + 2][y_ + 2] == 0 && x_ < 18 && y_ < 18){
					*x = x_ + 2;
					*y = y_ + 2;
					pan[x_ + 2][y_ + 2] = 1;
					goto end;
				}
				else if (pan[x_ - 1][y_ - 1] == 0 && x_>1 && y_>1){
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}
	//대각선 공격 / 모양 (2개)
	for (y_ = 1; y_ < 19; ++y_){
		for (x_ = 1; x_ < 19; ++x_){
			if (pan[x_][y_ + 1] == 1 && pan[x_ + 1][y_] == 1){
				if (pan[x_ - 1][y_ + 2] == 0 && x_>1 && y_ < 18){
					*x = x_ - 1;
					*y = y_ + 2;
					pan[x_ - 1][y_ + 2] = 1;
					goto end;
				}
				else if (pan[x_ + 2][y_ - 1] == 0 && x_ < 18 && y_>1){
					*x = x_ + 2;
					*y = y_ - 1;
					pan[x_ + 2][y_ - 1] = 1;
					goto end;
				}
				else
					continue;
			}
		}
	}

	//--------------------공격 끝---------------------

	//처음 시작 (한개 짜리)
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 2){
				if (pan[x_ + 1][y_] == 0 && x_ < 19){
					*x = x_ + 1;
					*y = y_;
					pan[x_ + 1][y_] = 1;
					goto end;
				}
				else if (pan[x_ - 1][y_] == 0 && x_>1){
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				else if (pan[x_][y_ + 1] == 0 && y_ < 19){
					*x = x_;
					*y = y_ + 1;
					pan[x_][y_ + 1] = 1;
					goto end;
				}
				else if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
			}
		}
	}
	x_ = 10;
	y_ = 10;
	*x = x_;
	*y = y_;
	pan[x_][y_] = 1;
	goto end;

end: return;
}

void BlackDefence( int x, int y )
{
	pan[x][y] = 2;
}


#endif