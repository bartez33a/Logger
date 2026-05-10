# Logger

Lightweight and efficient asynchronous logger written in C++.

## 📌 About The Project

`Logger` is a simple logging library designed for C++ applications. The project focuses on:

- asynchronous logging,
- clean and easy-to-use API,
- easy integration with existing projects.

The logger allows applications to record messages with different log levels while keeping logging operations efficient and non-blocking.

---

## ✨ Features

- ✅ Asynchronous logging
- ✅ Multiple log levels
- ✅ Simple configuration
- ✅ Lightweight and fast
- ✅ Easy integration with C++ projects

---

## 🛠️ Built With

- **C++**
- STL (`thread`, `mutex`, `queue`, `fstream`)

---

## 📂 Project Structure

```txt
Logger/
│
├── Logger/               # Logger source code
├── Logger.slnx           # Visual Studio solution
├── .gitignore
└── README.md
```

---

## 🚀 Getting Started

### Clone the repository

```bash
git clone https://github.com/bartez33a/Logger.git
```

### Open in Visual Studio

1. Open `Logger.slnx`
2. Build the solution (`Build Solution`)
3. Run the project

---

## ▶️ Example Usage

```cpp
#include "Logger.h"

int main()
{
    Logger::get()->log_info("Application started");
    Logger::get()->log_warning("Low memory warning");
    Logger::get()->log_error("Unexpected error");

    return 0;
}
```

## 👤 Author

Created by:

- **bartez33a**

GitHub Repository:

- https://github.com/bartez33a/Logger

