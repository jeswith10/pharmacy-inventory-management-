# 💊 Pharmacy Inventory Management System (C Project)

## 📄 Abstract
The **Pharmacy Inventory Management System** is a simple, terminal-based application written in **C**, designed to manage medicine inventory efficiently.  
It supports adding new medicines, searching by ID, updating stock details, and deleting records.  
All data is saved persistently in a **binary file (`pharmacy.dat`)**, ensuring availability across sessions.

This project demonstrates essential C programming concepts such as **file handling, structures, arrays, and menu-driven flow**, making it ideal for beginners and small pharmacy or medical store setups.

---

## 🚨 Features of the Program

### ✔ Add New Medicine Records:
- Medicine ID  
- Medicine Name  
- Quantity in Stock  
- Price  
- Manufacturer  
- Expiry Date  
- Category (Tablet / Syrup / Injection / Capsule / etc.)  

### ✔ Other Features:
- View all medicine records (table format)  
- Search medicine by ID  
- Update medicine details (quantity, price, expiry date, category)  
- Delete medicine records  
- Persistent binary storage (`pharmacy.dat`)  
- Creates data file automatically if missing  
- Terminal-based (CLI)  
- Beginner-friendly, clean code structure  
- Basic error handling for invalid input  

---

## 🖥 Technical Requirements

### 1. System Requirements
- OS: Windows / Linux / macOS  
- Terminal / Command-line  
- Minimum RAM: 4 MB  
- Minimal disk space (for `pharmacy.dat`)  

### 2. Software Requirements
- C Compiler: GCC / Clang / MinGW / MSVC  
- Any IDE or editor: VS Code, Code::Blocks, Dev-C++, Vim, Nano  
- Optional: Make tool  

### 3. Programming Requirements
- Language: C  
- C Standards: C89 / C99 / C11  
- Required Libraries:
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# 💊 Pharmacy Inventory Management System (C Project)

## 4. File Handling Requirements
- Read/write access to project folder  
- Records stored in binary: `pharmacy.dat`  
- Auto-creates the file if missing  

## 5. Compilation Requirements
Recommended compilation:
```bash
gcc pharmacy.c -o pharmacy -Wall
# ⚙️ Functional Requirements

## 1. User Interface
- Fully terminal-based  
- Clean menu display  
- Validates user inputs  

## 2. Pharmacy Inventory Operations

### 💊 Add Medicine
Stores new medicine details.

### 🔍 Search Medicine
Search by **Medicine ID**.

### 📋 View All Medicines
Displays all saved medicine records.

### ✏ Update Medicine
Modify:
- Quantity  
- Price  
- Expiry Date  
- Category  

### ❌ Delete Medicine
Removes a medicine entry after confirmation.

---

## 🗂 Data Management
- Persistent binary file (`pharmacy.dat`)  
- Data saved across multiple program runs  
- Handles missing/empty files gracefully  

---

## 🔁 Program Flow
- Menu-driven loop  
- Continues until user selects **Exit**  
- Provides clear messages and smooth navigation  

---

## ▶ How to Run the Program

### 1. Compile

#### Linux / macOS:
```bash
gcc pharmacy.c -o pharmacy
### 2. Run

#### Linux / macOS:
```bash
./pharmacy
### 3. Data File
- Auto-creates `pharmacy.dat`
- Stores all medicine records persistently

---

## 🖼 Screenshots
*(Replace with actual screenshots)*

1️⃣ Main Menu  
2️⃣ Add Medicine  
3️⃣ View Medicines  
4️⃣ Search Medicine  
5️⃣ Update Medicine  
6️⃣ Delete Medicine  
7️⃣ Exit
