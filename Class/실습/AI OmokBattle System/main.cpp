#include "OmokBattleSystem.h"
//---- �̰��� Header File�� Include �ϼ��� ----
// ex)
//#include "BLACK_4444444444.h"	
//#include "WHITE_6666666666.h"
//

#include "BLACK_2013180019_OG.h"
#include "Attack_2.h"
//---------------------------------------------

int main()
{
	COmokBattleSytem OmokGame;

	OmokGame.Init();

	//------------ �̰��� �ڽ��� �Լ��� ��������.-------------------------
	//
	// �տ� 2���� �浹�� �� Attack, Defnece �Լ��̸� 
	// �ڿ� 2���� �鵹�� �� Attack, Defence �Լ��̸��� �����ø� �˴ϴ�.
	//
	//--------------------------------------------------------------------

	OmokGame.SetYourFunc( 
		/*�浹Attack*/ BlackAttack, /*�浹Defence*/BlackDefence, 
		/*�鵹Attack*/ WhiteAttack, /*�鵹Defence*/WhiteDefence);

	if( OmokGame.BeginGame() )
		OmokGame.Result();

	return 0;
}