#ifndef Game_H_
#define Game_H_

#include "Scroll.h"
#include "Slider.h"
#include "Player.h"
#include "MapChip.h"

enum SceneStep
{
	Init,
	Run,
	Finish,
};

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Init();
	void Run();
	void Finish();

	int SceneStep;
private:
	//Scroll scroll;
	//Slider slider;
	//Player player;
	//MapChip map_chip;
};

#endif
