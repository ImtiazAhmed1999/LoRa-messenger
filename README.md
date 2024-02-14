# 🚀 LoRa Messaging Device Documentation

## Project Overview

![Top View](images/top view.jpg)

Welcome. This repository contains details, source code, and design files for this communication device. The project marries the reliability of LoRa technology with the charm of a button-style interface.

## Features

- 📡 **Long-Range Communication**: Utilizes LoRa technology for reliable and extended communication.
- 📱 **Keypad Interface**: Evokes the classic feel of button-style communication devices.
- 🌐 **Versatile Connectivity**: Designed for impressive range.
- ⚙️ **Customised PCB**

## Circuit
![Full Circuit](images/full circuit.png)

### Keypad Circuit

![keypad Circuit](images/keypad circuit)

This design uses a 3.3V voltage to meet the requirements of the communication device. It includes various electrical circuits, modules, and an ESP32 microcontroller.

#### Components

- 🕹️ **ESP32 Microcontroller**: Chosen for its versatility.
- 📡 **LoRa Transceiver Modules**: Leveraging LoRa's reputation for long-range communication.
- ⌨️ **Custom-Made Keypad**: 12 push buttons arranged in a 4x3 matrix configuration.
- 🔍 **Voltage Divider Circuit**: Employed for efficient button press detection.

#### Voltage Divider Principle

Integrated a custom-made keypad consisting of 12 push buttons arranged in a 4x3 matrix configuration. This keypad provides user input for text entry on an ESP32 microcontroller.

To efficiently capture button presses and translate them into usable data, used a voltage divider circuit and analog GPIO pins. Specifically, 12 push buttons are connected to the ESP32 through 6 resistors arranged in a voltage divider network. This arrangement allows us to detect the analog voltage values corresponding to each button press. Make sure to calibrate the analog values for the button rows.(0-4095)

By analyzing the voltage levels at the input pins, we can uniquely identify which button has been pressed based on the predefined voltage thresholds associated with each button.

### Power Supply

We used a 2S Lipo battery for the power supply of the device. However, since the LoRa module cannot handle more than 3.3V, we had to convert the voltage to 3.3V using a buck module.

## OLED User Interface

The device incorporates an OLED screen to provide a user-friendly interface. When buttons are pressed, the corresponding characters are registered and stored. These characters are then displayed on the OLED screen in real time, providing the user with immediate feedback.

## Device Selection and Messaging

The device allows users to select a specific device for sending messages. Through the user interface, users can navigate and choose a target device. The messaging process is seamless, with the selected characters displayed on the OLED screen and transmitted using LoRa technology.

## Usage

### Libraries Used

- [LoRa Library](https://github.com/sandeepmistry/arduino-LoRa)
- [Oled Display](https://github.com/adafruit/Adafruit_SSD1306)

### Getting Started
1. **Make the required hardware**
2. **Clone this repository:** `git clone https://github.com/your-username/LoRa-Messaging-Device.git`
3. **Open in IDE:** Use your preferred IDE (Integrated Development Environment).
4. **Install the libraries**
4. **Upload the code:** Load the code onto your device.

## Performance

- 🌍 **Open Space Range**: Achieved an 1km range in open spaces.
- 🏙️ **Constricted Area Range**: Performance may vary in congested areas.


## License

This project is licensed under the [License Name]. See the [LICENSE.md](LICENSE.md) file for details.
