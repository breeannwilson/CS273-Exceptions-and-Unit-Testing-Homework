#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include <iostream>
#include "readint.h"
#include <stdexcept>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		
		TEST_METHOD(TestCase1)		//when input is not int
		{
			//open a file stream to read the file zeroinput.txt
			ifstream ss("C:\\Users\\breea\\OneDrive\\documents\\visual studio 2017\\Projects\\CS273 Exception Handling\\UnitTester\\zeroinput.txt");

			//check that the file stream was opened successfully
			if (ss.fail())
				throw int(-1);

			//replace the cin read buffer with the read buffer from the file stream
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			//perform the read_int() test
			//first will read "Hello", not valid but read_int will go through
			//the while loop and will have "0" inputed next, then will return
			//0
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			//restore cin to the way it was before
			cin.rdbuf(orig_cin);

			//close the file stream
			ss.close();

		}


		TEST_METHOD(TestCase2)		//for invalid argument
		{
			//define func
			auto func = []() {
				//call with incorrect arguments to test for invalid_argument
				read_int("My prompt: ", 5, 1);
			};

			//We expect an invalid_argument exception to be thrown when we call func
			Assert::ExpectException<std::invalid_argument>(func);
		}


		TEST_METHOD(TestCase3)		//to make sure read_int works when input is valid
		{
			//open a file stream to read the file testcase3.txt
			ifstream ss("C:\\Users\\breea\\OneDrive\\documents\\visual studio 2017\\Projects\\CS273 Exception Handling\\UnitTester\\testcase3.txt");

			//check that the file stream was opened successfully
			if (ss.fail())
				throw int(-1);

			//replace the cin read buffer with the read buffer from the file stream
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			//perform the read_int() test
			//test will pass if "3" is returned
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			//restore cin to the way it was before
			cin.rdbuf(orig_cin);

			//close the file stream
			ss.close();
		}


		TEST_METHOD(TestCase4)		//for invalid argument
		{
			//define func
			auto func = []() {
				//call with incorrect arguments to test for invalid_argument
				read_int("My prompt: ", 0, 0);
			};

			//We expect an invalid_argument exception to be thrown when we call func
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}