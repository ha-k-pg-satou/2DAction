#ifndef Scroll_H_
#define Scroll_H_

#include "Src/Common/Vec.h"

class Scroll
{
public:
	Scroll();
	~Scroll();

	void S_Update(Vec2 pos);
	void S_Draw();
	Vec2 ConvertWorldToScreen(Vec2 world_pos);

private:
	Vec2 m_CameraPos;
	float m_speed;
	float m_window_width_half;
	float m_window_height_half;
	float m_stage_width;
	float m_stage_height;
	Vec2 m_origin_pos;
	Vec2 m_screen_pos;
	Vec2 m_position;
};

#endif
