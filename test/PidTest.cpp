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
  std::shared_ptr<Pid> pid = std::make_shared<Pid>(0.1, 0.001, 0.03, 0.1);
  pid->setReference(4);
  double currentvelocity = pid->compute(1);
  EXPECT_NEAR(2.2003, currentvelocity, 0.0001);
  EXPECT_NEAR(2.02066, pid->compute(currentvelocity), 0.0001);

  pid->setReference(4);
  currentvelocity = pid->compute(1);
  EXPECT_NEAR(2.2003, currentvelocity, 0.0001);
  EXPECT_NEAR(2.02066, pid->compute(currentvelocity), 0.0001);
}

/**
 * @brief Test initialization of gains and the get functions
 */
TEST(PIDTest, testGainInit) {
  std::shared_ptr<Pid> pid = std::make_shared<Pid>(1, 1, 5, 1);

  EXPECT_EQ(1, pid->getKp());
  EXPECT_EQ(1, pid->getKi());
  EXPECT_EQ(5, pid->getKd());
}

/**
 * @brief Test the set functions properly set each gain
 */
TEST(PIDTest, testGainSetter) {
  std::shared_ptr<Pid> pid = std::make_shared<Pid>(0.1, 0.01, 0.5, 1);
  pid->setKp(5);
  pid->setKi(10);
  pid->setKd(15);

  EXPECT_EQ(5, pid->getKp());
  EXPECT_EQ(10, pid->getKi());
  EXPECT_EQ(15, pid->getKd());
}
