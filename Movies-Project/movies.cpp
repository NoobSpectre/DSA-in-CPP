#include<iostream>
#include<string>
#include "movie.h"
#include "movies.h"
using namespace std;

// void Movies::insert(string movie_name);
// insert();
// movies.cpp -> []
void Movies::insert(string movie_name, float __rating, int __watched) {
    Movie _movie(movie_name, __rating, __watched);

    for(Movie& __movie: movieList) {
        if(__movie == _movie) {
            cout << "This movie has been already added in your movie's list!!!";
            return;
        }
    }

    movieList.push_back(_movie);
}

void Movies::display() const {
    int i=1;
    for(const Movie& __movie: movieList) {
        std::cout << i++ << ") " << __movie << std::endl;
    }
    cout << "==========================\n" << endl;
}

void Movies::remove(string movie_name) {
    int i, n = movieList.size();
    Movie _movie(movie_name); // error

    for(i=0; i<n; i++) {
        if(movieList[i] == _movie) break;
    }

    if(i >= n)
        cout << "\"" << movie_name << "\" movie is not in your movie's list!!!" << endl;
    else
        movieList.erase(movieList.begin()+i,movieList.begin()+i+1);
}

void Movies::incrementWatchCount(string movie_name, int __incrementBy) {
    Movie _movie(movie_name);
    int i, n = movieList.size();

    for(i=0; i<n; i++) {
        if(movieList[i] == _movie) {
            movieList[i]._increment_watch_count(__incrementBy);
            break;
        }
    }

    if(i >= n) {
        cout << "\"" << movie_name << "\" movie is not in your movie's list!!!" << endl;
        cout << "Do you want to add this movie to your movie's list (Y/N)?";
        char ch; cin >> ch;
        if(ch == 'y' || ch == 'Y')
            movieList.push_back(_movie);
    }
}