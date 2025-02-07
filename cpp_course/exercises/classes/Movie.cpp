#include "Movie.h"
#include <iostream>

struct Ratings
{
    std::string g {"G"};
    std::string pg {"PG"};
    std::string pg_13 {"PG-13"};
    std::string r {"R"};
};

//Constructor
Movie::Movie(std::string t_movie_name, std::string t_rating,  uint16_t t_watched)
    : movie_name{t_movie_name}, rating{t_rating}, watched{t_watched}
{

}

void Movie::set_movie_name(std::string t_movie_name) {
    movie_name = t_movie_name;
}

std::string Movie::get_movie_name() const {
    return movie_name;
}

void Movie::set_rating(std::string t_rating) {
    Ratings ratings;
    if ((t_rating != ratings.g) &&
    (t_rating != ratings.pg) &&
    (t_rating != ratings.pg_13) &&
    (t_rating != ratings.r)) {
        std::cout << "Available ratings: " 
        << ratings.g << " " 
        << ratings.pg << " "
        << ratings.pg_13 << " "
        << ratings.r << " "
        << std::endl;
    } else {
        rating = t_rating;
    }
}

std::string Movie::get_rating() const {
    return rating;
}

void Movie::set_watched(uint16_t t_watched) {
        watched = t_watched;
}

uint16_t Movie::get_watched() const {
    return watched;
}
