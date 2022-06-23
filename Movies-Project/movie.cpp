#include<iostream>
#include<string>
#include "movie.h"
using namespace std;

// Movie::Movie(string _name)
//     : _name{_name}, _rating{-1}, _watchCount{-1} {}

Movie::Movie(string _name, float _rating, int _watchCount)
    : _name{_name}, _rating{_rating}, _watchCount{_watchCount} {}

void Movie:: _increment_watch_count(int _incrementBy) {
    if(_watchCount >=0)
        _watchCount += _incrementBy;
}

bool Movie::operator==(Movie& _movie) {
    return (_name == _movie._name);
}

ostream& operator<<(ostream& output, const Movie& _movie) {
    output << "Movie: " << _movie._name << endl;

    if(_movie._rating >= 0)
        output << "   Rating: " << _movie._rating << endl;

    if(_movie._watchCount >= 0)
        output << "   Watch count: " << _movie._watchCount << endl;

    return output;
}