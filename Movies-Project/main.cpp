#include<iostream>
// #include "movies.h"
#include "movies.cpp"
// #include "movie.h"
#include "movie.cpp"
using namespace std;

int main() {
    Movies myMovies;

    myMovies.insert("Sholay", 4.5, 6);
    myMovies.insert("KGF", 5, 8);
    myMovies.insert("Pushpa", 3.5);
    myMovies.insert("Avengers Endgame", 5, 3);

    myMovies.display();

    myMovies.remove("Pushpa");
    myMovies.remove("Dhamaal");

    myMovies.display();
    myMovies.insert("Pushpa", 3.5);

    myMovies.incrementWatchCount("Avengers Endgame");
    myMovies.incrementWatchCount("KGF", 2);
    myMovies.incrementWatchCount("XXX", 3);

    myMovies.display();
    
    return 0;
}