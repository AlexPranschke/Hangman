// Game.cpp
#include "Game.h"

using namespace std;

Game::Game() {
    srand(time(0));  
    m_words = { "first", "random", "unreal", "engine", "game", "programming" };  // Lista s³ów
}

Game::~Game() {
   
}

void Game::RandPassword() {
    
    int temp = rand() % m_words.size();  // Losowy indeks z wektora
    m_password = m_words[temp];  
    m_pVector.assign(m_password.begin(), m_password.end());  // Przypisanie liter has³a do wektora
    m_hiddenSigns.assign(m_pVector.size(), false);
    m_guessCounter = m_hiddenSigns.size();
}

void Game::Interface() {
    char guess = '\0';
    
    cout << "Write a letter: ";

    // Sprawdzanie, czy input to litera
    while (guess < 'a' || guess > 'z') {
        
        cin >> guess;
        if (guess < 'a' || guess > 'z') {
            cout << "Invalid input. Please enter a small letter: ";
        }
    }

    // Sprawdzanie, czy litera by³a ju¿ u¿yta
    for (char it : m_usedSigns) {
        if (it == guess) {
            guess = '\0';  // Zresetowanie guess, jeœli litera ju¿ by³a u¿yta
            cout << " this letter was used \n";
            break;
        }
    }

    // Sprawdzanie, czy litera pasuje do has³a
    if (guess != '\0') {
        bool correct = false;
        for (int i = 0; i < m_pVector.size(); i++) {
            if (m_pVector[i] == guess) {
                m_hiddenSigns[i] = true;  // Odkrycie litery w haœle
                m_guessCounter--;
                if (m_guessCounter == 0) {
                    m_gameover = true;
                }
                correct = true;
                
                
            }
            
        }
        if (correct == false) m_wrongGuesses++;
        if (m_wrongGuesses >= 6) m_gameover = true;
        // Dodanie litery do listy u¿ytych liter
        m_usedSigns.push_back(guess);
    }
    
}

void Game::CheckEndGame(bool & isRunning, Game & game) {

    
    if (m_gameover == true) {
        cout << "Game Over\n";
        cout << "Start new Game? (y/n)";
            char answer = '\0';
        while (answer != 'y' && answer != 'n') {
            cin >> answer;
        }
        if (answer == 'y') {
            m_gameover  = false;
            m_wrongGuesses = 0;
            m_usedSigns.clear();
            system("CLS");
            game.RandPassword();
            game.DrawMap();
        }
        else {
            isRunning = false;
        }
    }
    



}

void Game::DrawMap() {
    // Rysowanie mapy w zale¿noœci od liczby b³êdów

    
    switch (m_wrongGuesses) {
    case 0:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 1:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 2:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |     | \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 3:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |     |\\ \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 4:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |    /|\\ \n";
        cout << " |       \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 5:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |    /|\\ \n";
        cout << " |    / \n";
        cout << " |       \n";
        cout << "_|_______\n";
        break;
    case 6:
        cout << " _______ \n";
        cout << " |     | \n";
        cout << " |     O \n";
        cout << " |    /|\\ \n";
        cout << " |    / \\ \n";
        cout << " |       \n";
        cout << "_|_______\n";
        cout << "  game over\n";
        break;
    default:
        cout << "error\n";
        break;
    }

    // Rysowanie ukrytych liter
    for (int i = 0; i < m_hiddenSigns.size(); i++) {
        if (m_hiddenSigns[i]) {
            cout << " " << m_pVector[i] << " ";  // Odkryte litery
        }
        else {
            cout << " _ ";  // Ukryte litery
        }
    }
    cout << endl;

    cout << "Used Signs: ";
    for (char it : m_usedSigns) {
        cout << " " << it;
   }
    
    cout << endl;

}
