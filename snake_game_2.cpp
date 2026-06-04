// snake_game_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

const int ROWS = 25;
const int COLS = 25;

//srand(time(0));
int foodRow, foodCol;
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
Direction dir;

void clearBoard(vector<vector<int>>& Board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (Board[i][j] != 2) Board[i][j] = 0;
        }
    }
}
//void drawBoard(vector<vector<int>>& Board) {
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            cout << Board[i][j] << "  ";
//        }
//        cout << endl;
//        cout << endl;
//    }
//}


void generateFood(vector<vector<int>>& Board) {
    
    while (true) {
        foodRow = rand() % ROWS;
        foodCol = rand() % COLS;

        if (Board[foodRow][foodCol] == 0) {
            Board[foodRow][foodCol] = 2;
            break;
        }
    }
}
int main()
{


    vector<vector<int>> Board(ROWS, vector<int>(COLS, 0));

    vector<pair<int, int>> snake =
    {
        {5,3},
        {5,4},
        {5,5}
    };

    for (auto segment : snake) {
        Board[segment.first][segment.second] = 1;
    }

    generateFood(Board);
    //drawBoard(Board);
    /*while (true) {
        clearBoard(Board);
        bool foodEaten = false;
        char move;
        cin >> move;
        if (move == 'w') dir = UP;
        else if (move == 's') dir = DOWN;
        else if (move == 'a') dir = LEFT;
        else if (move == 'd') dir = RIGHT;

        int newRow = snake.back().first;
        int newCol = snake.back().second;

        switch (dir)
        {
        case UP: newRow--;
            break;
        case DOWN: newRow++;
            break;
        case LEFT: newCol--;
            break;
        case RIGHT: newCol++;
            break;
        default:
            break;
        }
        if (newRow < 0 || newRow > ROWS || newCol < 0 || newCol > COLS) {
            cout << "Game Over !" << endl;
            break;
        }
        if (Board[newRow][newCol] != 2) {
            snake.push_back({ newRow , newCol });
            snake.erase(snake.begin());
        }
        else {
            snake.push_back({ newRow , newCol });
            generateFood(Board);
        }

        for (auto segment : snake) {
            Board[segment.first][segment.second] = 1;
        }

        drawBoard(Board);
    }*/
    sf::RenderWindow window(sf::VideoMode({ 800 , 600 }), "Snake");
    sf::Clock clock;

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        

        window.clear();
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                sf::RectangleShape cell(sf::Vector2f(30.f, 30.f));
                cell.setPosition(sf::Vector2f(col*30.f, row*30.f));

                if (Board[row][col] == 1) {
                    cell.setFillColor(sf::Color::Red);
                }
                else if (Board[row][col] == 2) {
                    cell.setFillColor(sf::Color::Green);
                }
                else cell.setFillColor(sf::Color::Black);
                window.draw(cell);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && dir != DOWN){
            dir = UP;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && dir != UP) {
            dir = DOWN;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && dir != RIGHT) {
            dir = LEFT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && dir != LEFT) {
            dir = RIGHT;
        }

        if (clock.getElapsedTime().asSeconds() > 0.2f) {
            int newRow = snake.back().first;
            int newCol = snake.back().second;

            switch (dir)
            {
            case UP: newRow--;
                break;
            case DOWN: newRow++;
                break;
            case LEFT: newCol--;
                break;
            case RIGHT: newCol++;
                break;
            default:
                break;
            }

            if (newRow < 0 || newRow >= ROWS ||
                newCol < 0 || newCol >= COLS)
            {
                cout << "GAME OVER\n";
                break;
            }
            snake.push_back({ newRow, newCol });
            snake.erase(snake.begin());
            
            
            clock.restart();
        }
        clearBoard(Board);

        for (auto segment : snake)
        {
            Board[segment.first][segment.second] = 1;
        }
        Board[foodRow][foodCol] = 2;

        
        
        
        
        window.display();
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
