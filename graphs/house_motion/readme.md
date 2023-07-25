# House Drawing 128x64 pixels - With Motion

## Components
- 128x64 OLED Display

## Comments
This code was created to train bitwise operators, the following operators and counters were used:
- count: range 0-127
- chimmey smoke animation: count&7 to range 0-7
- sun and moon motion: count>>5 to identify the stage and count&31 to range 0-31
- stars fade in and out: (count&31)>>3 to identify the 4 stages of fade (maybe 8 stages would be smoother)
