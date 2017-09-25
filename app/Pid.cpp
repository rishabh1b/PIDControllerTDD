/**
 *  @file      pid.cpp
 *  @brief     PID Class implementation
 *  @details   Implementation of the PID class to compute velocity as a result of a PID controller
 *  @author    Rishabh Biyani (rishabh1b)
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
Pid::Pid(double kp, double ki, double kd, double deltat)
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
  currentReference = reference;
  // Refresh the error and accumulators
  lastError = 0;
  accumulator = 0;
}

/**
 * @brief computes the next current velocity based on the calculated control signal
 * @param currentVelocity - current velocity value
 * @return velocity computed after one time step by the controller
 */
double Pid::compute(double currentVelocity) {
  double err = currentReference - currentVelocity;
  accumulator = accumulator + err;

  double controlSignal = kp * err + kd * (err - lastError) / deltat
      + ki * accumulator * deltat;
  lastError = err;
  return currentVelocity + controlSignal;
}

/**
 * @brief Get the value of the proportional gain
 * @return kp gain
 */
double Pid::getKp() {
  return kp;
}

/**
 * @brief Get the value of the integral gain
 * @return ki gain
 */
double Pid::getKi() {
  return ki;
}

/**
 * @brief Get the value of the derivative gain
 * @return Kd gain
 */
double Pid::getKd() {
  return kd;
}

/**
 * @brief Set the value of the proportional gain
 * @param kp New Kp value
 */
void Pid::setKp(double kp) {
  this->kp = kp;
}

/**
 * @brief Set the value of the integral gain
 * @param ki New Ki value
 */
void Pid::setKi(double ki) {
  this->ki = ki;
}

/**
 * @brief Set the value of the derivative gain
 * @param kd New Kd value
 */
void Pid::setKd(double kd) {
  this->kd = kd;
}

/**
 * @brief reinitialize the values for accumulator and lastError
 */
void Pid::refresh() {
  lastError = 0;
  accumulator = 0;
}
