#include "WinChecker.hpp"

bool WinChecker::CheckRows(SymbolState symbol) const {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol ){
            return true;
        }
    }
    return false;

}

bool WinChecker::CheckColumns(SymbolState symbol) const {
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol ){
            return true;
        }
    }
    return false;


}
bool WinChecker::CheckDiagonals(SymbolState symbol) const {
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true; 
    }
    if (grid[2][1] == symbol && grid[1][1] == symbol && grid[1][2] == symbol) {
        return true; 
    }
    return false;
    

}

bool WinChecker::CheckWin(SymbolState symbol) const {
    return CheckRows(symbol) || CheckColumns(symbol) || CheckDiagonals(symbol);


}

bool WinChecker::CheckDraw() const{
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == SymbolState::Empty){
                return false;
            }
        }
    }
    return true;

}