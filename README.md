# PIC18F47Q10 Utils

![C Programming Language](https://raw.githubusercontent.com/github/explore/main/topics/c/c.png)
![Microchip Logo](https://upload.wikimedia.org/wikipedia/commons/c/ca/Microchip-Logo.svg)

This repository provides utility files for the **PIC18F47Q10** microcontroller, including functionalities such as UART communication, interrupt handling, timer operations, and string-controlled multicolored LED control.

---

## Features

- **UART Communication**: Facilitates serial data transmission and reception.
- **Interrupt Handling**: Manages asynchronous events efficiently.
- **Timer Operations**: Supports precise timing and event scheduling.
- **Multicolored LED Control**: Allows string-based commands to manage LED colors and patterns.

---

## Getting Started

### Prerequisites

- **MPLAB X IDE**
- **XC8 Compiler**
- **PICkit 4 or compatible programmer**
- **PIC18F47Q10 Development Board**

### Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Strife-01/PIC18F47Q10-Utils.git
   ```
   
2. **Open the Project**:
   - Launch **MPLAB X IDE**.
   - Navigate to `File` > `Open Project` and select the cloned repository.

3. **Configure the Project**:
   - Ensure the **PIC18F47Q10** microcontroller is selected.
   - Verify that the necessary libraries and dependencies are included.

4. **Build and Program**:
   - Connect your development board.
   - Use the 'Make and Program Device' option to compile and upload the firmware.

---

## Usage

### UART Communication

- Initialize the UART module with the desired baud rate.
- Use the provided functions to send and receive data.

### Interrupt Handling

- Enable necessary interrupts in the configuration.
- Implement interrupt service routines as required.

### Timer Operations

- Configure timers for specific intervals.
- Utilize timer interrupts or polling methods for event handling.

### Multicolored LED Control

- Send string commands to control LED colors and patterns.

---

## Contributing

Contributions are welcome! If you have improvements or additional features to share, please fork the repository, create a new branch for your feature or bug fix, and submit a pull request. Ensure your code adheres to the project's coding standards and includes appropriate documentation.

---

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the code, provided proper attribution is given.

---

## Acknowledgments

- **Microchip Technology**: For the PIC18F47Q10 microcontroller and development tools.
- **Open-Source Community**: For contributions and support.
