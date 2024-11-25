#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

enum Color { RED, GREEN, BLUE, YELLOW, PURPLE };

Color generateRandomColor()
{
    int randomNum=rand() % 5;
    return static_cast<Color>(randomNum);
}

string colorToString(Color color)
{
    switch(color)
    {
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
        case PURPLE:
            return "Purple";
        default:
            return "Unknown";        
    }
} 

int main()
{
    srand(time(0));

    Color targetColor = generateRandomColor();

    string guess;
    const int MAX_GUESS_LENGTH = 20;
    
    while(true)
    {
        system("cls");
        cout<<"Welcome to the Color Game!"<<endl;
        cout<<"**************************"<<endl;
        cout<<"Guess the color from (Red, Green, Blue, Yellow, or Purple )"<<endl;
        cout<<"Enter your guess: ";
        cin>>guess;

        for (int i = 0 ; i < guess.length() && i < MAX_GUESS_LENGTH; i++)
        {
            guess[i]=tolower(guess[i]);
        }

        if(guess == "red" || guess == "green" || guess == "blue" || guess == "yellow" || guess == "purple")
        {
            Color userColor;
            
            if(guess == "red")
            userColor = RED;
            
            else if(guess == "green")
            userColor = GREEN;
            
            else if(guess == "blue")
            userColor = BLUE;
            
            else if(guess == "yellow")
            userColor = YELLOW;
            
            else if(guess == "purple")
            userColor = PURPLE;


            if(userColor ==targetColor)
            {
                cout<<endl;
                cout<<"Congratulations! You guessed the correct color. "<<endl;
                break;
            }
            else
            {
                cout<<"Wrong guess. Try again!"<<endl;
            }
        }
        
        else
        {
            cout<<"INVALID COLOR. Please try again and enter a valid color. "<<endl;
        }
        Sleep(1000);

    }

}
