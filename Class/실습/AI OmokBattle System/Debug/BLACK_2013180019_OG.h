#ifndef _ATTACK_1_H_
#define _ATTACK_1_H_

int pan[20][20] = { 0 };

void BlackAttack( int *x, int *y )
{
	int x_, y_;
	//�� �� ¥�� ������ ���̸� �ٷ� ���ݽ���
	//���� �� ��
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
	//���� �װ�
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
	//�밢�� �װ� \ ����
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
	//----------------------�¸� ���� ��
	//���� O O O O +
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
	//���� O O O O +
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



	//--------------------O O O + O ���� �¸� ����

	//����
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
	//����
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
	//�밢�� \ ���
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
	//�밢�� / ���
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
	//-----------------�����¸� ���� ��

	//������ ���� +	O O + O + //������ �׳�



	//--------------------���----------------------------------------------------------------------------------

	//���� ¥�� ������ �Ѱ��� ���������� ������ ���� �ʿ䰡 ����.

	//���� ������� �ϼ� 2014.5.31 ���� 4��<<<<<<<<<<<<<<<<<<<<


	//-----------------------------���� �ſ�� (�޼���)---------------------------------------
	// O O + O ���
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
	//O ���
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

	//�밢 O O + O \���
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

	//�밢 ���� O O + O / ���
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
	//---------------------------------------���� �ſ�� ��-------------------------------------//

	//���� (3��)
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
	//���� (3��)
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
	//�밢�� \  ��� (3��)
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
	//�밢�� / ���(3��)
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

	//���� (2��)
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
	//�밢�� \ ��� (2��)
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
	//�밢�� /��� (2��)
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
	//-------------------��� ��------------------------------

	//-----------------------����-------------------
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>���� ���� �����ؾ��� <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//(2014 . 05 .31 ���� 6�� 30�� ��)

	//���� ����
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
	//���� ����
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
	//�밢 ���� \ ���
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
	//�밢 ���� / ��� 
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
	//�밢 ���� / ���
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
	//----���� ���� ��----

	//���� ����(3��)
	for (y_ = 1; y_ < 20; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_] == 1 && pan[x_ + 2][y_] == 1){
				//���� ¥�� ���ӵ� �� �߰�
				if (pan[x_ - 1][y_] == 0 && x_>1){//���ӵ� ���� �� ���� ����� ��
					*x = x_ - 1;
					*y = y_;
					pan[x_ - 1][y_] = 1;
					goto end;
				}
				//���ӵ� ���� �� ���� ������� �ʰ� �ڿ� ���
				else if (pan[x_ + 3][y_] == 0 && x_ < 17){
					*x = x_ + 3;
					*y = y_;
					pan[x_ + 3][y_] = 1;
					goto end;
				}
				else//�յڰ� �� ���� �׷��� 
					continue;
			}
		}
	}
	//���� ���� (3��)
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 20; ++x_){
			if (pan[x_][y_] == 1 && pan[x_][y_ + 1] == 1 && pan[x_][y_ + 2] == 1){
				//���η� ���� ���ӵ� ���� �߰�
				if (pan[x_][y_ - 1] == 0 && y_>1){
					*x = x_;
					*y = y_ - 1;
					pan[x_][y_ - 1] = 1;
					goto end;
				}
				//���ӵ� ���� ������ ���� 
				//�Ʒ��� �� �α�.
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
	//�밢�� ���� ���� \ ���
	for (y_ = 1; y_ < 18; ++y_){
		for (x_ = 1; x_ < 18; ++x_){
			// \��� ���� ���� 
			if (pan[x_][y_] == 1 && pan[x_ + 1][y_ + 1] == 1 && pan[x_ + 2][y_ + 2] == 1){
				if (pan[x_ - 1][y_ - 1] == 0 && x_>1 && y_>1){//������ �� ����
					*x = x_ - 1;
					*y = y_ - 1;
					pan[x_ - 1][y_ - 1] = 1;
					goto end;
				}
				else if (pan[x_ + 3][y_ + 3] == 0 && x_ < 17 && y_ < 17){//������ ���� -> �Ʒ����ٰ� �α�
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
	//�밢�� ���� ���� / ���
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
	//�ΰ�¥�� ���� ����
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
	//���� ���� (2��)
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
	//�밢�� ���� \ ��� (2��)
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
	//�밢�� ���� / ��� (2��)
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

	//--------------------���� ��---------------------

	//ó�� ���� (�Ѱ� ¥��)
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