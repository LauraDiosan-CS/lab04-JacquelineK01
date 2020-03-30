#include <iostream>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "user_interface.h"
#include "tests_domain.h"
#include "tests_repository.h"
#include "tests_service.h"

using namespace std;

int main()
{
	TestDomain testDomain;
	testDomain.run_TestDomain();

	TestRepository testRepository;
	testRepository.run_TestRepository();

	TestService testService;
	testService.run_TestService();

	UserInterface userInterface;
	userInterface.run();

	return 0;
}