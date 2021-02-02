#ifndef Slider_H_
#define Slider_H_

#include "Src/Common/Size.h"
#include "Src/Common/Vec.h"
#include "Player.h"

class Slider
{
public:
	Slider();
	~Slider();

	void Init();
	void S_Update();
	void S_Draw();

	bool GetIsEnd();
private:
	Vec2 m_pos;				// 座標
	Size m_size;			// サイズ
	float m_min_val;		// 最小値
	float m_max_val;		// 最大値
	float m_current_val;	// 現在値
	float m_target_val;		// 目標値
	float m_speed;			// 速度
	bool m_is_end;
	
};

#endif
