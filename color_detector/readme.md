# Color Detector
This code uses a TCS230 sensor to ligth a RGB led
## Components
- RGB Led
- TCS230 color sensor
- 3 small value resistor to connect the small RGB led
## Comments
This comment normalize the frequency from the sensor using (1-(x-Min/Max-Min)), then I multiply for 255 to make sure it will be on 0-255 range. The sensor is usually very sensitive to your ambient light. So I suggest updating min and max.
