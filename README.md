# Electronic Voting System (EVS)

A console-based electronic voting management system developed in C++ that simulates Pakistan's electoral process for both National Assembly (MNA) and Provincial Assembly (MPA) elections.

## 📋 Project Overview

This project was developed as a **semester project for the Object-Oriented Programming (OOP) course** in **May 2023**. It demonstrates the implementation of OOP concepts in C++ to create a comprehensive voting management system that handles candidate registration, voter authentication, vote casting, and result declaration.

> **Note:** This project has not been updated since May 2023. It was created as an academic exercise and may contain improvements opportunities. **Contributions are welcome!**

## 🔄 Project Evolution

This terminal-based voting system served as the foundation for a more advanced implementation. The core concepts and logic developed here were later expanded into a **full-stack web application** with a graphical user interface during the **Database Systems course**.

**🌐 Web Version**: [Electronic Voting System (Web-Based)](https://github.com/FayazNoor/Voting-System)

The web version features:

- Modern web interface using PHP, MySQL, HTML, CSS, and JavaScript
- Enhanced user experience with graphical interfaces
- Advanced database management with MySQL
- Real-time election monitoring and analytics
- Responsive design for multiple devices

While this C++ version focuses on **OOP principles and console-based implementation**, the web version demonstrates **full-stack development and database design concepts**. Both projects complement each other in showcasing different aspects of software development.

## ✨ Features

### For Administrators

- **Secure Login System**: Password-protected administrator access
- **Candidate Registration**: Register political candidates for MNA/MPA seats
  - Validates age requirement (must be 25+ years)
  - Province-based seat allocation
  - Party affiliation and electoral symbols
- **Voter Management**: Track voter details and prevent duplicate voting
- **Real-time Vote Counting**: Automatic vote tallying for each candidate
- **Result Declaration**: View and declare election results by seat/province
- **Password Management**: Change administrator credentials

### For Voters

- **Voter Registration**: Register voters with personal details
- **Age Verification**: Ensures voters are 18+ years old
- **CNIC-based Authentication**: Prevents duplicate voting
- **Dual Voting**: Cast votes for both MNA and MPA seats
- **Province-specific Voting**: Vote for candidates in your province

## 🏗️ System Architecture

### Classes Structure

```
Person (Base Class)
├── Personal information management
└── Basic getters/setters

Voter (Inherits from Person)
├── Voting-specific information
├── Vote casting functionality
└── Vote verification methods

Candidate
├── Candidate information management
├── Electoral symbol management
└── Vote counting functionality

Election (Main Controller)
├── Voting process management
├── Candidate registration
├── Results calculation
└── Results display

Administrator
├── Access control
└── Credential management

Time & Date
└── Voting schedule management
```

## 📁 Project Structure

```
project/
├── Project/
│   ├── Project.cpp           # Main source code
│   ├── mna.txt               # MNA candidates data
│   ├── mpa.txt               # MPA candidates data
│   ├── signs.txt             # Electoral symbols registry
│   ├── system.txt            # Administrator credentials
│   ├── v_cnic.txt            # Voter CNIC records
│   ├── v_details.txt         # Voter details records
│   ├── temp.txt              # Temporary file for operations
│   ├── MNA_SEATS/
│   │   └── seats.txt         # MNA seat numbers
│   └── MPA_SEATS/
│       ├── punjab.txt        # Punjab MPA seats
│       ├── sindh.txt         # Sindh MPA seats
│       ├── kpk.txt           # KPK MPA seats
│       └── balochistan.txt   # Balochistan MPA seats
└── extra/                    # Backup/additional data files
```

## 🚀 Getting Started

### Prerequisites

- C++ Compiler (GCC/MinGW/MSVC)
- C++11 or higher
- Windows/Linux/macOS

### Compilation

```bash
# Using g++
g++ -o voting_system Project/Project.cpp -std=c++11

# Using MinGW (Windows)
g++ -o voting_system.exe Project/Project.cpp -std=c++11
```

### Running the Program

```bash
# Linux/macOS
./voting_system

# Windows
voting_system.exe
```

### Default Credentials

The system comes with default administrator credentials stored in `system.txt`. You can change these after logging in.

## 🎯 Usage Flow

1. **Administrator Login**
   - Enter administrator ID and password
   - Enter `0` to exit

2. **Main Menu Options**
   - Start Voting Process
   - Register Political Candidate
   - Check Specific Results/Filters
   - Declare Final Results
   - Change Administrator Password

3. **Voting Process**
   - Voter provides CNIC and personal details
   - System validates age (18+) and checks for duplicate voting
   - Voter selects MNA and MPA candidates by electoral symbol
   - Votes are recorded and tallied automatically

## 🔧 Technical Details

### Key OOP Concepts Demonstrated

- **Encapsulation**: Private data members with public getter/setter methods
- **Inheritance**: `Voter` class inherits from `Person` class
- **File Handling**: Persistent storage using text files
- **Data Validation**: Age verification, CNIC checking, seat validation
- **String Manipulation**: Custom parsing functions for data extraction

### Data Storage

All data is stored in plain text files with a structured format:

- Candidate information (party, name, votes, etc.)
- Voter records (CNIC, voting history)
- Electoral symbols and seat information

## 🐛 Known Limitations

- File-based storage (no database integration)
- Console-based interface (no GUI)
- Limited error handling in some scenarios
- No encryption for stored data
- Single administrator support

## 🤝 Contributing

This project was created as an academic exercise and **hasn't been updated since May 2023**. There's significant room for improvement! Contributions are **highly welcomed**.

### Potential Improvements

- [ ] Add database integration (MySQL/SQLite)
- [ ] Implement GUI using Qt or similar framework
- [ ] Add data encryption for security
- [ ] Improve error handling and input validation
- [ ] Add multi-administrator support
- [ ] Implement real-time result visualization
- [ ] Add unit tests
- [ ] Refactor code for better modularity
- [ ] Add logging system
- [ ] Implement result export functionality (PDF/CSV)

### How to Contribute

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -m 'Add some improvement'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Open a Pull Request

## 📝 License

This project is open source and available for educational purposes.

## 👥 Authors

Created as a semester project for the Object-Oriented Programming course at university in May 2023.

## 📧 Contact

For questions or suggestions, please open an issue in the repository.

---

**Disclaimer**: This is an educational project created for academic purposes. It is not intended for use in real electoral systems without significant security enhancements and professional audit.
