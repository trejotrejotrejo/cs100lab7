#include "gtest/gtest.h"
#include <stdio.h>
#include <iostream>
#include "../tests/factory_test.hpp"
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
