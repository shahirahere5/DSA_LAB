#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    static const int MAX = 5;
    string songs[MAX];
    int front, rear;
    int count; 

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void addSong(string songName) {
        rear = (rear + 1) % MAX;
        songs[rear] = songName;

        if (count < MAX)
            count++;
        else
            front = (front + 1) % MAX; 

        cout << "Added: " << songName << endl;
        display();
    }

    void playNext() {
        if (isEmpty()) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        cout << "Playing: " << songs[front] << endl;
        front = (front + 1) % MAX;
        count--;
        display();
    }

    bool isEmpty() {
        return (count == 0);
    }

    void display() {
        if (isEmpty()) {
            cout << "Playlist is empty!" << endl << endl;
            return;
        }

        cout << "Current Playlist: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << songs[i] << "  ";
            i = (i + 1) % MAX;
        }
        cout << endl << endl;
    }
};

int main() {
    CircularQueue playlist;

    playlist.addSong("Pasoori");
    playlist.addSong("Bichhri");
    playlist.addSong("Afreen Afreen");
    playlist.addSong("Balaaj");
    playlist.addSong("Kahani Suno");

    playlist.playNext(); 
    playlist.addSong("Bella Ciao");

    playlist.playNext();
    playlist.addSong("Tu Hai Kahan");

    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext(); 

    return 0;
}
