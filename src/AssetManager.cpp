#include "AssetManager.hpp"


AssetManager::AssetManager() {

}

AssetManager::~AssetManager() {

}

void AssetManager::LoadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
        textures[name] = texture;
    }
}

sf::Texture& AssetManager::GetTexture(const std::string& name) {
    return textures.at(name);
}

void AssetManager::LoadFont(const std::string& name, const std::string& filename) {
    sf::Font font;
    if (font.loadFromFile(filename)) {
        fonts[name] = font;
    }
}

sf::Font& AssetManager::GetFont(const std::string& name) {
    return fonts.at(name);
}