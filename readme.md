# 🏥 Hospital Management System  

A **C++ based Hospital Management System** designed using **Object-Oriented Programming (OOP)** concepts.  
The system efficiently manages the data and operations of different hospital entities like **Doctors, Receptionists, Medical Store, and Admin**.  
An advanced feature of the system is **Ambulance Routing**, which computes the **best possible route across given locations** using a graph-based approach powered by **Dijkstra’s Algorithm**.  

---

## 🚀 Features  

- **Doctor Management** 🩺  
  - Add, update, and remove doctor records.  
  - View specialization and availability schedules.  

- **Receptionist Module** 📝  
  - Handle patient appointments and doctor allocation.  
  - Maintain check-in/check-out logs.  

- **Medical Store Management** 💊  
  - Track medicine stock and availability.  
  - Generate bills for prescriptions.  

- **Admin Panel** 🔑  
  - Manage hospital staff (doctors, receptionists).  
  - Generate overall system reports.  

- **Ambulance Routing (Graph Algorithm)** 🚑  
  - Works on a **graph representation of locations (nodes and roads)**.  
  - Uses **Dijkstra’s Algorithm** to calculate the **best possible route** covering a given set of nodes.  
  - Supports dynamic distance input for flexibility.  

---

## 🛠️ Tech Stack  

- **Language:** C++  
- **Concepts Used:**  
  - Object-Oriented Programming (OOP)  
  - File Handling  
  - Inheritance, Polymorphism, Encapsulation, Abstraction  
  - Graph Algorithms (Dijkstra’s Algorithm for routing)  

---



---

## ⚙️ How It Works  

1. **Launch the executable** → Start the system and select your role (Admin, Doctor, Receptionist, Nurse, or Store Manager).  
2. **Role-based operations** → Each role has its own menu with specific functionalities (e.g., patient management, staff scheduling, inventory control).  
3. **File-based storage** → All records (patients, staff, medicines, etc.) are saved and retrieved from `.txt` files to ensure persistence across sessions.  
4. **Emergency Ambulance Routing** →  
   - The hospital map is modeled as a graph, with **locations as nodes** and **roads as weighted edges**.  
   - Users can input a **set of emergency destinations**.  
   - The system applies shortest-path algorithms to calculate the **optimal route** that visits all required locations efficiently.  


---

## ▶️ Getting Started  

### Prerequisites  
- C++ compiler (g++, clang++, or MSVC)  

### Compilation & Execution  

```bash
# Compile
g++ src/*.cpp -o hospital

# Run
./hospital

📊 Example: Ambulance Routing
Enter number of locations: 6
Enter roads (u v distance):
1 2 4
1 3 2
2 4 5
3 4 8
2 5 10
4 6 3

Enter number of emergency locations: 3
Locations: 2 5 6

Best possible route from Hospital (node 1):  
1 -> 2 -> 5 -> 4 -> 6  
Total Distance: 22 units


👨‍💻 Author

Developed as an academic project showcasing C++ OOP principles and graph algorithms applied to real-world healthcare scenarios.