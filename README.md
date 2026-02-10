# DubWriter

A simple text editor compatible with DubInstante to write rhythmo band faster and easier.

## Features

- 4 lines of editable text with horizontal scrolling (no line wrapping)
- Save functionality to export as .txt files
- Clean, simple interface
- Separated Core and UI layers for multi-platform compatibility

## Architecture

The application is structured with clear separation between Core and UI:

- **Core Module** (`src/core/`): Contains the `DocumentModel` class that manages the document data and file operations
- **UI Module** (`src/ui/`): Contains the `MainWindow` class that provides the Qt Widgets interface

This separation allows for easy adaptation to different platforms and UI frameworks.

## Building

### Prerequisites

- CMake 3.16 or later
- Qt 6.4 or later
- C++17 compatible compiler

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the application
make

# Run the application
./DubWriter
```

## Usage

1. Launch the application
2. Type text in any of the 4 line fields
3. Text will scroll horizontally without line breaks
4. Click the "Save" button to save your text as a .txt file
5. Choose a location and filename in the file dialog

## Platform Support

The application is designed to be cross-platform and should work on:
- Linux
- macOS
- Windows

The separation between Core and UI makes it easy to adapt to different platforms or add alternative UI implementations.
