#include <cassert>
#include <string.h>
#include "domain.h"
#include "service.h"
#include "repository.h"
#include "tests.h"

void tests()
{
	Movie movies[5];

	char* title1 = new char[20];
	char* title2 = new char[20];
	char* title3 = new char[20];
	char* title4 = new char[20];
	char* title5 = new char[20];

	char* date1 = new char[20];
	char* date2 = new char[20];
	char* date3 = new char[20];
	char* date4 = new char[20];
	char* date5 = new char[20];

	char* gender1 = new char[20];
	char* gender2 = new char[20];
	char* gender3 = new char[20];
	char* gender4 = new char[20];
	char* gender5 = new char[20];

	//implicit constructor
	strcpy_s(title1, sizeof "Ted", "Ted");
	strcpy_s(date1, sizeof "12.05.2019", "12.05.2019");
	strcpy_s(gender1, sizeof "comedy", "comedy");
	Movie movie1;

	//general constructor
	strcpy_s(title2, sizeof "HarryPotter", "HarryPotter");
	strcpy_s(date2, sizeof "11.11.2011", "11.11.2011");
	strcpy_s(gender1, sizeof "sf", "sf");
	Movie movie2(title2, date2, gender2);

	strcpy_s(title3, sizeof "b", "b");
	strcpy_s(date3, sizeof "19.11.2018", "19.11.2018");
	strcpy_s(gender3, sizeof "b", "b");
	Movie movie3(title3, date3, gender3);

	strcpy_s(title4, sizeof "c", "c");
	strcpy_s(date4, sizeof "02.03.2020", "02.03.2020");
	strcpy_s(gender4, sizeof "documentary", "documentary");
	Movie movie4(title4, date4, gender4);

	strcpy_s(title5, sizeof "a", "a");
	strcpy_s(date5, sizeof "01.02.2020", "01.02.2020");
	strcpy_s(gender5, sizeof "y", "y");
	Movie movie5(title5, date5, gender5);

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;

	//getTitle
	assert(movie1.getTitle() == "Ted");
	assert(movie2.getTitle() == "HarryPotter");
	assert(movie3.getTitle() == "b");
	assert(movie4.getTitle() == "c");
	assert(movie5.getTitle() == "a");

	//getDate
	assert(movie1.getDate() == "12.05.2019");
	assert(movie2.getDate() == "11.11.2011");
	assert(movie3.getDate() == "19.11.2018");
	assert(movie4.getDate() == "02.03.2020");
	assert(movie5.getDate() == "01.02.2020");

	//getGender
	assert(movie1.getGenre() == "comedy");
	assert(movie2.getGenre() == "sf");
	assert(movie3.getGenre() == "b");
	assert(movie4.getGenre() == "documentary");
	assert(movie5.getGenre() == "y");

	//setTitle
	movie2.setTitle(movie3.getTitle());
	assert(movie2.getTitle() == movie3.getTitle());

	//setDate
	movie2.setDate(movie3.getDate());
	assert(movie2.getDate() == movie3.getDate());

	//setGender
	movie2.setGenre(movie3.getGenre());
	assert(movie2.getGenre() == movie3.getGenre());

	//operator
	movie4 = movie1;
	assert(movie4 == movie1);
}


void tests_with_repository()
{
	Movie movies[5];
	Repository repository;

	char* title1 = new char[20];
	char* title2 = new char[20];
	char* title3 = new char[20];
	char* title4 = new char[20];
	char* title5 = new char[20];

	char* date1 = new char[20];
	char* date2 = new char[20];
	char* date3 = new char[20];
	char* date4 = new char[20];
	char* date5 = new char[20];

	char* gender1 = new char[20];
	char* gender2 = new char[20];
	char* gender3 = new char[20];
	char* gender4 = new char[20];
	char* gender5 = new char[20];

	//implicit constructor
	strcpy_s(title1, sizeof "Bright", "Bright");
	strcpy_s(date1, sizeof "11.11.2019", "11.11.2019");
	strcpy_s(gender1, sizeof "thriller", "thriller");
	Movie movie1;

	//general constructor
	strcpy_s(title2, sizeof "Mute", "Mute");
	strcpy_s(date2, sizeof "11.11.2011", "11.11.2011");
	strcpy_s(gender1, sizeof "drame", "drame");
	Movie movie2(title2, date2, gender2);

	strcpy_s(title3, sizeof "Mank", "Mank");
	strcpy_s(date3, sizeof "09.11.2016", "09.11.2016");
	strcpy_s(gender3, sizeof "biographical", "biographical");
	Movie movie3(title3, date3, gender3);

	strcpy_s(title4, sizeof "Tig", "Tig");
	strcpy_s(date4, sizeof "02.03.2020", "02.03.2020");
	strcpy_s(gender4, sizeof "documentary", "documentary");
	Movie movie4(title4, date4, gender4);

	strcpy_s(title5, sizeof "Rebecca", "Rebecca");
	strcpy_s(date5, sizeof "01.02.2020", "01.02.2020");
	strcpy_s(gender5, sizeof "thriller", "thriller");
	Movie movie5(title5, date5, gender5);

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;

	//addMovie
	repository.addMovie(movie1);
	repository.addMovie(movie2);
	repository.addMovie(movie3);
	repository.addMovie(movie4);
	repository.addMovie(movie5);

	assert(movies[0] == movie1);
	assert(movies[1] == movie2);
	assert(movies[2] == movie3);
	assert(movies[3] == movie4);
	assert(movies[4] == movie5);

	//deleteMovie
	repository.deleteMovie(movie4);

	//updateMovie
	repository.updateMovie(movie2, movie3.getTitle(), movie1.getDate(), movie5.getGenre());
	assert(movie2.getTitle() == "Mank");
	assert(movie2.getDate() == "11.11.2019");
	assert(movie2.getGenre() == "thriller");


	//getAll
	assert(repository.getAll()[0] == movie1);
	assert(repository.getAll()[1] == movie2);
	assert(repository.getAll()[2] == movie3);
	assert(repository.getAll()[3] == movie5);
}

void tests_with_service()
{
	int m;
	Movie filter_movies[100];
	Movie movies[5];
	Repository repository;

	char* title1 = new char[20];
	char* title2 = new char[20];
	char* title3 = new char[20];
	char* title4 = new char[20];
	char* title5 = new char[20];

	char* date1 = new char[20];
	char* date2 = new char[20];
	char* date3 = new char[20];
	char* date4 = new char[20];
	char* date5 = new char[20];

	char* gender1 = new char[20];
	char* gender2 = new char[20];
	char* gender3 = new char[20];
	char* gender4 = new char[20];
	char* gender5 = new char[20];

	//implicit constructor
	strcpy_s(title1, sizeof "Bright", "Bright");
	strcpy_s(date1, sizeof "11.11.2019", "11.11.2019");
	strcpy_s(gender1, sizeof "thriller", "thriller");
	Movie movie1;

	//general constructor
	strcpy_s(title2, sizeof "Mute", "Mute");
	strcpy_s(date2, sizeof "11.11.2011", "11.11.2011");
	strcpy_s(gender1, sizeof "drame", "drame");
	Movie movie2(title2, date2, gender2);

	strcpy_s(title3, sizeof "Mank", "Mank");
	strcpy_s(date3, sizeof "09.11.2016", "09.11.2016");
	strcpy_s(gender3, sizeof "biographical", "biographical");
	Movie movie3(title3, date3, gender3);

	strcpy_s(title4, sizeof "Tig", "Tig");
	strcpy_s(date4, sizeof "02.03.2020", "02.03.2020");
	strcpy_s(gender4, sizeof "documentary", "documentary");
	Movie movie4(title4, date4, gender4);

	strcpy_s(title5, sizeof "Rebecca", "Rebecca");
	strcpy_s(date5, sizeof "01.02.2020", "01.02.2020");
	strcpy_s(gender5, sizeof "thriller", "thriller");
	Movie movie5(title5, date5, gender5);

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;


	//filter_movies_by_gender
	//filter_movies_by_genre(repository, movie5.getGenre(), filter_movies, m);
	

	//delete_movies_by_date
	//delete_movies_by_date(repository, movie5.getDate());
}
