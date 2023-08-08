#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class AssetManager {

    private:
        
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
        

    public:
        AssetManager();
        ~AssetManager(); 
        // Add functions to load and retrieve assets
        void LoadTexture(const std::string& name, const std::string& filename);
        sf::Texture& GetTexture(const std::string& name);

        void LoadFont(const std::string& name, const std::string& filename);
        sf::Font& GetFont(const std::string& name);

    
    
};