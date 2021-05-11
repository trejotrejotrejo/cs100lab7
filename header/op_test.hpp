#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

  
#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "pow.hpp"
#include "rand.hpp"

//unit tests for op function
TEST(OpTest, OpEvaluateZero) {
      Op* test = new Op(0);
      EXPECT_EQ(test->evaluate(), 0);
 }
  
 TEST(OpTest, OpEvaluateFloatingPt) {
      Op* test = new Op(3.5);
      EXPECT_EQ(test->evaluate(), 3.5);
 }
  
  TEST(OpTest, OpEvaluateNeg) {
      Op* test = new Op(-24);
      EXPECT_EQ(test->evaluate(), -24);
  }
  
 TEST(OpTest, OpEvaluateLargeNum) {
     Op* test = new Op(68570450);
      EXPECT_EQ(test->evaluate(), 68570450);
  }
  
  TEST(OpTest, OpEvaluateStringify) {
      Op* test = new Op(28990);
      EXPECT_EQ(test->evaluate(), 28990);
  }

//unit tests for add function
 TEST(AddingTest, AddEvaluateZero) {
      Op* test1 = new Op(0);
      Op* test2 = new Op(0);
      Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), 0);
 }
  
  TEST(AddingTest, AddEvaluatePositiveVal) {
       Op* test1 = new Op(46);
       Op* test2 = new Op(92);
       Base* ad = new Add(test1, test2);
       EXPECT_EQ(ad->evaluate(), 138);
   }
  
  TEST(AddingTest, AddEvaluateNegativeVal) {
      Op* test1 = new Op(4);
      Op* test2 = new Op(-11);
      Base* ad = new Add(test1, test2);
      EXPECT_EQ(ad->evaluate(), -7);
 }
 
 TEST(AddingTest, AddEvaluateFloatingPt) {
      Op* test1 = new Op(7.19);
      Op* test2 = new Op(17.38);
      Base* ad = new Add(test1, test2);
      EXPECT_EQ(ad->evaluate(), 24.57);
 }
 
 TEST(AddingTest, AddEvaluateLargeNum) {
     Op* test1 = new Op(6180010);
     Op* test2 = new Op(4939823);
     Base* ad = new Add(test1, test2);
      EXPECT_EQ(ad->evaluate(), 11119833);
 }
 
 TEST(AddingTest, AddEvaluateStringify) {
     Op* test1 = new Op(7);
     Op* test2 = new Op(14);
     Base* ad = new Add(test1, test2);
     EXPECT_EQ(ad->stringify(), "7 + 14");
}

//unit tests for subtract function
TEST(SubtractTest, SubEvaluatePositive) {
      Op* test1 = new Op(9);
      Op* test2 = new Op(4);
      Base* subtraction = new Sub(test1, test2);
      EXPECT_EQ(subtraction->evaluate(), 5);
  }
  
 TEST(SubtractTest, SubEvaluateZero) {
       Op* test1 = new Op(0);
       Op* test2 = new Op(0);
       Base* subtraction = new Sub(test1, test2);
       EXPECT_EQ(subtraction->evaluate(), 0);
  }
  
 TEST(SubtractTest, SubEvaluateNegative) {
      Op* test1 = new Op(-5);
      Op* test2 = new Op(-3);
      Base* subtraction = new Sub(test1, test2);
      EXPECT_EQ(subtraction->evaluate(), -2);
 }
 
TEST(SubtractTest, SubLargeNumber) {
     Op* test1 = new Op(2006727);
     Op* test2 = new Op(8060612);
     Base* subtraction = new Sub(test1, test2);
    EXPECT_EQ(subtraction->evaluate(), -6053885);
 }
 
 TEST(SubtractTest, SubEvaluateFloatingPt) {
      Op* test1 = new Op(31.91);
      Op* test2 = new Op(5.45);
      Base* subtraction = new Sub(test1, test2);
      EXPECT_EQ(subtraction->evaluate(), 26.46);
  }
 
 TEST(SubtractTest, SubEvaluateStringify) {
     Op* test1 = new Op(44);
     Op* test2 = new Op(56);
     Base* subtraction = new Sub(test1, test2);
     EXPECT_EQ(subtraction->stringify(), "44 - 56");
 }

    //unit tests for power function
  TEST(PowerTest, PowEvaluateZero) {
    Op* test1 = new Op(14);
    Op* test2 = new Op(0);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->evaluate(), 0);
}

TEST(PowerTest, PowEvaluateNeg) {
    Op* test1 = new Op(-9);
    Op* test2 = new Op(3);
    Base* power = new Pow(test1, test2);
    EXPECT_EQ(power->evaluate(), -729);
}

 TEST(PowerTest, PowEvaluatePos) {
     Op* test1 = new Op(4);
     Op* test2 = new Op(3);
     Base* power = new Pow(test1, test2);
     EXPECT_EQ(power->evaluate(), 64);
 }
 
 TEST(PowerTest, PowFloatingPt) {
      Op* test1 = new Op(12.7);
      Op* test2 = new Op(5.4);
      Base* power = new Pow(test1, test2);
      EXPECT_FLOAT_EQ(power->evaluate(), 913145.7311);
 }
 
 TEST(PowerTest, PowStringify) {
      Op* test1 = new Op(20);
      Op* test2 = new Op(5);
      Base* power = new Pow(test1, test2);
      EXPECT_EQ(power->stringify(), "20 ^ 5");
}

//Unit tests for multiplication function
TEST(MultTest, MultEvaluateZero) {
    Op* test1 = new Op(0);
    Op* test2 = new Op(0);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->evaluate(), 0);
}

TEST(MultTest, MultEvaluatePositiveVal) {
    Op* test1 = new Op(12);
    Op* test2 = new Op(9);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->evaluate(), 108);
}

TEST(MultTest, MultEvaluateNegativeVal) {
    Op* test1 = new Op(-7);
    Op* test2 = new Op(8);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->evaluate(), -56);
}


TEST(MultTest, MultEvaluateFloatingPoint) {
    Op* test1 = new Op(12.5);
    Op* test2 = new Op(14.25);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->evaluate(), 178.125);
}

TEST(MultTest, MultEvaluateStringify) {
    Op* test1 = new Op(13);
    Op* test2 = new Op(14);
    Base* mul = new Mult(test1, test2);
    EXPECT_EQ(mul->stringify(), "13 * 14");
}

//Unit tests for division function
TEST(DivTest, DivEvaluateZero) {
    Op* test1 = new Op(0);
    Op* test2 = new Op(5);
    Base* divv = new Div(test1, test2);
    EXPECT_EQ(divv->evaluate(), 0);
}

TEST(DivTest, DivEvaluatePositiveVal) {
    Op* test1 = new Op(49);
    Op* test2 = new Op(7);
    Base* divv = new Div(test1, test2);
    EXPECT_EQ(divv->evaluate(), 7);
}

TEST(DivTest, DivEvaluateNegativeVal) {
    Op* test1 = new Op(-144);
    Op* test2 = new Op(4);
    Base* divv = new Div(test1, test2);
    EXPECT_EQ (divv->evaluate(), -36);
}

TEST(DivTest, DivEvaluateFloatingPoint) {
    Op* test1 = new Op(8.5);
    Op* test2 = new Op(2.5);
    Base* divv = new Div(test1, test2);
    EXPECT_EQ(divv->evaluate(), 3.4);
}

TEST(DivTest, DivEvaluateStringify) {
    Op* test1 = new Op(55);
    Op* test2 = new Op(11);
    Base* divv = new Div(test1, test2);
    EXPECT_EQ(divv->stringify(), "55 / 11");
} 

//unit tests for rand function
TEST(RandTest, RandEvaluate) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandEvaluateStringify) {
    Rand* test = new Rand();
    EXPECT_EQ(std::to_string(test->evaluate()), test->stringify());
}

 #endif //__OP_TEST_HPP__

