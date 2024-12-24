# Programming Concepts cpp

This project demonstrates various programming concepts using C++. Each concept is encapsulated into their own files. Look into the header files in the "include" directory to get an overview of the different concepts. Additionally, go into the implementation files in "src" to see them in more detail. Each file usually has a demonstration() function that will demonstrate the concept - these are called from main.

## Usage
1. Compile the project using one of the following:
    1. CMake. Use the supplied CMakeLists.txt file at the base directory. Example for building on Windows for Make installed via MSYS:
    ```
    cd Programming_Concepts_cpp
    mkdir build
    cd build
    cmake -G "MSYS Makefiles" ..
    cmake --build .
    ```
    2. Visual Studio Code. Open the project in VSCode and use the supplied ```.vscode/tasks.json``` file to build the project. Modify the compiler to match your system. You may also build with the CMake tools extension and the supplied CMakeLists.txt file.
    3. Manually compile with files with a C++ compiler. Example on Windows, using g++, running from a terminal at the repo's base directory:
    ```
    C:\msys64\ucrt64\bin\g++.exe -g ./src/*.cpp ./RK_Logger/src/log.cpp -I ./include -I ./RK_Logger/include -o ./Programming_Concepts_cpp
    ```
2. After building the project, simply run the executable to see the demonstration. If the project was built using of the methods above, the executable will be called "Programming_Concepts_cpp".