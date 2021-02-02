#ifndef Player_H_
#define Player_H_

#include "Src/Common/Vec.h"
#include "Scroll.h"
#include "MapChip.h"
#include "Game.h"

class Player
{
public:
	Player();
	~Player();

	void Init();
	void P_Update();
	void P_Draw();
	Vec2 P_Getter();
	void StartJump();
	bool HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1);
	bool GetIsEnd();
	void SetIsEnd(bool is_end);

private:
	Vec2 m_position;
	Vec2 m_speed;
	float m_gravity;
	bool m_can_jump;
	Vec2 m_size;
	bool m_is_end;

	//Scroll scroll;
	//MapChip map_chip;
};

#endif
