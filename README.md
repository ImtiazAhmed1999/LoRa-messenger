# 🚀 LoRa Messaging Device Documentation

## Project Overview

Welcome. 
This repository contains details, source code, and design files for this communication device. The project marries the reliability of LoRa technology with the keypad interface.

![Top View](images/top%20view.jpg)![Bottom View](images/bottom%20view.png)

## Features

- 📡 **Long-Range Communication**: Utilizes LoRa technology for reliable and extended communication.
- 📱 **Keypad Interface**: Evokes the classic feel of button-style communication devices.
- 🌐 **Versatile Connectivity**: Designed for impressive range.
- ⚙️ **Customised PCB**

## Full Circuit
![Full Circuit](images/full%20circuit.png)

This design uses a 3.3V voltage to meet the requirements of the communication device. It includes various electrical circuits, modules, and an ESP32 microcontroller.

### Components

- 🕹️ **ESP32 Microcontroller**: Chosen for its versatility.
- 📡 **LoRa Transceiver Modules(SX1278)**: Leveraging LoRa's reputation for long-range communication.
- ⌨️ **Custom-Made Keypad**: 12 push buttons arranged in a 4x3 matrix configuration.
- 🖥️ **I2C OLED Display 0.96"**: Incorporates a vibrant OLED screen for a user-friendly interface.
- 🔄 **Buck Module (MP1584)**: Converts the voltage to 3.3V, ensuring compatibility with the LoRa module.
- 🔄 **INA219 Current Sensor**: Used for measurement of voltage, current, and power consumption.
- 📡 **433MHz Spring Type Antenna**: Enhances communication range and signal strength.


### Keypad Circuit

![keypad Circuit](images/keypad%20circuit.png)

### Voltage Divider Principle

Integrated a custom-made keypad consisting of 12 push buttons arranged in a 4x3 matrix configuration. This keypad provides user input for text entry on an ESP32 microcontroller.

To efficiently capture button presses and translate them into usable data, used a voltage divider circuit and analog GPIO pins. Specifically, 12 push buttons are connected to the ESP32 through 6 resistors arranged in a voltage divider network. This arrangement allows us to detect the analog voltage values corresponding to each button press. Make sure to calibrate the analog values for the button rows. (0-4095)

By analyzing the voltage levels at the input pins, we can uniquely identify which button has been pressed based on the predefined voltage thresholds associated with each button.

### Power Supply

We used a 2S Lipo battery for the power supply of the device. However, since the LoRa module cannot handle more than 3.3V, we had to convert the voltage to 3.3V using a buck module.

### OLED User Interface

The device incorporates an OLED screen to provide a user-friendly interface. When buttons are pressed, the corresponding characters are registered and stored. These characters are then displayed on the OLED screen in real time, providing the user with immediate feedback.

### Measuring Power Consumption with INA219

To monitor power consumption, we've integrated the INA219 current sensor. This sensor allows precise measurement of voltage, current, and power consumption. The collected data provides insights into the device's energy efficiency and aids in optimizing power usage.

### 433MHz Spring Type Antenna

For optimal performance in the 433MHz frequency range, we've employed a spring type antenna. This design choice enhances the communication range and signal strength, especially in open spaces.
- **RF Antenna Type**: Spring Antenna
- **Model**: CTRF-ANTENNA-SP-0433-3505
- **Frequency**: 433MHz
- **Gain**: 3dBi
- **VSWR (Voltage Standing Wave Ratio)**: ≤2.0
- **Impedance**: 50Ω
- **Polarization**: Vertical Polarization
- **Spring Coil Wire OD (Outer Diameter)**: 0.8mm
- **Spring Coil Antenna OD (Outer Diameter)**: 5mm
- **Spring Coil Turns**: 21
- **Lightning Protection**: DC-Ground

### Device Selection and Messaging

The device allows users to select a specific device for sending messages. Through the user interface, users can navigate and choose a target device. The messaging process is seamless, with the selected characters displayed on the OLED screen and transmitted using LoRa technology.

## Libraries Used

- [LoRa Library](https://github.com/sandeepmistry/arduino-LoRa)
- [Oled Display](https://github.com/adafruit/Adafruit_SSD1306)

## Implementation
1. **Make the required hardware**
2. **Clone this repository:** `git clone https://github.com/your-username/LoRa-Messaging-Device.git`
3. **Open in IDE:** Use your preferred IDE (Integrated Development Environment).
4. **Install the libraries**
4. **Upload the code:** Load the code onto your device.

## Performance

- 🌍 **Open Space Range**: Achieved a 1km range in open spaces.
- 🏙️ **Constricted Area Range**: Performance may vary in congested areas.


## License

This project is licensed under the [License Name]. See the [LICENSE.md](LICENSE.md) file for details.
