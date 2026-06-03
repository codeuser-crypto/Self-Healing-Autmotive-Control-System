TITLE :- Self-Healing Automotive Control System with Runtime Fault Detection and Autonomous Recovery using QNX RTOS

My project explores ideas that industry is moving toward, especially self-healing architectures for future software defined vehicles.

Automotive Control System → Software controlling vehicle subsystems
Self-Healing → System detects failures and recovers automatically; NVIDIA, Tesla
Runtime Fault Detection → Faults detected while system is running
Autonomous Recovery → System restarts or fixes modules without human intervention
RTOS → Real-Time Operating System (Advantage - real time scheduling, fault isolation, message passing architecture)
ASIL-D certification :- Automotive Safety Integrity Level - D

There are 50-150 ECUs (braking, steering, engine - fuel injection and ignition, airbag etc) if one ECU fails; vehicle safety is compromised, system crashes, driver may lose control (braking ECU crash :- brakes do not respond, steering ECU crash :-  loss of steering/cruise control). My project works on this.

PHASE 1  :-
Part 1 → ECU modules
Part 2 → ECU communication + system flow
PHASE 2 :-
Part 3 → Health Monitoring
Part 4 → Fault Detection
Part 5 → Self Healing Recovery

PHASE 1 :-
Running order :-
Each ECU runs as an independent process and compiled, similar to real automotive architecture
sensor_ecu - generates vehicle data, simulates vehicle sensors
control_ecu - makes safety decisions, reads sensor data. Example :- ADAS Controller
brake_ecu - simulates braking systems. Example :- ABS
steering_ecu - simulates steering adjustment, collision avoidance. Example :- Electronic Steering
logger_ecu - records system events, tracking

Sensor ECU -> Speed:80 Distance:91 Steering:10 (This means the sensor ECU is generating real-time vehicle data)

Control ECU -> EMERGENCY BRAKE (9 m)
Control ECU -> SAFE (65 m)
This means the control ECU is reading the sensor distance and making decisions.
logic :-
distance > 40  → SAFE
20 < distance ≤ 40 → WARNING
distance ≤ 20 → EMERGENCY BRAKE

Logger -> Speed:33 Distance:17 Action:2
Logger -> Speed:81 Distance:95 Action:0
This proves shared memory communication is working, because the logger is reading the same data produced by the sensor and processed by control.
logic :-
0 = SAFE
1 = WARNING
2 = BRAKE

Each program uses:
while(1)
This simulates continuous real-time vehicle operation. In real cars, ECUs run as long as the vehicle is powered.

SYSTEM FLOW :-                                             EXAMPLE :-
Sensor ECU    Radar / Camera sensors                       Sensor → Distance = 17
Control ECU   ADAS Control ECU                             Control → EMERGENCY BRAKE
Brake ECU     Steering ECU                                 Brake ECU → Apply brake
Logger ECU    Vehicle network logging                      Logger → Action = 2

Steering or Brake less print :- Steering ECU runs only when action = WARNING
Brake ECU runs only when action = BRAKE. If distance stays high, they will not print.

Real systems use:
CAN bus
Automotive Ethernet
AUTOSAR architecture

My project uses:
1. Shared memory
2. Simplified decision logic
3. Multi process ECU simulation
4. Sensor processing
5. Control logic
6. Centralized logging
ECUs communicate using shared memory. ECU A -> sends data -> ECU B

Examples :-
Mercedes-Benz / BMW / Volkswagen - AUTOSAR allows: modular ECU software, communication between ECUs and fault tolerant automotive systems
[modular ECU architecture]
2. Tesla - Autopilot, Sensor fusion, braking and steering control
Instead of hundreds of independent ECUs, they are moving toward software-defined vehicles with centralized control computers.
[It shows the distributed architecture that older vehicles used, which is still widely deployed]


PHASE 2 :-

Brake ECU crashes
        ↓
System detects failure
        ↓
Watchdog restarts Brake ECU
        ↓
Braking continues normally

Bosch develops redundant and fault tolerating braking systems. Ex :- Electronic Stability Control.
Tesla Autopilot uses multiple processors and sensors.
Waymo (Google self driving)
still on fail safe, not self healing

Better :-
Self Healing Architecture
Modular ECU
Fault Monitoring Design
Transparent Logging System
Easy Simulation Environment
Future SDV (Software Defined Vehicle) :- Tesla, Hyundai, NVIDIA, Qualcomm, Volkswagen

Most current automotive systems are fail-safe, meaning they shut down a subsystem when a fault occurs. My project explores a self-healing architecture where the system can detect faults and recover automatically. This concept is important for future autonomous and software defined vehicles where continuous operation and reliability are critical.

Difference between my model and others :- 
1. Fail Safe :- A system detects a fault and moves to a safe state by shutting down or disabling functionality. Example :- Brake ECU fault -> ABS disabled -> Driver warning light...simple, reliable...system capability reduced, autonomous vehicles cannot rely
Toyota, Honda, Ford, Hyundai, Nissan etc. (((Disable Feature)))
2. Fail Operational :- If one system fails, another redundant system takes over. Example :- Primary ECU fails -> Backup ECU takes control, Airbus...extremely reliable, no loss...my project recovers software instead of hardware redundancy.
Bosch, Merc, BMW, Volkswagen etc.         (((Backup System)))
3. Hypervisor :- A hypervisor isolates multiple software systems running on the same hardware.
Tesla, BMW, Merc, Qualcomm etc.           (((Isolate Systems)))
4. Supervisor :- A supervisor monitors system health.
Bosch, Denso etc.                         (((Monitors Systems)))
5. Self Healing :- A self healing system detects faults, diagnoses the failed software component, and automatically restores it without requiring backup hardware or human intervention.

Future Vehicles require autonomous driving, always reliable system, remote software updates. These systems cannot simply disable features when faults occur. They must recover automatically.

Flow:-
Brake ECU crashes -> Watchdog detects no heartbeat  -> Watchdog restarts Brake ECU  -> Brake ECU continues working

Fail Safe :- Brake ECU failed, System entering Safe mode, Braking disabled (Brake ECU FAILED - System entering SAFE MODE - Braking disabled) no recovery; function lost
Fail Operational :- Primary Brake ECU failed, Switching to Backup Brake ECU, Backup ECU active (Not repaired, Just switched to backup)
In my system, when an ECU like the brake module fails, a watchdog detects the failure using heartbeat timeout and automatically restarts the ECU process. Unlike fail-safe systems that disable functionality or fail-operational systems that rely on backup hardware, my system restores the failed module itself, ensuring continuous operation. This demonstrates a self-healing software-defined automotive architecture.
