# Microcontroller-Based Clone Hero Guitar and Drum Controllers

Embedded Systems | Hardware Design | PCB Design | CAD | Microcontroller Programming

**Project Overview**
This projected involved the design and development of custom guitar and drum controller for _Clone Hero_, a music-based rhythmic video game. The objective was to integrate physical inputs with a microcontroller-based system with the capability of translating suer interaction into digital commands recognized by the game. The completed project was showcased at the 2026 Women Can Do tabling event, where it served as an interactive demonstration to engage high school students and encourage their interest in electrical engineering.

**Project Objectives**
- Design and assemble functional guitar and drum controllers compatible with _Clone Hero_
- Interface physical buttons, switches, and pressure sensors with a microcontroller
- Develop firmware to detect and process various user inputs
- Design PCB to house electronic components
- 3D print housing unit for controller
- Test controller functionality and reliability

**Hardware**
| Component | Function |
|---|---|
| Arduino Leonardo | Processes inputs and communicates with the computer |
| Push Buttons / Switches | Detect guitar fret and strum inputs |
| I2C Pressure Sensors | Detect drum strikes |
| Wiring and Connectors | Provide electrical connections between components |
| Computer | Runs Clone Hero and receives controller inputs |

**System Architecture**
1. _Input Detection_: Physical interaction with user through buttons and joystick.
2. _Signal Processing_: Microcontroller read signals and determines corresponding response.
3. _Input Mapping_: Detected actions are key-binded onto game controls.
4. _Communication_: Controller send appropriate commands to the connected computer.
5. _Game Response_: Clone Hero interprets commands as guitar or drum set inputs.

**Software Implementation**
The embedded firmware is responsible for monitoring live input signals and converting them into meaningful in-game commands.

Primary programming considerations:
- Using a microcontroller that had key binding abilities
- Input mapping and controller logic
- Timing and responsiveness
- Communication between hardware and software

_Programming Language_: C++
_Microcontroller_: Arduino Leonardo with ATMega32u4 chip
_Development Environment_: Arduino IDE

**Design and Implementation**
_Guitar Controller_: The guitar controller utilized five LED-illuminated fret buttons and a joystick serving as the strumming mechanism. Each fret button functioned as a digital input, registering a button press and transmitting the corresponding command to the game. The joystick detected directional movement to simulate upward and downward strumming. A large external housing was 3D printed using a hollow guitar form found from an online repository.
_Drum Controller_: The drum controller consisted of five balloons connected via flexible tubing to individual I2C pressure sensors. When a balloon was struck, the resulting increase in internal air pressure was detected by its corresponding sensor. Because the pressure sensors shared the I2C communication interface, an I2C multiplexer was implemented to allow the microcontroller to communicate with all five sensors individually. A zeroing button was implemented to calibrate the pressure sensors by setting their current readings to zero when pressed. This established a consistent baseline across all five balloons, accounting for differences in their initial internal pressures and improving the accuracy of drum hit detection. The microcontroller continuously monitored pressure changes and registered a drum hit when the measured pressure exceeded a predefined threshold, converting physical drum strikes into digital game inputs. The external housing was constructed using interconnected boxes, each designed to securely hold an individual balloon in place during operation.

**Testing and Troubleshooting**
A primary consideration in the hardware selection process was identifying a cost-effective microcontroller capable of supporting keyboard input emulation. The project initially utilized an Arduino Mega; however, further research identified the ATmega32U4 microcontroller as a more suitable option due to its native USB Human Interface Device (HID) capabilities. Consequently, the Arduino Leonardo was selected to enable direct keyboard input emulation and key mapping for compatibility with Clone Hero.

**Project Media**
_Guitar Controller_

### Guitar Controller Design

<p align="center">
  <img src="images/GuitarController_Physical_Design_Iteration1" width="48%">
  <img src="images/GuitarController_Key_Binding_Map" width="48%">
</p>

<p align="center">
  <em>Figure 1. Guitar controller physical design (left) and key binding map (right).</em>
</p>

### Guitar Controller CAD Design

<p align="center">
  <img src="images/GuitarController_CAD_files" width="90%">
</p>

<p align="center">
  <em>Figure 2. CAD models and design files for the guitar controller.</em>
</p>


### Guitar Controller Assembly and Final Design

<p align="center">
  <img src="images/GuitarController_Soldered_Buttons" width="32%">
  <img src="images/GuitarController_Final_Front" width="32%">
  <img src="images/GuitarController_Final_Back" width="32%">
</p>

<p align="center">
  <em>Figure 3. Soldered fret button assembly (left), completed guitar controller front view (middle), and back view (right).</em>
</p>

### Community Outreach — Women Can Do 2026

<p align="center">
  <img src="images/GuitarController_WomanCanDo" width="75%">
</p>

<p align="center">
  <em>Figure 4. Guitar controller showcased at the 2026 Women Can Do event, providing an interactive demonstration to engage high school students and encourage interest in electrical engineering.</em>
</p>

_Drum Controller_

### Drum Controller Design

<p align="center">
  <img src="images/DrumController_Design_Iteration1" width="48%">
  <img src="images/DrumController_Key_Mapping" width="48%">
</p>

<p align="center">
  <em>Figure 5. Initial drum controller design (left) and key mapping configuration (right).</em>
</p>

### Final Drum Controller Design

<p align="center">
  <img src="images/DrumController_Final_Top" width="48%">
  <img src="images/DrumController_Final_Side" width="48%">
</p>

<p align="center">
  <em>Figure 6. Completed drum controller showing the top view (left) and side view (right).</em>
</p>

_Circuit Design_
### Guitar Controller Circuit Schematic

<p align="center">
  <img src="images/GuitarController_CircuitSchematic" width="85%">
</p>

<p align="center">
  <em>Figure 7. Circuit schematic illustrating the electrical connections between the Arduino Leonardo, fret buttons, LEDs, and joystick strumming mechanism.</em>
</p>

**Note:** Photographic documentation of the initial breadboard prototype was not captured. The circuit schematic above illustrates the electrical design and connections used during prototyping. Arduino MicroPro was labeled in the image, but was later updated to Arduino Leonardo.


### Drum Controller Circuit Schematic and Breadboard Prototype

<p align="center">
  <img src="images/DrumController_CircuitSchematic" width="48%">
  <img src="images/DrumController_Breadboard_Prototype" width="48%">
</p>

<p align="center">
  <em>Figure 8. Drum controller circuit schematic (left) and physical breadboard prototype (right), illustrating the integration of the Arduino Leonardo and I2C pressure sensors for drum hit detection.</em>
</p>


**Future Improvements**
Although a custom PCB was planned for the project, it was never integrated due to budget constraints. Future development would involve implementing the PCB to replace the existing wiring configuration, improving the overall organization, reliability, and compactness of the electrical system.


**Course:** Microcontrollers (CMPE 3815)

**Institution:** University of Vermont

**Project Type:** Initially an independent project, later expanded as part of the Microcontrollers course.

**Contributions:** Independently initiated the project, including initial hardware selection, controller design, and development. Further developed and refined the guitar and drum controllers through microcontroller programming, sensor integration, circuit assembly, and troubleshooting.
