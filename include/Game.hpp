#pragma once
#include "AssetManager.hpp"
#include "WinChecker.hpp"
#include "Board.hpp"
#include "SymbolBase.hpp"




class Game {
    private:
        void Init();
        void ProcessEvents();
        void Update(sf::Time deltaTime);
        void Render();

        sf::RenderWindow window;
        bool isRunning;
        const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); 

        AssetManager assetManager;
        Board board;
        SymbolBase symbolBase;
        WinChecker winChecker;

        sf::Text fpsText;
        sf::Text mousePosText;
        sf::Text winText;
        sf::Text turnText;

    public:
        Game();
        ~Game();

        void Run();

    
};