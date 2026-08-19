#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;

    Song(string t, string a)
        : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}

    // Add a song to the end of the playlist
    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);

        if (head == nullptr) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    // Move to the next song
    void nextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } else if (current->next == nullptr) {
            cout << "Already at the last song.\n";
        } else {
            current = current->next;
            displayCurrent();
        }
    }

    // Move to the previous song
    void previousSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
        } else if (current->prev == nullptr) {
            cout << "Already at the first song.\n";
        } else {
            current = current->prev;
            displayCurrent();
        }
    }

    // Display currently playing song
    void displayCurrent() {
        if (current)
            cout << "Now playing: " << current->title
                 << " - " << current->artist << "\n";
    }

    // Display playlist from beginning to end
    void displayForward() {
        Song* temp = head;

        cout << "\nPlaylist (Forward):\n";
        while (temp) {
            cout << temp->title << " - " << temp->artist << "\n";
            temp = temp->next;
        }
    }

    // Display playlist from end to beginning
    void displayBackward() {
        Song* temp = tail;

        cout << "\nPlaylist (Backward):\n";
        while (temp) {
            cout << temp->title << " - " << temp->artist << "\n";
            temp = temp->prev;
        }
    }

    ~Playlist() {
        Song* temp = head;

        while (temp) {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Blinding Lights", "The Weeknd");
    playlist.addSong("Shape of You", "Ed Sheeran");
    playlist.addSong("Believer", "Imagine Dragons");
    playlist.addSong("Perfect", "Ed Sheeran");

    playlist.displayForward();

    cout << "\n";
    playlist.displayCurrent();

    cout << "\nMoving forward:\n";
    playlist.nextSong();
    playlist.nextSong();

    cout << "\nMoving backward:\n";
    playlist.previousSong();
    playlist.previousSong();

    playlist.displayBackward();

    return 0;
}