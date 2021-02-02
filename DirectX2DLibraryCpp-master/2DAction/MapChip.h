#ifndef MapChip_H_
#define MapChip_H_
#define MAP_CHIP_ALL   (16)					// マップチップの数
#define MAP_CHIP_X     (4)					// マップチップの横幅の数
#define MAP_CHIP_Y     (4)					// マップチップの縦幅の数
#define SIZE_MAP_X     (64)					// マップチップの縦幅
#define SIZE_MAP_Y     (64)		            // マップチップの縦幅
#define MAP_CHIP_MAX_X (20)		            // ステージの縦幅
#define MAP_CHIP_MAX_Y (8)		            // ステージの横幅

#include "Src/Common/Vec.h"
#include "Scroll.h"

enum MapChipId
{
	OneBlock = 1,
	TwoBlock,
	ThreeBlock,
	FourBlock,
	FiveBlock,
	SixBlock,
	SevenBlock,
	EightBlock,
	NineBlock,
	TenBlock,
	ElevenBlock,
	TwelveBlock,
	ThirteenBlock,
	FourteenBlock,
	FifteenBlock
};

class MapChip
{
public:
	MapChip();
	~MapChip();

	bool OnCollisionRectAndMap(Vec2 obj_pos, Vec2 obj_size, int number);
	void M_Draw();

	bool GetIsActive();

private:
	int m_MapArray[MAP_CHIP_MAX_Y][MAP_CHIP_MAX_X] =
	{
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	};
	/*struct m_rect
	{
		float Top;
		float Bottom;
		float Left;
		float Right;
	};*/
	Vec2 m_pos;
	Vec2 m_chip_size;
	bool m_is_active;
	int m_chip_data[MAP_CHIP_ALL];
	Vec2 m_tex_pos;

	//Scroll scroll;
};

#endif
