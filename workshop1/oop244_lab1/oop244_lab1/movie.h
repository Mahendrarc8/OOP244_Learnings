/*
Name: Mahendra Roka
ID: 143117232
Email: mroka1@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_

namespace seneca {

struct Movie {
	char m_title[128];
	int m_year;
	char m_rating[6];
	int m_duration;
	char m_genres[10][11];
	float m_consumerRating;
};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}

#endif 
