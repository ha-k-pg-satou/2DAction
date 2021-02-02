#include "Slider.h"
#include "Src/Engine/Engine.h"

Slider::Slider()
{
	m_pos = Vec2(0.0f, 0.0f);
	m_size = Size(640.0f, 50.0f);
	m_min_val = 0.0f;
	m_max_val = 100.0f;
	m_current_val = 100.0f;
	m_target_val = 0.0f;
	m_speed = -0.05f;
	m_is_end = false;
}

Slider::~Slider()
{

}

void Slider::Init()
{
	m_pos = Vec2(0.0f, 0.0f);
	m_size = Size(640.0f, 50.0f);
	m_min_val = 0.0f;
	m_max_val = 100.0f;
	m_current_val = 100.0f;
	m_target_val = 0.0f;
	m_speed = -0.05f;
	m_is_end = false;
}

void Slider::S_Update()
{
	//方向
	float vec = m_target_val - m_current_val;

	if (vec == 0.0f)
	{
		return;
	}

	//現在値変動
	/*float sign = 1.0f;
	if (vec < 0.0f)
	{
		sign = -1.0f;
	}*/

	m_current_val += m_speed;

	if (m_current_val <= 0)
	{
		m_current_val = 0.0f;

		m_is_end = true;
	}

	//目標値オーバーチェック
	if (m_speed >= abs(vec))
	{
		m_current_val = m_target_val;
	}
}

void Slider::S_Draw()
{
	float percent = (m_current_val - m_min_val) / (m_max_val - m_min_val);
	//描画矩形のサイズ
	float wid = m_size.Width * percent;

	Engine::DrawRect(m_pos.X, m_pos.Y, wid, m_size.Height, 0xffffff);
}

bool Slider::GetIsEnd()
{
	return m_is_end;
}