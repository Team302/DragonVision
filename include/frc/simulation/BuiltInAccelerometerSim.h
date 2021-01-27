// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <memory>

#include <hal/Accelerometer.h>

#include "frc/simulation/CallbackStore.h"

namespace frc {

class BuiltInAccelerometer;

namespace sim {

/**
 * Class to control a simulated built-in accelerometer.
 */
class BuiltInAccelerometerSim {
 public:
  /**
   * Constructs for the first built-in accelerometer.
   */
  BuiltInAccelerometerSim();

  /**
   * Constructs from a BuiltInAccelerometer object.
   *
   * @param accel BuiltInAccelerometer to simulate
   */
  explicit BuiltInAccelerometerSim(const BuiltInAccelerometer& accel);

  std::unique_ptr<CallbackStore> RegisterActiveCallback(NotifyCallback callback,
                                                        bool initialNotify);

  bool GetActive() const;

  void SetActive(bool active);

  std::unique_ptr<CallbackStore> RegisterRangeCallback(NotifyCallback callback,
                                                       bool initialNotify);

  HAL_AccelerometerRange GetRange() const;

  void SetRange(HAL_AccelerometerRange range);

  std::unique_ptr<CallbackStore> RegisterXCallback(NotifyCallback callback,
                                                   bool initialNotify);

  double GetX() const;

  void SetX(double x);

  std::unique_ptr<CallbackStore> RegisterYCallback(NotifyCallback callback,
                                                   bool initialNotify);

  double GetY() const;

  void SetY(double y);

  std::unique_ptr<CallbackStore> RegisterZCallback(NotifyCallback callback,
                                                   bool initialNotify);

  double GetZ() const;

  void SetZ(double z);

  void ResetData();

 private:
  int m_index;
};
}  // namespace sim
}  // namespace frc
