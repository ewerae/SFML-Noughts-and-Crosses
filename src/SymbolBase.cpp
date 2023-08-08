#include "SymbolBase.hpp"

SymbolBase::SymbolBase(AssetManager& assetManager) : assetManager(assetManager), board(assetManager), isCrossHeld(false), isCircleHeld(false){
    assetManager.LoadTexture("cross held", "assets/sprites/cross held.png");
    assetManager.LoadTexture("circle held", "assets/sprites/circle held.png");

    crossBaseSprite.setTexture(assetManager.GetTexture("cross"));
    crossBaseSprite.setPosition(100.f, 200.f);

    circleBaseSprite.setTexture(assetManager.GetTexture("circle"));
    circleBaseSprite.setPosition(100.f, 370.f);


    crossHeldSprite.setTexture(assetManager.GetTexture("cross held"));
    crossHeldSprite.setPosition(100.f, 200.f);

    circleHeldSprite.setTexture(assetManager.GetTexture("circle held"));
    circleHeldSprite.setPosition(100.f, 370.f);

}

SymbolBase::~SymbolBase() {

}

bool SymbolBase::IsPixelTransparent(const sf::Sprite& sprite, const sf::Vector2f& position) const {

    sf::IntRect textureRect = sprite.getTextureRect();

    if (position.x < sprite.getPosition().x || position.x >= sprite.getPosition().x + textureRect.width ||
        position.y < sprite.getPosition().y || position.y >= sprite.getPosition().y + textureRect.height) {
        return false; // The position is outside the sprite's bounding box
    }

    int pixelX = static_cast<int>(position.x - sprite.getPosition().x);
    int pixelY = static_cast<int>(position.y - sprite.getPosition().y);

    // Retrieve the texture's pixel at the specified position
    sf::Color pixelColor = sprite.getTexture()->copyToImage().getPixel(pixelX + textureRect.left, pixelY + textureRect.top);
    // .getPixel gets its coords from the texture coordinate system not the global one
    return pixelColor.a > 0; // Check if the alpha value is greater than 0 (non-transparent)
}

void SymbolBase::HandleMouseInput(sf::RenderWindow& window, sf::Event& event, bool isCrossTurn) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        
        if (IsPixelTransparent(crossBaseSprite, mousePositionFloat) && isCrossTurn) {
            isCrossHeld = true;
            textureClickOffset = mousePositionFloat - crossHeldSprite.getPosition();
            
        }

        if (IsPixelTransparent(circleBaseSprite, mousePositionFloat) && !isCrossTurn) {
            isCircleHeld = true;
            textureClickOffset = mousePositionFloat - circleHeldSprite.getPosition();
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        isCrossHeld = false;
        crossHeldSprite.setPosition(100.f, 200.f);
        isCircleHeld = false;
        circleHeldSprite.setPosition(100.f, 370.f);
    }

    if (isCrossHeld) {
        
        crossHeldSprite.setPosition(mousePositionFloat - textureClickOffset + sf::Vector2f(0.f, -20.f));
    }

    if (isCircleHeld) {
       
        circleHeldSprite.setPosition(mousePositionFloat - textureClickOffset + sf::Vector2f(0.f, -20.f));
    }
}

sf::Vector2f SymbolBase::GetCrossHeldSpritePosition() const {
    return crossHeldSprite.getPosition();
}

sf::Vector2f SymbolBase::GetCircleHeldSpritePosition() const{ 
    return circleHeldSprite.getPosition();
}

void SymbolBase::Draw(sf::RenderWindow& window) const {
    if (!isCrossHeld) {
        window.draw(crossBaseSprite);
    } else {
        window.draw(crossHeldSprite);
    }
    
    if (!isCircleHeld) {
        window.draw(circleBaseSprite);
    } else {
        window.draw(circleHeldSprite);
    }
   
}
