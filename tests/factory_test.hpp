
#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "../header/base.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/pow.hpp"
#include "../header/op.hpp"
#include "../header/factory.hpp"
using namespace std;

TEST(Factory, normalAdd) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "20";
        test_val[2] = "+";
        test_val[3] = "10";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("20 + 10", calc->stringify());
        EXPECT_EQ(30, calc->evaluate());

        delete factory;
	delete calc;
}

TEST(Factory, normalSub) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "29";
        test_val[2] = "-";
        test_val[3] = "14";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("29 - 14", calc->stringify());
        EXPECT_EQ(15, calc->evaluate());
	
	delete factory;
	delete calc;
}

TEST(Factory, negativeSub) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "6";
        test_val[2] = "-";
        test_val[3] = "16";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("6 - 16", calc->stringify());
        EXPECT_EQ(-10, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, normalMult) {
	Factory* factory = new Factory();

	char* test_val[4]; 
	test_val[0] = "./calculator"; 
	test_val[1] = "20"; 
	test_val[2] = "*";
	test_val[3] = "10";

	Base* calc = factory->parse(test_val, 4);

	EXPECT_EQ("20 * 10", calc->stringify());
	EXPECT_EQ(200, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, zeroMult) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "0";
        test_val[2] = "*";
        test_val[3] = "2";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("0 * 2", calc->stringify());
        EXPECT_EQ(0, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, normalDiv) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "15";
        test_val[2] = "/";
        test_val[3] = "3";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("15 / 3", calc->stringify());
        EXPECT_EQ(5, calc->evaluate());

	delete factory;
	delete calc;
}


TEST(Factory, zeroDiv) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "0";
        test_val[2] = "/";
        test_val[3] = "8";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("0 / 8", calc->stringify());
        EXPECT_EQ(0, calc->evaluate());

	delete factory;
	delete calc;
}


TEST(Factory, normalPow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "2";
        test_val[2] = "**";
        test_val[3] = "4";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("2 ** 4", calc->stringify());
        EXPECT_EQ(16, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, zeroPow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "3";
        test_val[2] = "**";
        test_val[3] = "0";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("3 ** 0", calc->stringify());
        EXPECT_EQ(1, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, onePow) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "9";
        test_val[2] = "**";
        test_val[3] = "1";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ("9 ** 1", calc->stringify());
        EXPECT_EQ(9, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, MultipleOperations) {
        Factory* factory = new Factory();

        char* test_val[12];
        test_val[0] = "./calculator";
        test_val[1] = "4";
        test_val[2] = "*";
        test_val[3] = "3";
        test_val[4] = "+";
        test_val[5] = "8";
        test_val[6] = "/";
        test_val[7] = "2";
        test_val[8] = "**";
        test_val[9] = "2";
        test_val[10] = "-";
        test_val[11] = "50";

        Base* calc = factory->parse(test_val, 12);

        EXPECT_EQ("4 * 3 + 8 / 2 ** 2 - 50", calc->stringify());
        EXPECT_EQ(50, calc->evaluate());

	delete factory;
	delete calc;
}

TEST(Factory, invalidInput) {
        Factory* factory = new Factory();

        char* test_val[4];
        test_val[0] = "./calculator";
        test_val[1] = "+";
        test_val[2] = "**";
        test_val[3] = "6";

        Base* calc = factory->parse(test_val, 4);

        EXPECT_EQ(nullptr, calc);

	delete factory;
	delete calc;
}

TEST(Factory, invalidNegativeInput) {
	Factory* factory = new Factory();
	char* test_val[4];
	test_val[0] = "./calculator";
	test_val[1] = "-9";
	test_val[2] = "^";
	test_val[3] = "8";

	Base* calc = factory->parse(test_val, 4);
	EXPECT_EQ(nullptr, calc);
}

#endif //__FACTORY_TEST_HPP__
