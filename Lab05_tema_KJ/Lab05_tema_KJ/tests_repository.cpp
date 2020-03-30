#include "tests_repository.h"
#include "repository.h"
#include <assert.h>

TestRepository::TestRepository()
{

}

TestRepository::~TestRepository()
{
	assert(repository.getSize() == 0);
}

void TestRepository::tests_constructors()
{
	Repository repository;
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

	char* genre1 = new char[20];
	char* genre2 = new char[20];
	char* genre3 = new char[20];
	char* genre4 = new char[20];
	char* genre5 = new char[20];

	//implicit constructor
	strcpy_s(title1, sizeof "a", "a");
	strcpy_s(date1, sizeof "11.11.2019", "11.11.2019");
	strcpy_s(genre1, sizeof "x", "x");
	Movie movie1;

	//general constructor
	strcpy_s(title2, sizeof "b", "b");
	strcpy_s(date2, sizeof "10.11.2010", "10.11.2010");
	strcpy_s(genre1, sizeof "y", "y");
	Movie movie2(title2, date2, genre2);

	strcpy_s(title3, sizeof "c", "c");
	strcpy_s(date3, sizeof "09.11.2013", "09.11.2013");
	strcpy_s(genre3, sizeof "z", "z");
	Movie movie3(title3, date3, genre3);

	strcpy_s(title4, sizeof "d", "d");
	strcpy_s(date4, sizeof "02.03.2010", "02.03.2010");
	strcpy_s(genre4, sizeof "t", "t");
	Movie movie4(title4, date4, genre4);

	strcpy_s(title5, sizeof "e", "e");
	strcpy_s(date5, sizeof "01.02.2020", "01.02.2020");
	strcpy_s(genre5, sizeof "f", "f");
	Movie movie5(title5, date5, genre5);

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;
}

void TestRepository::test_addMovie()
{
	Repository repository;
	Movie movies[5], movie1, movie2, movie3, movie4, movie5;

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;

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
}

void TestRepository::test_updateMovie()
{
	Repository repository;
	Movie movies[5], movie1, movie2, movie3, movie5;

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[4] = movie5;

	repository.updateMovie(movie2, movie3.getTitle(), movie1.getDate(), movie5.getGenre());

	assert(movie2.getTitle() == "b");
	assert(movie2.getDate() == "10.11.2010");
	assert(movie2.getGenre() == "y");
}

void TestRepository::test_deleteMovie()
{
	Repository repository;
	Movie movies[5], movie4;
	movies[3] = movie4;

	repository.deleteMovie(movie4);
}

void TestRepository::test_getAll()
{
	Repository repository;
	Movie movies[5], movie1, movie2, movie3, movie5;

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[4] = movie5;

	assert(repository.getAll()[0] == movie1);
	assert(repository.getAll()[1] == movie2);
	assert(repository.getAll()[2] == movie3);
	assert(repository.getAll()[3] == movie5);
}

void TestRepository::run_TestRepository()
{
	void tests_constructor();
	void test_addMovie();
	void test_updateMovie();
	void test_deleteMovie();
	void test_getAll();

}