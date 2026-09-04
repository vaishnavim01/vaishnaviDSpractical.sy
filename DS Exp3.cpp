#include <iostream>
#include <string>

using namespace std;

// Node
struct Song
{
    string title;
    Song* prev;
    Song* next;

    Song(string t)
    {
        title = t;
        prev = NULL;
        next = NULL;
    }
};

// Playlist class
class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:

    // Constructor
    Playlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    // Add a song
    void addSong(string title)
    {
        Song* newSong = new Song(title);

        if (head == NULL)
        {
            head = newSong;
            tail = newSong;
            current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song added successfully!" << endl;
    }

    // Move to next song
    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->next == NULL)
        {
            cout << "Already at the last song." << endl;
        }
        else
        {
            current = current->next;
            cout << "Now playing: " << current->title << endl;
        }
    }

    // Move to previous song
    void previousSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->prev == NULL)
        {
            cout << "Already at the first song." << endl;
        }
        else
        {
            current = current->prev;
            cout << "Now playing: " << current->title << endl;
        }
    }

    // Display playlist forward
    void displayForward()
    {
        Song* temp = head;

        if (temp == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "\nPlaylist (Forward):" << endl;

        while (temp != NULL)
        {
            cout << temp->title << endl;
            temp = temp->next;
        }
    }

    // Display playlist backward
    void displayBackward()
    {
        Song* temp = tail;

        if (temp == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "\nPlaylist (Backward):" << endl;

        while (temp != NULL)
        {
            cout << temp->title << endl;
            temp = temp->prev;
        }
    }

    // Show current song
    void showCurrent()
    {
        if (current == NULL)
        {
            cout << "No song is currently playing." << endl;
        }
        else
        {
            cout << "Currently playing: "
                 << current->title << endl;
        }
    }

    // Destructor
    ~Playlist()
    {
        Song* temp = head;

        while (temp != NULL)
        {
            Song* nextSong = temp->next;
            delete temp;
            temp = nextSong;
        }
    }
};


int main()
{
    Playlist playlist;

    int choice;
    string songName;

    do
    {
        cout << "\n==============================" << endl;
        cout << "       MUSIC PLAYLIST" << endl;
        cout << "==============================" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Next Song" << endl;
        cout << "3. Previous Song" << endl;
        cout << "4. Display Playlist Forward" << endl;
        cout << "5. Display Playlist Backward" << endl;
        cout << "6. Show Current Song" << endl;
        cout << "7. Exit" << endl;
        cout << "==============================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cin.ignore();

                cout << "Enter song name: ";
                getline(cin, songName);

                playlist.addSong(songName);
                break;

            case 2:
                playlist.nextSong();
                break;

            case 3:
                playlist.previousSong();
                break;

            case 4:
                playlist.displayForward();
                break;

            case 5:
                playlist.displayBackward();
                break;

            case 6:
                playlist.showCurrent();
                break;

            case 7:
                cout << "Exiting playlist..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
