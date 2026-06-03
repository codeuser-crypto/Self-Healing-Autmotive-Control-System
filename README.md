# Self-Healing Automotive Control System with Runtime Fault Detection and Autonomous Recovery using QNX RTOS

> A fault-tolerant automotive software architecture built on QNX RTOS that simulates real world Electronic Control Units (ECUs), performs runtime fault detection and automatically recovers failed modules using a watchdog based self healing mechanism.

## Overview

Modern vehicles contain 50–150 Electronic Control Units (ECUs) responsible for critical functions such as braking, steering, engine control, airbags and Advanced Driver Assistance Systems (ADAS). Failure of a single ECU can compromise vehicle safety and system reliability.

This project demonstrates a modular automotive control system where independent ECU processes communicate in real time and a watchdog supervisor continuously monitors system health. When a fault occurs, the system automatically detects the failure and restores the affected ECU without human intervention, showcasing a self-healing architecture for future Software Defined Vehicles (SDVs).

---

## Key Features

### Modular ECU Architecture

* Independent ECU processes
* Real-time data exchange
* Automotive-inspired software design
* Fault isolation between modules

### Runtime Fault Detection

* Continuous ECU health monitoring
* Heartbeat based supervision
* Failure detection during operation
* Real time fault identification

### Autonomous Recovery

* Automatic ECU restart
* Watchdog based supervision
* Continuous system availability
* Reduced downtime

### Automotive System Simulation

* Sensor processing
* Control decision logic
* Braking subsystem
* Steering subsystem
* Centralized event logging

### QNX RTOS Concepts

* Real time scheduling
* Process isolation
* Inter process communication
* Shared memory communication

---

# System Architecture

```text
Sensor ECU
     │
     ▼
Control ECU
     │
 ┌───┴───┐
 ▼       ▼
Brake   Steering
 ECU      ECU
     │
     ▼
 Logger ECU
     │
     ▼
Watchdog Supervisor
```

Each ECU runs as an independent process similar to real automotive architectures used in modern vehicles.

---

# ECU Modules

## Sensor ECU

Simulates vehicle sensors by generating:

* Vehicle speed
* Obstacle distance
* Steering angle

Example:

```text
Speed: 80 km/h
Distance: 17 m
Steering: 10°
```

---

## Control ECU

Processes sensor information and determines vehicle actions.

Decision Logic:

```text
Distance > 40m      → SAFE
20m < Distance ≤ 40m → WARNING
Distance ≤ 20m      → EMERGENCY BRAKE
```

---

## Brake ECU

Simulates:

* ABS-style braking actions
* Emergency braking responses
* Collision avoidance support

---

## Steering ECU

Simulates:

* Steering corrections
* Collision avoidance adjustments
* ADAS steering assistance

---

## Logger ECU

Records:

* Sensor values
* Vehicle actions
* Safety decisions
* System events

---

# Inter ECU Communication

The ECUs communicate using shared memory.

```text
Sensor ECU
     │
     ▼
Shared Memory
     │
     ▼
Control ECU
     │
     ▼
Brake / Steering ECU
     │
     ▼
Logger ECU
```

This architecture demonstrates real time communication between multiple automotive software components.

---

# Phase 1 – Automotive Control System

Implemented:

* ECU process architecture
* Shared memory communication
* Sensor data generation
* Decision-making logic
* Braking simulation
* Steering simulation
* Centralized logging

The system continuously runs using infinite execution loops similar to real automotive ECUs that remain active while the vehicle is powered on.

---

# Phase 2 – Self Healing Architecture

A watchdog supervisor continuously monitors ECU health using heartbeat signals.

When an ECU stops responding:

```text
Brake ECU Failure
        │
        ▼
Heartbeat Timeout
        │
        ▼
Watchdog Detects Failure
        │
        ▼
Automatic ECU Restart
        │
        ▼
System Restored
```

This demonstrates autonomous software recovery without requiring manual intervention.

---

# Why Self Healing?

Most automotive systems today are designed to be fail-safe.

## Fail Safe

```text
Brake ECU Failure
        ↓
Disable Function
        ↓
Warning Light
```

Advantages:

* Simple
* Reliable

Limitation:

* Functionality is lost

---

## Fail Operational

```text
Primary ECU Failure
        ↓
Backup ECU Activated
        ↓
Operation Continues
```

Advantages:

* No service interruption

Limitation:

* Requires redundant hardware

---

## Self-Healing (This Project)

```text
Brake ECU Failure
        ↓
Watchdog Detection
        ↓
Automatic Restart
        ↓
Function Restored
```

Advantages:

* No backup hardware required
* Lower cost
* Automatic recovery
* Continuous operation

Unlike fail safe systems that disable functionality or fail operational systems that rely on redundant hardware, this project restores the failed ECU itself.

---

# Technologies Used

### Operating System

* QNX RTOS

### Programming

* C

### Automotive Concepts

* ECU Architecture
* ADAS Control Logic
* Watchdog Supervision
* Heartbeat Monitoring
* Fault Detection
* Process Recovery

### Communication

* Shared Memory IPC

---

# Industry Relevance

The project explores concepts increasingly adopted in modern Software Defined Vehicles (SDVs).

Related industry directions:

* Autonomous Driving
* Centralized Vehicle Computing
* Runtime Health Monitoring
* Over the Air Updates
* Self Healing Architectures
* Safety Critical Systems

Companies exploring similar future architectures include Tesla, NVIDIA, Qualcomm, Volkswagen, Hyundai, Bosch and Waymo.

---

# Future Enhancements

* CAN Bus Integration
* Automotive Ethernet
* AUTOSAR Support
* Hypervisor-Based Isolation
* ASIL-D Safety Extensions
* Redundant Controllers
* Predictive Fault Detection
* OTA Software Updates
* Distributed Vehicle Control

---

# Learning Outcomes

This project demonstrates practical implementation of:

* Real-Time Operating Systems
* Automotive Software Architecture
* Multi-Process System Design
* Inter-Process Communication
* Fault Detection Mechanisms
* Watchdog-Based Monitoring
* Autonomous Recovery Systems
* Software Defined Vehicle Concepts
* Safety-Critical Embedded Systems
A QNX RTOS-based automotive software project demonstrating runtime fault detection, watchdog supervision, and autonomous ECU recovery for future Software Defined Vehicles.
