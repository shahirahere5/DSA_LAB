#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void play(int pnum, int cplayer, int total)
{
    int guess;
    cout << " Player " << cplayer + 1 << " enter your guess(1-100): ";
    cin >> guess;
    if (guess == pnum)
    {
        cout << "Player guessed the correct number.. You win!\n";
        return;
    }
    else if (guess < pnum)
    {
        cout << "Too low!\n";
    }
    else{
        cout << "Too high!\n";
    }
    int nextplayer = (cplayer + 1) % total;
    play(pnum, nextplayer, total);
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    int pnum=1+rand()%100;
    int numPlayers;
    cout<<"Enter number of players: ";
    cin>>numPlayers;
    cout<<"Guess the number 1 and 100.\n";
    play(pnum, 0, numPlayers);
    return 0;
}