#include <random>

#include "Board.hpp"

Board::Board(AssetManager& assetManager) : assetManager(assetManager), winChecker(grid), isCrossTurn(RandomTurn()) {
    
    assetManager.LoadTexture("board", "assets/sprites/board.png");
    boardSprite.setTexture(assetManager.GetTexture("board"));
    boardSprite.setPosition(300.f, 100.f);

    assetManager.LoadTexture("cross", "assets/sprites/cross.png");
    assetManager.LoadTexture("circle", "assets/sprites/circle.png");
    
    xSprite.setTexture(assetManager.GetTexture("cross"));
    oSprite.setTexture(assetManager.GetTexture("circle"));

    xSpritePotentialPlacement.setTexture(assetManager.GetTexture("cross"));
    oSpritePotentialPlacement.setTexture(assetManager.GetTexture("circle"));

    sf::Color spriteCrossColour = xSpritePotentialPlacement.getColor();
    spriteCrossColour.a =128;
    xSpritePotentialPlacement.setColor(spriteCrossColour);

    sf::Color spriteCircleColour = oSpritePotentialPlacement.getColor();
    spriteCircleColour.a =128;
    oSpritePotentialPlacement.setColor(spriteCircleColour);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = SymbolState::Empty;
        }
    }
    
}

Board::~Board() {
}


bool Board::RandomTurn() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    return dis(gen) == 1; 
}

void Board::UpdateGrid(sf::Event& event, const sf::Vector2f& crossPosition, const sf::Vector2f& circlePosition){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            if (crossPosition.x + 75.f >= 332.f + i * 185.f && crossPosition.x + 75.f  < 332.f + (i + 1) * 185.f &&
                crossPosition.y + 75.f >= 132.f + j * 185.f && crossPosition.y + 75.f < 132.f + (j + 1) * 185.f && 
                grid[i][j] == SymbolState::Empty && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {

                grid[i][j] = SymbolState::X;
                isCrossTurn = false;
            }
            
            if (circlePosition.x + 75.f >= 332.f + i * 185.f && circlePosition.x + 75.f< 332.f + (i + 1) * 185.f &&
                circlePosition.y + 75.f >= 132.f + j * 185.f && circlePosition.y + 75.f < 132.f + (j + 1) * 185.f && 
                grid[i][j] == SymbolState::Empty && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {

                grid[i][j] = SymbolState::O;
                isCrossTurn = true;
            }
        }
    }
}

void Board::Draw(sf::RenderWindow& window, const sf::Vector2f& crossPosition, const sf::Vector2f& circlePosition, bool drawPotentialPlacement) {
    window.draw(boardSprite);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == SymbolState::X) {
                xSprite.setPosition(340.f + i * 185.f, 140.f + j * 185.f);
                window.draw(xSprite);
            } else if (grid[i][j] == SymbolState::O) {
                oSprite.setPosition(340.f + i * 185.f, 140.f + j * 185.f);
                window.draw(oSprite);
            } else if (drawPotentialPlacement) {
                if (crossPosition.x + 75.f >= 332.f + i * 185.f && crossPosition.x + 75.f < 332.f + (i + 1) * 185.f &&
                    crossPosition.y + 75.f >= 132.f + j * 185.f && crossPosition.y + 75.f < 132.f + (j + 1) * 185.f) {

                    xSpritePotentialPlacement.setPosition(340.f + i * 185.f, 140.f + j * 185.f);
                    window.draw(xSpritePotentialPlacement);
                }
                if (circlePosition.x + 75.f >= 332.f + i * 185.f && circlePosition.x + 75.f < 332.f + (i + 1) * 185.f &&
                    circlePosition.y + 75.f >= 132.f + j * 185.f && circlePosition.y + 75.f < 132.f + (j + 1) * 185.f) {

                    oSpritePotentialPlacement.setPosition(340.f + i * 185.f, 140.f + j * 185.f);
                    window.draw(oSpritePotentialPlacement);
                }
            }
        }
    }
}