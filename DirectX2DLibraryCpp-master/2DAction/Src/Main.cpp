#define _CRTDBG_MAP_ALLOC
#define Map_Height 8
#define Map_Width 20

#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>
#include "Engine/Engine.h"
#include "Common/Vec.h"
#include "../Game.h"

// ゲーム処理
void GameProcessing();
// 描画処理
void DrawProcessing();


/*
	エントリポイント
*/
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmpLine,
	_In_ INT       nCmdShow)
{
	// エンジンの初期化
	// ゲームループ開始前に1度だけ実行する
	if (Engine::Initialize(640, 480, "Sample") == false)
	{
		return 0;
	}

	// テクスチャ読み込み
	// 第一引数の文字列で読み込んだテクスチャを登録する
	// 描画や取得は登録した文字列で指定する
	Engine::LoadTexture("Enemy", "Res/Enemy.png");
	Engine::LoadTexture("Bg", "Res/BackGround.png");
	Engine::LoadTexture("MapChip", "Res/MapChip.png");

	Game game;

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Engine::StartDrawing(0);

			game.Update();

			Engine::FinishDrawing();
		}
	}

	// エンジン終了
	// ゲームループ終了後に1度だけ実行する
	// テクスチャとサウンドファイルも全て解放する
	Engine::Release();

	// メモリリーク検出
	_CrtDumpMemoryLeaks();

	return 0;

} // プログラム終了


