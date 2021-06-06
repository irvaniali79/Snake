#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>

using namespace std;

void gotoxy(int x, int y)
{
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;

        SetConsoleCursorPosition(hConsole, pos);
    }
}

void Color(int number)
{
    HANDLE Color;
    Color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Color, number);
}

class Apple
{
private:
    int x;
    int y;
    int color;

public:
    Apple()
    {

        this->color = 10;
        this->x = rand() % 79 + 1;
        this->y = rand() % 23 + 2;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    void show()
    {
        gotoxy(this->x, this->y);
        Color(this->color);
        cout << "A";
    }
};

class Banana
{
private:
    int x;
    int y;
    int color;

public:
    Banana()
    {

        this->color = 6;
        this->x = rand() % 79 + 1;
        this->y = rand() % 23 + 2;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    void show()
    {
        gotoxy(this->x, this->y);
        Color(this->color);
        cout << "B";
    }
};

class Poison
{
private:
    int x;
    int y;
    int color;

public:
    Poison()
    {

        this->color = 12;
        this->x = rand() % 79 + 1;
        this->y = rand() % 23 + 2;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    void show()
    {
        gotoxy(this->x, this->y);
        Color(this->color);
        cout << "P";
    }
};

class Hedgehog
{
private:

    int x;
    int y;
    int color;

public:
    Hedgehog()
    {
        this->x = rand() % 79 + 1;
        this->y = rand() % 23 + 2;
        this->color = 7;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }

    void show()
    {
        gotoxy(this->x, this->y);
        Color(this->color);
        cout << "H";
    }

};


class Snake
{
private:
    int size;
    int speed;
    int x;
    int y;
    int color;
    int score;
    pair<int, int> myback;//x , y
    int lastmove;

public:
    Snake()
    {
        this->score = 0;
        this->size = 1;
        this->x = rand() % 79 + 1;
        this->y = rand() % 23 + 2;
        this->color = 9;
    }
    Snake(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->color = 9;
    }
    Snake(int x, int y, int lastmovement)
    {
        this->x = x;
        this->y = y;
        this->color = 9;
        this->lastmove = lastmovement;
        SetMyBack();
    }
    pair<int, int> getMyback()
    {
        return myback;
    }
    int getLastMove()
    {
        return lastmove;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
    int getScore()
    {
        return this->score;
    }

    void eatApple()
    {
        this->score++;
    }
    void eatBanana()
    {
        this->score += 2;

    }
    void eatPoison()
    {
        this->score--;
    }
    void move(int x, int y)
    {
        this->x += x;
        this->y += y;
        if (x > 0)lastmove = 4;
        else if (y > 0)lastmove = 1;
        else if (y < 0)lastmove = 3;
        else  lastmove = 2;
        this->lastmove = lastmove;
        SetMyBack();
    }
    void SetMyBack()
    {
        switch (this->lastmove)
        {
        case(1):
        {
            myback.first = this->x;
            myback.second = this->y - 1;
            break;
        }
        case(2):
        {
            myback.first = this->x + 1;
            myback.second = this->y;
            break;
        }
        case(3):
        {
            myback.first = this->x;
            myback.second = this->y + 1;
            break;
        }
        case(4):
        {
            myback.first = this->x - 1;
            myback.second = this->y;
            break;
        }
        default: {
            myback.first = this->x;
            myback.second = this->y - 1;
            break;
        }
        }

    }
    void show()
    {

        gotoxy(this->x, this->y);
        Color(this->color);
        cout << "*";
    }

};

void ShowWall()
{
    Color(15);
    gotoxy(0, 1);
    for (int i = 0; i < 80; i++)
        cout << "_";
    gotoxy(0, 25);
    for (int i = 0; i < 80; i++)
        cout << "_";
    for (int i = 2; i < 26; i++)
    {
        gotoxy(0, i);
        cout << "|";
    }
    for (int i = 2; i < 26; i++)
    {
        gotoxy(80, i);
        cout << "|";
    }
}

void ShowHelp()
{
    gotoxy(85, 0);
    Color(9);
    cout << "*";
    Color(15);
    cout << " : Snake ";
    gotoxy(85, 1);
    Color(15);
    cout << "H";
    Color(15);
    cout << " : Hedgehug ";
    gotoxy(85, 2);
    Color(10);
    cout << "A";
    Color(15);
    cout << " : Apple ( +1 score )";
    gotoxy(85, 3);
    Color(6);
    cout << "B";
    Color(15);
    cout << " : Banana ( +2 score ) ";
    gotoxy(85, 4);
    Color(12);
    cout << "P";
    Color(15);
    cout << " : Poison ( -1 score ) ";
    gotoxy(85, 7);
    Color(15);
    cout << "Win by :";
    gotoxy(85, 8);
    Color(15);
    cout << "Getting 20 points ";
    gotoxy(85, 9);
    cout << "lose by : ";
    gotoxy(85, 10);
    cout << "1-Hitting the walls ";
    gotoxy(85, 11);
    cout << "2-Eating the hedghog ";
    gotoxy(85, 12);
    cout << "3-Score being less than 0";
    gotoxy(85, 14);
    cout << "Moves : ";
    gotoxy(85, 15);
    cout << " 'w' = up " << "      " << "'s' = down";
    gotoxy(85, 16);
    cout << " 'a' = left " << "    " << "'d' = right";

}
int Menu()
{
    int i;
    system("cls");
    Color(15);
    gotoxy(0, 0);
    cout << "Choose an option : " << endl;
    cout << "1-Play a game " << endl;
    cout << "2-Exit" << endl;
    cin >> i;
    return i;
}

int main()
{
    srand(time(0));
    vector<Snake> snake;
    Snake head;
    snake.push_back(head);
    while (true)
    {
        switch (Menu())
        {
        case 1:
            break;
        case 2:
            return 0;
        }
        system("cls");
        char ch;
        ShowWall();
        ShowHelp();
        Hedgehog hedgehog;



        Apple* apple = new Apple();
        Banana* banana = new Banana();
        Poison* poison = new Poison();


        snake[0].show();
        hedgehog.show();
        banana->show();
        apple->show();
        poison->show();
        ch = _getch();

        while (true)
        {
            ch = _getch();
            switch (ch)
            {
            case 'w':
                snake[0].move(0, -1);
                break;
            case 's':
                snake[0].move(0, 1);
                break;
            case 'a':
                snake[0].move(-1, 0);
                break;
            case 'd':
                snake[0].move(1, 0);
                break;
            }
            for (int i = 1; i < snake.size(); i++)
            {
                snake[i].move(snake[i - 1].getMyback().first - snake[i].getX(), snake[i - 1].getMyback().second - snake[i].getY());
            }
            int flag = 0;
            for (int i = 1; i < snake.size(); i++)
            {
                if (snake[0].getX() == snake[i].getX() && snake[0].getY() == snake[i].getY())
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                system("cls");
                gotoxy(0, 0);
                Color(12);
                cout << "GAME OVER" << endl;
                cout << "YOU HIT THE YOUR SELF" << endl;
                cout << "BETTER LUCK NEXT TIME" << endl;
                break;
            }

            if (0 == snake[0].getX() || 80 == snake[0].getX() || 1 == snake[0].getY() || 25 == snake[0].getY())
            {

                system("cls");
                gotoxy(0, 0);
                Color(12);
                cout << "GAME OVER" << endl;
                cout << "YOU HIT THE WALL" << endl;
                cout << "BETTER LUCK NEXT TIME" << endl;
                Color(15);


                break;
            }
            if (hedgehog.getX() == snake[0].getX() && hedgehog.getY() == snake[0].getY())
            {

                system("cls");
                gotoxy(0, 0);
                Color(12);
                cout << "GAME OVER" << endl;
                cout << "YOU ATE THE HEDGEHOG" << endl;
                cout << "BETTER LUCK NEXT TIME" << endl;
                Color(15);


                break;
            }

            if (apple->getX() == snake[0].getX() && apple->getY() == snake[0].getY())
            {
                snake[0].eatApple();
                Snake temp(snake[snake.size() - 1].getMyback().first, snake[snake.size() - 1].getMyback().second);
                snake.push_back(temp);
                delete(apple);
                apple = new Apple();
            }
            if (banana->getX() == snake[0].getX() && banana->getY() == snake[0].getY())
            {
                snake[0].eatBanana();
                Snake temp(snake[snake.size() - 1].getMyback().first, snake[snake.size() - 1].getMyback().second, snake[snake.size() - 1].getLastMove());
                snake.push_back(temp);

                Snake temp1(snake[snake.size() - 1].getMyback().first, snake[snake.size() - 1].getMyback().second);
                snake.push_back(temp1);
                delete(banana);
                banana = new Banana();
            }
            if (poison->getX() == snake[0].getX() && poison->getY() == snake[0].getY())
            {
                snake[0].eatPoison();
                delete(poison);
                snake.pop_back();
                poison = new Poison();
            }

            if (snake[0].getScore() < 0)
            {
                system("cls");
                gotoxy(0, 0);
                Color(12);
                cout << "GAME OVER" << endl;
                cout << "YOUR ATE TOO MUCH POSION" << endl;
                cout << "BETTER LUCK NEXT TIME" << endl;
                Color(15);

                break;
            }
            if (snake[0].getScore() > 19)
            {
                system("cls");
                gotoxy(0, 0);
                Color(10);
                cout << "CONGRATULATIONS" << endl;
                cout << "YOU WIN" << endl;
                cout << "HOPE YOU HAD FUN !" << endl;
                Color(15);

                break;
            }
            system("cls");
            gotoxy(0, 0);
            Color(15);
            cout << "score :" << snake[0].getScore();
            cout << endl;
            for (int i = 0; i < snake.size(); i++)
                snake[i].show();
            hedgehog.show();
            apple->show();
            banana->show();
            poison->show();
            ShowWall();
            ShowHelp();
        }
        snake.clear();

        Snake head1;
        snake.push_back(head1);

        cout << endl;
        system("pause");
    }
}
