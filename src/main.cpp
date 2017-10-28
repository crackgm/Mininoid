#include <SFML/Graphics.hpp>
#include "Code/Managers/GameManager.h"
#include "Code/Managers/StateManager.h"
#include "Code/Managers/TextureManager.h"
#include "Code/TestState.h"
#include <ctime>

int main()
{
	srand(time(NULL));
    GameManager::InitializeGame();
    TextureManager::LoadTexture("Resources/texPaddle.png","paddle");
    TextureManager::LoadTexture("Resources/texBlock.png","block");
    TextureManager::LoadTexture("Resources/texBall.png","ball");


    FontManager::LoadFont("Verdana.ttf", "Verdana");
    StateManager::PushState(new TestState());

    GameManager::UpdateGame();

    return 0;
}
