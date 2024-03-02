

// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// khỏi tao bien để lay dl tu MPU6050
Adafruit_MPU6050 mpu;
// const int soundSensorPin = 15; // Đầu vào của cảm biến âm thanh được kết nối với chân analog A0

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  // Wire.begin(16, 0);

  // Try to initialize!
  if (!mpu.begin()) {
    // Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  // Serial.println("");
  // pinMode(soundSensorPin, INPUT); // Thiết lập chân đầu vào của cảm biến âm thanh
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  // int soundValue = analogRead(soundSensorPin); // Đọc giá trị từ cảm biến âm thanh
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  // Serial.print("AccelX:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  // Serial.print("AccelY:");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  // Serial.print("AccelZ:");
  Serial.print(a.acceleration.z);
  Serial.print(",");
  // Serial.print("GyroX:");
  Serial.print(g.gyro.x);
  Serial.print(",");
  // Serial.print("GyroY:");
  Serial.print(g.gyro.y);
  Serial.print(",");
  // Serial.print("GyroZ:");
  Serial.print(g.gyro.z);
  Serial.println("");
 
  // Serial.print("Sound:");
  // Serial.println(soundValue); // In giá trị âm thanh lên Serial Monitor
  // Serial.println("");
  delay(32);
}
