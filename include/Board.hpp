#pragma once

#include "AssetManager.hpp"
#include "WinChecker.hpp"


class Board {
    private:      
        AssetManager& assetManager;
        WinChecker winChecker;

        SymbolState grid[3][3];

        sf::Sprite xSprite;
        sf::Sprite oSprite;

        sf::Sprite xSpritePotentialPlacement;
        sf::Sprite oSpritePotentialPlacement;

        sf::Sprite boardSprite;

        bool isCrossTurn;

    public:
        Board(AssetManager& assetManager);
        ~Board();

        bool RandomTurn();

        void UpdateGrid(sf::Event& event, const sf::Vector2f& crossPosition, const sf::Vector2f& circlePosition);
        void DrawPlacement(sf::RenderWindow& window,const sf::Vector2f& crossPosition, const sf::Vector2f& circlePosition);
        void Draw(sf::RenderWindow& window, const sf::Vector2f& crossPosition, const sf::Vector2f& circlePosition, bool drawPotentialPlacement);

        bool GetCrossTurn(){ return isCrossTurn; }
        
        const SymbolState (&GetGrid())[3][3] { return grid; }
        
};