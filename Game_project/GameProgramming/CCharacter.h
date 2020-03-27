#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "CVector.h"

#include"CTaskManager.h"


class CCharacter :public CTask{
public:


	~CCharacter();

	CCharacter(int Priority);

	//更新処理
	void Update();

	//描画処理
	void Render();
};
#endif