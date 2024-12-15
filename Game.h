// Game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // dla rand i srand
#include <ctime>    // dla time

class Game {
public:
    Game();  // Konstruktor
    ~Game(); // Destruktor

    void RandPassword();  // Funkcja losuj¹ca has³o
    void Interface();  // Interfejs gry (przyjmowanie liter)
    void DrawMap();  // Funkcja rysuj¹ca mapê (hangman)
    void CheckEndGame(bool &, Game &);
private:
    std::vector<std::string> m_words;  // Lista s³ów do wyboru
    std::vector<char> m_usedSigns;  // Wektor u¿ytych liter
    std::vector<bool> m_hiddenSigns;  // Wektor oznaczaj¹cy ukryte litery
    std::vector<char> m_pVector;  // Wektor liter has³a
    std::string m_password;  // Wylosowane has³o
    int m_guessCounter = 0;  // Licznik zgadywanych liter
    int m_wrongGuesses = 0;  // Liczba b³êdnych prób
    bool m_gameover = false;
};

#endif
