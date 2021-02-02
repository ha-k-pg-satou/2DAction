#include "Game.h"

static Player player;
static Slider slider;
Scroll scroll;
MapChip map_chip;

Game::Game()
{
	SceneStep = SceneStep::Init;
}

Game::~Game()
{

}

//SceneStepÇÃçXêV
void Game::Update()
{
	switch (SceneStep)
	{
	case SceneStep::Init:
		Init();
		break;
	case SceneStep::Run:
		Run();
		break;
	case SceneStep::Finish:
		Finish();
		break;
	default:
		break;
	}
}

void Game::Init()
{
	player.Init();
	slider.Init();

	SceneStep = SceneStep::Run;
}

void Game::Run()
{
	scroll.S_Update(player.P_Getter());
	player.P_Update();
	slider.S_Update();

	scroll.S_Draw();
	player.P_Draw();
	slider.S_Draw();
	map_chip.M_Draw();

	if (player.GetIsEnd() == true || slider.GetIsEnd() == true)
	{
		SceneStep = SceneStep::Finish;
	}
}

void Game::Finish()
{
	SceneStep = SceneStep::Init;
}