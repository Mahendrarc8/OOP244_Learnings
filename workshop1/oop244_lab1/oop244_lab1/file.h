/*
																			Workshop - 1

Name: Mahendra Roka
ID: 143117232
Email: mroka1@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);
}
#endif 
