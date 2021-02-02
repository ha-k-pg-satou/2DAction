#include "MapChip.h"
#include "Src/Engine/Engine.h"
#include "Scroll.h"

extern Scroll scroll;

#define Map_Height 8
#define Map_Width 20

MapChip::MapChip()
{
	m_chip_size = Vec2(64.0f, 64.0f);
	m_pos = Vec2(0.0f, 0.0f);
	m_is_active == true;
}

MapChip::~MapChip()
{
	
}

void MapChip::M_Draw()
{
	for (int y = 0; y < MAP_CHIP_MAX_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_MAX_X; x++)
		{
			//チップ番号取得
			int chip_id = m_MapArray[y][x];
			//無効な値化をチェック
			if (chip_id == 0)
			{
				continue;
			}

			m_tex_pos = Vec2(m_MapArray[y][x] % 4 * m_chip_size.X, m_MapArray[y][x] / 4 * m_chip_size.Y);
			m_pos = Vec2(x * m_chip_size.X, y * m_chip_size.Y);
			Vec2 Screen_Pos = scroll.ConvertWorldToScreen(m_pos);

			Engine::DrawTextureUV(Screen_Pos.X, Screen_Pos.Y, "MapChip", m_tex_pos.X, m_tex_pos.Y, m_chip_size.X, m_chip_size.Y);
		}
	}
}

bool MapChip::OnCollisionRectAndMap(Vec2 obj_pos, Vec2 obj_size, int number)
{
	//矩形の四頂点を割り出す
	Vec2 vertices[] =
	{
		//左上
		obj_pos,
		//右上
		Vec2(obj_pos.X + obj_size.X , obj_pos.Y),
		//右下
		Vec2(obj_pos.X + obj_size.X , obj_pos.Y + obj_size.Y),
		//左下
		Vec2(obj_pos.X , obj_pos.Y + obj_size.Y),
	};

	int vertex_mapchip_ids_w[4];
	int vertex_mapchip_ids_h[4];

	for (int i = 0; i < 4; i++)
	{
		vertex_mapchip_ids_w[i] = vertices[i].X / 64.0f;
		vertex_mapchip_ids_h[i] = vertices[i].Y / 64.0f;
	}

	for (int i = 0; i < 4; i++)
	{
		int w = vertex_mapchip_ids_w[i];
		int h = vertex_mapchip_ids_h[i];

		if ((w < 0 || w >= 64) &&
			(h < 0 || h >= 64))
		{
			continue;
		}

		if (m_MapArray[h][w] == number)
		{
			return true;
		}
	}

	return false;
}

bool MapChip::GetIsActive()
{
	return m_is_active;
}