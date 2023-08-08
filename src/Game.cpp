#include "Game.hpp"


Game::Game() : window(sf::VideoMode(1000, 800), "SFML Game", sf::Style::Titlebar | sf::Style::Close), 
            isRunning(true), board(assetManager), symbolBase(assetManager), winChecker(board.GetGrid()) {
    Init();
}

Game::~Game() {
    
}


void Game::Init() {
    
    assetManager.LoadFont("font1", "assets/fonts/playfair/PlayfairDisplay-VariableFont_wght.ttf");
    
    fpsText.setFont(assetManager.GetFont("font1"));
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.0f, 10.0f);

    mousePosText.setFont(assetManager.GetFont("font1"));
    mousePosText.setCharacterSize(20);
    mousePosText.setFillColor(sf::Color::White);
    mousePosText.setPosition(10.f, 35.f);

    winText.setFont(assetManager.GetFont("font1"));
    winText.setCharacterSize(20);
    winText.setFillColor(sf::Color::White);
    winText.setPosition(10.f, 60.f);

    turnText.setFont(assetManager.GetFont("font1"));
    turnText.setCharacterSize(20);
    turnText.setFillColor(sf::Color::White);
    turnText.setPosition(10.f, 85.f);
    
}


void Game::Run() {
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    unsigned int frameCount = 0;
    

    while (isRunning) {
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        
        ProcessEvents();
        
        while (elapsedTime >= timePerFrame) {
            float fps = static_cast<float>(frameCount) / elapsedTime.asSeconds();
            fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::string mousePositionString = "(" + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y) + ")";
            mousePosText.setString(mousePositionString);
            frameCount = 0;
            frameCount++;

            elapsedTime -= timePerFrame;
            Update(timePerFrame);
            Render();
            
        }

        
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            isRunning = false;

        board.UpdateGrid(event, symbolBase.GetCrossHeldSpritePosition(), symbolBase.GetCircleHeldSpritePosition());
        symbolBase.HandleMouseInput(window, event, board.GetCrossTurn());
        
        
    }
    
}

void Game::Update(sf::Time deltaTime) {
    winText.setString("No winner");
    if(winChecker.CheckDraw()){
        winText.setString("Draw");
    }

    if(winChecker.CheckWin(SymbolState::X) ){
        winText.setString("X Winner");
    } else if (winChecker.CheckWin(SymbolState::O)){
        winText.setString("O Winner");
    }

    if(board.GetCrossTurn()){
        turnText.setString("X turn");
    } else {
        turnText.setString("O turn");
    }
}

void Game::Render() {
    window.clear();
    window.draw(fpsText);
    window.draw(mousePosText);
    window.draw(winText);
    window.draw(turnText);
    
    board.Draw(window, symbolBase.GetCrossHeldSpritePosition(), symbolBase.GetCircleHeldSpritePosition(), false);
    board.Draw(window, symbolBase.GetCrossHeldSpritePosition(), symbolBase.GetCircleHeldSpritePosition(), true);
    
    symbolBase.Draw(window);
    
    window.display();
}