#include "OmokBattleSystem.h"
//---- 이곳에 Header File을 Include 하세요 ----
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

	//------------ 이곳에 자신의 함수를 넣으세요.-------------------------
	//
	// 앞에 2곳은 흑돌을 할 Attack, Defnece 함수이름 
	// 뒤에 2곳은 백돌을 할 Attack, Defence 함수이름을 넣으시면 됩니다.
	//
	//--------------------------------------------------------------------

	OmokGame.SetYourFunc( 
		/*흑돌Attack*/ BlackAttack, /*흑돌Defence*/BlackDefence, 
		/*백돌Attack*/ WhiteAttack, /*백돌Defence*/WhiteDefence);

	if( OmokGame.BeginGame() )
		OmokGame.Result();

	return 0;
}