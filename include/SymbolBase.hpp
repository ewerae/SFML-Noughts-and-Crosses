#pragma once


#include "SymbolBase.hpp"
#include "AssetManager.hpp"
#include "WinChecker.hpp"
#include "Board.hpp"

class SymbolBase {
    private:
        AssetManager& assetManager;
        Board board;

        sf::Sprite crossBaseSprite;
        sf::Sprite circleBaseSprite;
        sf::Sprite crossHeldSprite;
        sf::Sprite circleHeldSprite;

        bool isCrossHeld;
        bool isCircleHeld;

        sf::Vector2f position;
        sf::Vector2f textureClickOffset;
        
    public:

        SymbolBase(AssetManager& assetManager);
        ~SymbolBase();

        void Draw(sf::RenderWindow& window) const;
        bool IsPixelTransparent(const sf::Sprite& sprite, const sf::Vector2f& position) const;
        void HandleMouseInput(sf::RenderWindow& window, sf::Event& event, bool isCrossTurn);

        sf::Vector2f GetCrossHeldSpritePosition() const;
        sf::Vector2f GetCircleHeldSpritePosition() const;
       
        

};