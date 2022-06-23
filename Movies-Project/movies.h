#ifndef MOVIES_H
#define MOVIES_H

#include<vector>
#include<string>
#include "movie.h"
using namespace std;

class Movies {
    vector<Movie> movieList;
    public:
    void insert(string movie_name, float __rating = -1.0, int __watched = -1);
    void display() const;
    void remove(string);
    void incrementWatchCount(string movie_name, int __incrementBy = 1);
};

#endif //MOVIES_H
