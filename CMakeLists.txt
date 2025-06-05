cmake_minimum_required(VERSION 3.16)
project(CongoGUI VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Source files
set(SOURCES
        main.cpp
        MainWindow.cpp
        StoredItem.cpp
        StorageManager.cpp
)

# Header files
set(HEADERS
        MainWindow.h
        Exceptions.h
        StoredItem.h
        StorageManager.h
)

set(CMAKE_AUTOMOC ON)

# Add executable
add_executable(CongoGUI ${SOURCES} ${HEADERS})

# Link Qt libraries
target_link_libraries(CongoGUI PRIVATE Qt5::Widgets)

# Include directories
target_include_directories(CongoGUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

