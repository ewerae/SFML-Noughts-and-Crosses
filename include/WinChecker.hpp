#pragma once

enum class SymbolState {
    Empty,
    X,
    O
};

class WinChecker {

    private:      
        const SymbolState (&grid)[3][3];

        bool CheckRows(SymbolState symbol) const;
        bool CheckColumns(SymbolState symbol) const;
        bool CheckDiagonals(SymbolState symbol) const;

    public:
        WinChecker(const SymbolState (&boardGrid)[3][3]);

        bool CheckWin(SymbolState symbol) const;
        bool CheckDraw() const;

};
