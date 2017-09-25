/**
 *  @file      pid.cpp
 *  @brief     PID Class implementation
 *  @details   Implementation of the PID class to compute velocity as a result of a PID controller
 *  @author    Rishabh Biyani (patnolan33)
 *  @copyright GNU Public License.
 */

#include "Pid.h"
#include <iostream>

/**
 * @brief PID constructor
 * @param Kp initial value for Kp
 * @param Ki initial value for Ki
 * @param Kd initial value for Kd
 * @param dt initial value for dt
 */
Pid::Pid(double kp, double kd, double ki, double deltat)
    : kp(kp),
      ki(ki),
      kd(kd),
      deltat(deltat),
      lastError(0),
      accumulator(0),
      currentReference(0) {
}

/**
 * @brief set reference velocity of the controller
 * @param reference - reference velocity to be achieved
 */
void Pid::setReference(double reference) {
  return;
}

/**
 * @brief computes the next current velocity based on the calculated control signal
 * @param currentVelocity - current velocity value
 * @return velocity computed after one time step by the controller
 */
double Pid::compute(double currentVelocity) {

  return 0;
}

/**
 * @brief Get the value of the proportional gain
 * @return kp gain
 */
double Pid::getKp() {
  return 0;
}

/**
 * @brief Get the value of the integral gain
 * @return ki gain
 */
double Pid::getKi() {
  return 0;
}

/**
 * @brief Get the value of the derivative gain
 * @return Kd gain
 */
double Pid::getKd() {
  return 0;
}

/**
 * @brief Set the value of the proportional gain
 * @param kp New Kp value
 */
void Pid::setKp(double kp) {
  return;
}

/**
 * @brief Set the value of the integral gain
 * @param ki New Ki value
 */
void Pid::setKi(double ki) {
  return;
}

/**
 * @brief Set the value of the derivative gain
 * @param kd New Kd value
 */
void Pid::setKd(double kd) {
  return;
}

/**
 * @brief reinitialize the values for accumulator and lastError
 */
void Pid::refresh() {
  return;
}
