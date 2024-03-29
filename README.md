# ESP-NOW Remote-Controlled Car

## Overview

This project involves building a remote-controlled car using the ESP-NOW protocol. ESP-NOW, created by Espressif, facilitates communication between multiple devices without the need for Wi-Fi. Similar to 2.4GHz low-power wireless connectivity used in wireless mice, ESP-NOW enables peer-to-peer and secure communication between devices. Pairing of devices is required initially, after which communication can occur without the need for a handshake.

For detailed instructions on setting up ESP-NOW with ESP32 in the Arduino IDE, refer to this [tutorial](https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/).

## Functionality

- Allows remote control of a car using the ESP-NOW protocol.
- Establishes a peer-to-peer connection between devices without the need for Wi-Fi.
- Provides secure communication between devices after initial pairing.

## Implementation

The car is controlled remotely using devices equipped with ESP32 boards communicating via ESP-NOW. Pairing of devices is required before they can communicate, ensuring a secure connection. Once paired, remote control commands can be sent directly to the car without the need for constant handshakes.

## Components Used

- ESP32 boards (for both car and remote control)
- Motor driver
- DC motors
- Wheels
- Battery pack
- Chassis
- Other electronic components as required

## Transmitter Diagram
<img width="532" alt="Transmitter Diagram" src="https://github.com/Z313PH/Remote-Controlled-Car-with-ESP-NOW/assets/119972119/d079666d-422f-40df-9a25-b9982bc0cc1a">

## Receiver Diagram
<img width="512" alt="Receiver Diagram" src="https://github.com/Z313PH/Remote-Controlled-Car-with-ESP-NOW/assets/119972119/3ce9f2f1-7c7d-4b81-a13f-f147bb4645fd">

## Setup Instructions

1. Set up the ESP32 boards for both the car and remote control.
2. Configure ESP-NOW communication between the devices.
3. Connect the motor driver, DC motors, and wheels to the car.
4. Assemble the car chassis and mount the components securely.
5. Pair the remote control device with the car.
6. Upload the necessary code to both devices.
7. Power on the car and remote control, and start controlling the car wirelessly.

## Repository Contents

- **Arduino Sketches**: Contains the code necessary to implement ESP-NOW communication between the car and remote control.
- **Project Image**: Illustration or image depicting the setup of the remote-controlled car.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- This project was inspired by the capabilities of the ESP-NOW protocol and its application in wireless communication between devices.

Feel free to contribute, report issues, or suggest improvements! Enjoy remote-controlling your car with ESP-NOW! 🚗🕹️
