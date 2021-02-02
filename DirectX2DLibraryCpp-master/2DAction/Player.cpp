#include "Player.h"
#include "Src/Engine/Engine.h"

extern Scroll scroll;
extern MapChip map_chip;

Player::Player()
{
	m_speed = Vec2(4.0f, 0.0f);
	m_gravity = 1.0f;
	m_can_jump = true;
	m_size = Vec2(40.0f, 40.0f);
	m_is_end = false;
}

Player::~Player()
{

}

void Player::Init()
{
	m_can_jump = true;
	m_position = Vec2(300.0f, 400.0f);
	m_is_end = false;
}

void Player::P_Update()
{
	Vec2 Vector = Vec2(0.0f, 0.0f);

	Engine::Update();

	//Aキーで左に移動
	if (Engine::IsKeyboardKeyHeld(DIK_A))
	{
		Vector.X = -m_speed.X;
	}
	//Dキーで左に移動
	if (Engine::IsKeyboardKeyHeld(DIK_D))
	{
		Vector.X = m_speed.X;
	}
	//Wキーでジャンプ
	if (Engine::IsKeyboardKeyPushed(DIK_W))
	{
		StartJump();
	}

	if (m_can_jump == false)
	{
		m_speed.Y -= m_gravity;
		Vector.Y = -m_speed.Y;
	}
	
	//0との当たり判定
	if (map_chip.OnCollisionRectAndMap(Vec2(m_position.X + Vector.X, m_position.Y + Vector.Y), m_size, 0) == true)
	{
		m_position.X += Vector.X;
		m_position.Y += Vector.Y;
	}
	//1との当たり判定
	if (map_chip.OnCollisionRectAndMap(Vec2(m_position.X + Vector.X, m_position.Y + Vector.Y), m_size, 1) == true)
	{
		m_can_jump = true;
	}
	//2との当たり判定
	if (map_chip.OnCollisionRectAndMap(Vec2(m_position.X + Vector.X, m_position.Y + Vector.Y), m_size, 2) == true)
	{
		if (m_position.X < 100)
		{
			m_position.X += m_speed.X;
		}
		else
		{
			m_position.X -= m_speed.X;
		}
	}
	//3との当たり判定
	if (map_chip.OnCollisionRectAndMap(Vec2(m_position.X + Vector.X, m_position.Y + Vector.Y), m_size, 3) == true)
	{
		m_is_end = true;
	}
}

void Player::P_Draw()
{
	Vec2 CameraPos = scroll.ConvertWorldToScreen(m_position);
	//Engine::DrawTexture(m_position.X, m_position.Y, "Enemy");
	Engine::DrawTexture(CameraPos.X, CameraPos.Y, "Enemy");
}

Vec2 Player::P_Getter()
{
	return m_position;
}

bool Player::GetIsEnd()
{
	return m_is_end;
}

void Player::SetIsEnd(bool is_end)
{
	is_end = m_is_end;
}

void Player::StartJump()
{
	if (m_can_jump == true)
	{
		m_speed.Y = 20.0f;
		m_can_jump = false;
	}
}

bool Player::HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1)
{
	//オブジェクトの距離
	int x = pos1.X - pos0.X;
	int y = pos1.Y - pos0.Y;

	//abs関数は絶対値を返す
	if (abs(x) < width0 / 2 + width1 / 2 && abs(y) < height0 / 2 + height1 / 2)
	{
		return true;
	}
	return false;
}