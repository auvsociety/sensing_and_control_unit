#ifndef SENSING_AND_CONTROL_UNIT_SRC_OLED_OLED_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_OLED_OLED_HPP

namespace sensing_and_control_unit {
class Oled {
 private:
  /* data */
  void displayVoltage(float voltage);
  void displayCurrent(float current);
  void displayTemperature(float temperature);

 public:
  Oled(/* args */);
  ~Oled();

  void initialize();

  void display(float voltage, float current, float temperature,
               int display_time);
};

}  // namespace sensing_and_control_unit

#endif  // SENSING_AND_CONTROL_UNIT_SRC_OLED_OLED_HPP