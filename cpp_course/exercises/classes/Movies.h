#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include "Movie.h"

class Movies
{
public:
    bool increment_watched(std::string name);
    bool add_movie(std::string name, std::string rating, uint16_t watched);
    void display();

private:
    std::vector<Movie> list_of_movies;

};

#endif