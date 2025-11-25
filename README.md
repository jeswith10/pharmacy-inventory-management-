#💊 ** PHARMACY INVENTORY MANAGEMENT SYSTEM (C Programming)**

##📄** ABSTRACT**

The Pharmacy Inventory Management System is a terminal-based application written in C designed to help manage medicine stock efficiently. It provides essential features such as adding, viewing, searching, updating, and deleting medicine records.

All inventory data is stored persistently in a binary file (pharmacy.dat) to ensure stock information is retained across program executions.

This project demonstrates important C programming concepts such as structures, file handling, control flow, loops, and modular programming — making it ideal for beginners, academic use, and practical learning.
---
##✨ FEATURES**
###**Core Functionalities**
➕ Add new medicine records (Medicine ID, Name, Quantity, Price, Manufacturing & Expiry Date)
📋 Display all inventory records in a clean table layout
🔍 Search medicine by Medicine ID
✏️ Update existing medicine details
❌ Delete expired or unused medicine entries
💾 Persistent storage using binary file (pharmacy.dat)
🖥️ Fully terminal-based, menu-driven system
👨‍💻 Beginner-friendly, modular & clean C code
⚙️ Automatically creates the storage file if missing
⚠️ Includes basic error handling & input validation
---

##**🛠️ TECHNICAL REQUIREMENTS**
###**System Requirements**

Operating System: Windows / Linux / macOS

Terminal or Command Prompt

At least 4 MB RAM

Minimal disk space for pharmacy.dat file

###**Software Requirements**

C Compiler: GCC / MinGW / Clang / MSVC

Code Editor / IDE: VS Code, Code::Blocks, Dev-C++, etc.

Make utility (optional)

###**Programming Requirements**

Language: C

Standards Supported: C89 / C99 / C11

Required header files:

stdio.h

stdlib.h

string.h

###**File Handling**

Requires read/write permissions

Records stored in binary format (pharmacy.dat)

File auto-created on first run

##📌** FUNCTIONAL REQUIREMENTS**
##**User Interface**

Terminal-based CLI

Easy, menu-driven navigation

Validates input and handles incorrect entries gracefully

##💊 **Pharmacy Inventory Operations**
##➕** Add Medicine**

Enter:

Medicine ID

Name

Quantity

Price

Manufacturing Date

Expiry Date
Stores data in pharmacy.dat

###📋 **Display Stock**

Shows all medicine records in a formatted table

Highlights expired/low-stock entries (optional enhancement)

🔍 ###**Search Medicine**

Search medicine using unique Medicine ID

###✏️** Update Medicine**

Modify:

Name

Quantity

Price

MFG/EXP dates

Other details

###❌ Delete Medicine**

Removes a medicine record permanently

Uses safe "temporary file" deletion method

###🔧 **DATA MANAGEMENT**

Fast & efficient binary file storage

Safe update/delete techniques

Handles missing/empty file gracefully

###🔄 **PROGRAM FLOW**

Menu runs in an infinite loop

Clear success & error notifications

Exit option included

###▶️ **Running the Program**
1️⃣ Compile
gcc pharmacy.c -o pharmacy

###2️⃣ Run 

**Linux / macOS**

./pharmacy


**Windows**

pharmacy.exe

###3️⃣ Data File

*Auto-creates pharmacy.dat on first run

*Stores all medicine records in binary format

##📸** Screenshots (Optional)**

*Add Medicine
<img width="383" height="481" alt="Screenshot 2025-11-25 191323" src="https://github.com/user-attachments/assets/c864f913-f1f9-42f4-80c2-2ed22e379539" />

*Display Inventory
<img width="1154" height="356" alt="Screenshot 2025-11-25 191358" src="https://github.com/user-attachments/assets/c955029e-b943-4ae4-bff5-87a4ba1bbbcd" />

*Search Medicine
<img width="543" height="510" alt="Screenshot 2025-11-25 191417" src="https://github.com/user-attachments/assets/b06d997f-61de-49ca-abe5-9223c57f35e1" />


*Update Stock
<img width="957" height="389" alt="Screenshot 2025-11-25 191516" src="https://github.com/user-attachments/assets/cd284c8f-ad20-4bed-9ac7-d0742522dfcd" />

*Delete Medicine
<img width="886" height="357" alt="Screenshot 2025-11-25 191545" src="https://github.com/user-attachments/assets/31a9d44d-7e39-4da5-b5ae-036fa2d7e2b1" />

*Exit
<img width="476" height="307" alt="Screenshot 2025-11-25 191559" src="https://github.com/user-attachments/assets/29390004-4fda-4c06-a983-6288b82d6360" />


##📝** Author**

**p.jeswith venkata sai**
