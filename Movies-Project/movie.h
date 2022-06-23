#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include<string>
using namespace std;

class Movie {
    string _name;
    float _rating;
    int _watchCount;
    public:
    // Movie(string);
    Movie(string _name, float _rating = -1, int _watchCount = -1); // 
    void _increment_watch_count(int _incrementBy = 1);
    bool operator==(Movie&);
    friend ostream& operator<<(ostream&, const Movie&);
};

#endif // MOVIE_H
