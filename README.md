# SmartParkingLotC++ - Object-Oriented Parking System
> **This project was developed as part of an academic Object-Oriented Programming course.**

**SmartParkingLotC++** is a console-based parking management system developed in **C++**.
Unlike basic procedural implementations, this project leverages **Object-Oriented Programming (OOP)** principles such as **Inheritance** and **Polymorphism** to manage different types of vehicles efficiently.

The system tracks vehicle entry/exit, calculates parking fees based on vehicle type, and ensures data persistence using file handling.

---

## 📌 Key Features

* **Vehicle Variety:** Supports specific logic for **Cars**, **Trucks**, and **Motorcycles**.
* **Dynamic Pricing:** Calculates fees based on parking duration and vehicle type.
* **Capacity Management:** Tracks available spots for each vehicle category (10 Cars, 3 Trucks, 5 Motorcycles).
* **Persistence:** Saves and Loads current parking status (`parking_data.txt`) and financial summary (`summary_data.txt`).
* **Revenue Tracking:** Keeps a running total of parking time and revenue generated.
* **Real-Time Clock:** Uses the system time (`std::time`) for entry/exit timestamps.

---

## 💰 Pricing Model

The system implements a polymorphic cost calculation strategy:

| Vehicle Type | Class Name | Hourly Rate |
| :--- | :--- | :--- |
| 🚗 **Car** | `ClassB` | **5.0 NIS** / Hour |
| 🚚 **Truck** | `ClassC` | **100.0 NIS** / Hour |
| 🏍️ **Motorcycle** | `ClassD` | **1.0 NIS** / Hour |

---

## Technical Highlights

This project demonstrates advanced **C++** capabilities:

* **OOP & Inheritance:** `ClassA` serves as an abstract base class, while `ClassB`, `ClassC`, and `ClassD` inherit and implement specific behaviors.
* **Polymorphism:** Uses `virtual` functions (`calculateCost`, `toString`) to treat all vehicles generically as `ClassA*`.
* **STL Containers:** Extensive use of `std::vector` for managing vehicle collections dynamically.
* **Operator Overloading:** Includes custom `operator+` and `operator-` for adding/removing vehicles (in `ClassA`).
* **Smart Memory Management:** Proper cleanup of dynamically allocated objects (`delete`) to prevent memory leaks.

---

## Project Structure

* **`main.cpp`**: Entry point. Handles the menu loop, user input, and orchestrates the system.
* **`ClassA.h / .cpp`**: **Abstract Base Class**. Defines common attributes (license plate, entry time) and virtual interface.
* **`ClassB.h / .cpp`**: Represents a **Car**. Implements specific cost logic.
* **`ClassC.h / .cpp`**: Represents a **Truck**. Implements specific cost logic.
* **`ClassD.h / .cpp`**: Represents a **Motorcycle**. Implements specific cost logic.
* **`Utility.h`**: (Helper) Handles file I/O operations and formatting output.
* **`SmartParkingLotC++.sln`**: Visual Studio Solution file.

---

## How to Run

### Prerequisites
* **Visual Studio 2022** (Recommended) or any C++ compiler (GCC/Clang) supporting C++11 or later.

### Installation
1.  Clone the repository or download the source code.
2.  Open `SmartParkingLotC++.sln` in Visual Studio.
3.  Build the solution (**Ctrl + Shift + B**).
4.  Run the application (**Ctrl + F5**).

---

## Usage Guide

1.  **Vehicle Entry:** Choose a type (1-3) and enter a license plate. The system automatically checks for available spots.
2.  **Vehicle Exit:** Enter the license plate. The system calculates the duration and cost based on the specific vehicle type.
3.  **Display Status:** Shows all parked vehicles with their entry times.
4.  **File Operations:** You can manually Save or Load the parking state.

---

### License

This project is intended for educational and portfolio purposes.
