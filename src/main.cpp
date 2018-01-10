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
    TextureManager::LoadTexture("Resources/paddle.png","paddle", false);
    TextureManager::LoadTexture("Resources/block.png","block", false);
    TextureManager::LoadTexture("Resources/ball.png","ball", false);
    TextureManager::LoadTexture("Resources/background.png","background",true);


    FontManager::LoadFont("Resources/Verdana.ttf", "Verdana");
    StateManager::PushState(new TestState());

    GameManager::UpdateGame();

    GameManager::FinalizeGame();
    return 0;
}
