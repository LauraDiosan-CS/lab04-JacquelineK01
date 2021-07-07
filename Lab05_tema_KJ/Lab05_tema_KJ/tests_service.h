#pragma once
#include "service.h"

class TestService
{
private:
	Service service;

	void tests_constructors();
	void test_addMovie();
	void test_updateMovie();
	void test_deleteMovie();
	void test_getAll();
	void test_filter_movies_by_genre();
	void test_delete_movies_by_date();
	void test_undo();
public:
	TestService();
	~TestService();

	void run_TestService();

};

