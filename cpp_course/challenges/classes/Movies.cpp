#include "Movies.h"
#include <iostream>

void Movies::display() {
    if (list_of_movies.empty()) {
        std::cout << "Sorry, no movies to display\n" << std::endl;
    } else {
        std::cout << "\n===================================" << std::endl;
        for (Movie &movie: list_of_movies) {
            std::cout << movie.get_movie_name() << ", "
            << movie.get_rating() << ", " 
            << movie.get_watched() << std::endl;
        }
        std::cout << "===================================\n" << std::endl;
    }
}

bool Movies::add_movie(std::string name, std::string rating, uint16_t watched) {
    for (Movie &movie: list_of_movies) {
        if (name == movie.get_movie_name()) {
            return false;
        }
    }
    Movie movie(name, rating, watched);
    list_of_movies.push_back(movie);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (Movie &movie: list_of_movies) {
        if (name == movie.get_movie_name()) {
            uint16_t incremented = movie.get_watched() + 1;
            movie.set_watched(incremented);
            return true;
        }
    }
    return false;
}