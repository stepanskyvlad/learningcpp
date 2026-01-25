// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

enum class Choice {First, Last, Next, Prev, Add, Display, Quit, Unknown};

Choice parse_user_input(std::string &user_input) {
    if (user_input.empty())
        return Choice::Unknown;

    char c = static_cast<char>(
        std::tolower(static_cast<unsigned char>(user_input[0]))
    );

    switch (c) {
        case 'f': return Choice::First;
        case 'l': return Choice::Last;
        case 'n': return Choice::Next;
        case 'p': return Choice::Prev;
        case 'a': return Choice::Add;
        case 'd': return Choice::Display;
        case 'q': return Choice::Quit;
        default:  return Choice::Unknown;
    }
}

void display_menu() {
    std::cout << "\n=================== Menu ==========================" << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "L - Play Last Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "D - Display a list of the current playlist" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "\n=================== Playing now ===================" << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, std::list<Song>::iterator &it) {
    // This function should display the current playlist 
    // and then the current song playing.
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    std::cout << "\n================== Your playlist ==================" << std::endl; 
    for (auto &song: playlist) {
        std::cout << song << std::endl;
    }
    
    play_current_song(*it);
}

void first_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    it = playlist.begin();
    play_current_song(*it);
}

void last_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    it = std::prev(playlist.end());
    play_current_song(*it);
}

void next_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    it++;
    if (it == playlist.end()) {
        it = playlist.begin();
    }
    play_current_song(*it);
}

void prev_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    if (playlist.empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    if (it == playlist.begin()) {
        it = --playlist.end();
    } else {
        it--;
    }
    play_current_song(*it);
}

void add_new_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    std::string song_name;
    std::string artist_name;
    std::string str_rating;
    int rating;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nEnter a song name: ";
    std::getline(std::cin, song_name);
    std::cout << "Enter an artist name: ";
    std::getline(std::cin, artist_name);
    while (true) {
        std::cout << "Rate a song (1-5): ";
        std::cin >> str_rating;
        if (str_rating.size() == 1 && str_rating[0] >= '1' && str_rating[0] <= '5') {
            rating = str_rating[0] - '0';
            break;
        }
    }
    if (playlist.empty()) {
        playlist.emplace_back(song_name, artist_name, rating);
        it = playlist.begin();
    } else {
        playlist.emplace(it, song_name, artist_name, rating);
        --it;
    }
    play_current_song(*it);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    std::list<Song>::iterator current_song = playlist.begin();
    bool running = true;

    while (running) {
        display_menu();
        std::string user_input;
        std::cin >> user_input;
        Choice selection = parse_user_input(user_input);
        
        switch (selection) {
            case Choice::First:
                first_song(playlist, current_song);
                break;
            case Choice::Last:
                last_song(playlist, current_song);
                break;
            case Choice::Next:
                next_song(playlist, current_song);
                break;
            case Choice::Prev:
                prev_song(playlist, current_song);
                break;
            case Choice::Add:
                add_new_song(playlist, current_song);
                break;
            case Choice::Display:
                display_playlist(playlist, current_song);
                break;
            case Choice::Quit:
                std::cout << "Thanks for listening!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "\nInvalid input. Enter again." << std::endl;
        }
    }
    return 0;
}