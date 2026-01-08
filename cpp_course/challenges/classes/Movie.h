#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <cstdint>

class Movie
{
public:
    void set_movie_name(std::string t_movie_name);
    void set_rating(std::string t_rating);
    void set_watched(uint16_t t_watched);

    std::string get_movie_name() const;
    std::string get_rating() const;
    uint16_t get_watched() const;

    Movie(std::string movie_name, std::string rating, uint16_t watched);

private:
    std::string movie_name;
    std::string rating;
    uint16_t watched;

};

#endif