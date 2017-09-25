/**
 *  @file      pidTest.cpp
 *  @brief     Unit tests
 *  @details   This file is used to run all unit tests for the PID class
 *  @author    Rishabh Biyani (rishabh1b)
 *  @copyright GNU Public License.
 */

#include <gtest/gtest.h>
#include <memory>
#include "Pid.h"


/**
 * @brief Test computation of the output velocity
 */
TEST(PIDTest, testCompute) {
  std::shared_ptr<Pid> pid = std::make_shared < Pid > (0.1, 0.001, 0.03, 1);
  pid->setReference(5);
  double currentvelocity = pid->compute(1);
  EXPECT_EQ(0.1, currentvelocity);
  EXPECT_EQ(0.2, pid->compute(currentvelocity));

  pid->setReference(4);
  // double currentvelocity = pid->compute(1);
  EXPECT_EQ(0.1, currentvelocity);
  EXPECT_EQ(0.2, pid->compute(currentvelocity));
}

/**
 * @brief Test initialization of gains and the get functions
 */
TEST(PIDTest, testGainInitialization) {
  std::shared_ptr<Pid> pid = std::make_shared < Pid > (0.1, 0.01, 0.5, 1);

  EXPECT_EQ(0.1, pid->getKp());
  EXPECT_EQ(0.01, pid->getKi());
  EXPECT_EQ(0.5, pid->getKd());
}

/**
 * @brief Test the set functions properly set each gain
 */
TEST(PIDTest, testGainSetting) {
  std::shared_ptr<Pid> pid = std::make_shared < Pid > (0.1, 0.01, 0.5, 1);
  pid->setKp(5);
  pid->setKi(5);
  pid->setKd(5);

  EXPECT_EQ(10, pid->getKp());
  EXPECT_EQ(10, pid->getKi());
  EXPECT_EQ(10, pid->getKd());
}
