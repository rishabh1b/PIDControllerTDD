/**
 *  @file      Pid.h
 *  @brief     PID Class
 *  @details   Definition of the PID class to compute velocity output from PID controller
 *  @author    Rishabh Biyani (rishabh1b)
 *  @copyright GNU Public License.
 */

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

class Pid {
 public:
  /**
   * @brief PID constructor
   * @param Kp value for prop gain
   * @param Ki value for integral gain
   * @param Kd value for derivative gain
   * @param deltat value for time interval
   */
  /**
   * @brief parametric constructor to initialize the controller
   * @param kp - Proportional Gain
   * @param Kd - Derivative Gain
   * @param ki - Integral Gain
   * @param deltat - time interval to use for differentiation and integration.
   */
  Pid(double kp, double kd, double ki, double deltat);

  /**
   * @brief computes the next current velocity based on the calculated control signal
   * @param currentVelocity - current velocity value
   * @return velocity computed after one time step by the controller
   */
  double compute(double currentVelocity);

  /**
   * @brief set reference velocity of the controller
   * @param reference - reference velocity to be achieved
   */
  void setReference(double reference);

  /**
   * @brief kp, kd, ki setter functions
   * @param kp - proportionalgain
   * @param kd - derivative gain
   * @param ki - Integral Gain
   */
  void setKp(double kp);
  void setKd(double kd);
  void setKi(double ki);

  /**
   * @brief kp, kd, ki getter functions
   * @return kp, ki or kd - the gains that are set
   */
  double getKp();
  double getKi();
  double getKd();

 private:
  /**
   * @brief reinitialize the values for accumulator and lastError
   */
  void refresh();

  /**
   * @brief proportional, integral and derivative gains
   */
  double kp;
  double ki;
  double kd;

  /**
   * @brief variable for time step to be used
   */
  double deltat;

  /**
   * @brief variable keeping track at the last time step
   */
  double lastError;

  /**
   * @brief variable adding error across time steps
   */
  double accumulator;
  /**
   * @brief variable to keep a track of current reference
   */
  double currentReference;
};

#endif /* INCLUDE_PID_H_ */
