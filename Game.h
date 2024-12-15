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

    void RandPassword();  // Funkcja losuj�ca has�o
    void Interface();  // Interfejs gry (przyjmowanie liter)
    void DrawMap();  // Funkcja rysuj�ca map� (hangman)
    void CheckEndGame(bool &, Game &);
private:
    std::vector<std::string> m_words;  // Lista s��w do wyboru
    std::vector<char> m_usedSigns;  // Wektor u�ytych liter
    std::vector<bool> m_hiddenSigns;  // Wektor oznaczaj�cy ukryte litery
    std::vector<char> m_pVector;  // Wektor liter has�a
    std::string m_password;  // Wylosowane has�o
    int m_guessCounter = 0;  // Licznik zgadywanych liter
    int m_wrongGuesses = 0;  // Liczba b��dnych pr�b
    bool m_gameover = false;
};

#endif
