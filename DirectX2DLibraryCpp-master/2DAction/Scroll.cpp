#include "Scroll.h"
#include "Src/Engine/Engine.h"

Scroll::Scroll()
{
	m_CameraPos = Vec2(0.0f, 0.0f);
}

Scroll::~Scroll()
{

}

void Scroll::S_Update(Vec2 pos)
{
	m_CameraPos.X = pos.X ;

	m_window_width_half = 640.0f / 2.0f;
	m_window_height_half = 480.0f / 2.0f;
	m_stage_width = 1280.0f;
	m_stage_height = 480.0f;

	if (m_CameraPos.X - m_window_width_half < 0.0f)
	{
		m_CameraPos.X = m_window_width_half;
	}
	else if (m_CameraPos.X + m_window_width_half > m_stage_width)
	{
		m_CameraPos.X = m_stage_width - m_window_width_half;
	}

	if (m_CameraPos.Y - m_window_height_half < 0.0f)
	{
		m_CameraPos.Y = m_window_height_half;
	}
	else if (m_CameraPos.Y + m_window_height_half > m_stage_height)
	{
		m_CameraPos.Y = m_stage_height - m_window_height_half;
	}
}

void Scroll::S_Draw()
{
	m_position = ConvertWorldToScreen(Vec2(0.0f, 0.0f));

	Engine::DrawTexture(m_position.X, m_position.Y, "Bg");
	//Engine::DrawTexture(-m_CameraPos.X, m_position.Y, "Bg");
}

//ワールド→スクリーンへの座標変換
Vec2 Scroll::ConvertWorldToScreen(Vec2 world_pos)
{
	m_origin_pos = Vec2(
		m_CameraPos.X - (640.0f / 2.0f),
		m_CameraPos.Y - (480.0f / 2.0f));

	m_screen_pos = Vec2(
		world_pos.X - m_origin_pos.X,
		world_pos.Y - m_origin_pos.Y);

	return m_screen_pos;
}