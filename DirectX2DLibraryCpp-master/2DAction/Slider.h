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
	Vec2 m_pos;				// ���W
	Size m_size;			// �T�C�Y
	float m_min_val;		// �ŏ��l
	float m_max_val;		// �ő�l
	float m_current_val;	// ���ݒl
	float m_target_val;		// �ڕW�l
	float m_speed;			// ���x
	bool m_is_end;
	
};

#endif
