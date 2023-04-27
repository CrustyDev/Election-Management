# Election Management program



# Compilation Instructions 
## Linux/WSL/Mac:
On Linux/OS x(Mac) download the following programs:
- cmake 
- make
Make sure you have a c/c++ compiler available.

then run the following command in the root directory of the project
```shell
$ mkdir build 
$ cd build && cmake .. && make
$ ./ElectionManagement
```
"ElectionManagement is the name of the program/executable"

## Windows:
On Windows again download the following programs:
- cmake
- Visual Studio 2022(MSVC) *or* Mingw32 (Make sure you add it to path)

Run the following commands for Mingw32 users 
```shell
$ md build
$ cd build
$ cmake .. -G "Unix Makefiles"
$ mingw32-make 
$ ./ElectionManagement.exe
```

For Visual Studio 2022 (MSVC) users
- Open the folder in visual studio and run it throgh there. Make sure that you chose ElectionManagement.exe in the dropdown of the run command
