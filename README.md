Infrared to LightWave RF relay
==============================


| JVC Button | JVC Code | LightWave RF Button | LightWave RF Code |
|------------|----------|---------------------|-------------------|
| Power      | 0xC2D0   | All Off             | C0 F0 F3 18 90    |
| Mute       | 0xC038   | Mood                | 82 F2 F3 18 90    |
| 1          | 0xC084   | Light 1 On          | 00 01 F3 18 90    |
| 2          | 0xC044   | Light 1 Off         | 00 00 F3 18 90    |
| 3          | 0xC0C4   | Light 2 On          | 00 11 F3 18 90    |
| 4          | 0xC024   | Light 2 Off         | 00 10 F3 18 90    |
| 5          | 0xC0A4   | Light 3 On          | 00 21 F3 18 90    |
| 6          | 0xC064   | Light 3 Off         | 00 20 F3 18 90    |
| 7          | 0xC0E4   | Light 4 On          | 00 31 F3 18 90    |
| 8          | 0xC014   | Light 4 Off         | 00 30 F3 18 90    |
| 9          | 0xC094   |                     |                   |
| 0          | 0xC004   |                     |                   |



Atmega 328 Pinout
-----------------

| Arduino Pin | AVR Pin | Function        |
|-------------|---------|-----------------|
| D0          | D0      | Serial Receive  |
| D1          | D1      | Serial Transmit |
| D2          | D2      |                 |
| D3          | D3      |                 |
| D4          | D4      |                 |
| D5          | D5      | Red LED         |
| D6          | D6      |                 |
| D7          | D7      |                 |
| D8          | B0      | IR Receive      |
| D9          | B1      | RF Transmit     |
| D10         | B2      |                 |
| D11         | B3      |                 |
| D12         | B4      |                 |
| D13         | B5      |                 |
| A0          | C0      |                 |
| A1          | C1      |                 |
| A2          | C2      |                 |
| A3          | C3      |                 |
| A4          | C4      |                 |
| A5          | C5      |                 |

