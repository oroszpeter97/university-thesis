# Build and Run Instructions (Linux)

This project uses a Makefile for building and running the application on Linux. The main targets are:

- `make build` &mdash; Configure and build the project (output in `out/`)
- `make run` &mdash; Run the built executable (after `make build`)
- `make buildrun` &mdash; Build and then run the executable
- `make clean` &mdash; Remove the build output directory

## Quick Start

1. **Build the project:**
    ```sh
    make build
    ```

2. **Run the executable:**
    ```sh
    make run
    ```

3. **Build and run the project:**
   ```sh
   make buildrun
   ```

4. **Clean build output:**
    ```sh
    make clean
    ```

The built executable will be located at `out/university_thesis` by default.

# Build and Run Instructions (Windows)
1. Ensure you have `cmake` and a C++ compiler (e.g., Visual Studio or MinGW) installed.
2. Clone the repository:
   ```powershell
   git clone https://github.com/oroszpeter97/university-thesis.git
   cd university-thesis
   ```
3. Create a build directory and navigate to it:
   ```powershell
   mkdir build
   cd build
   ```
4. Run `cmake` to configure the project:
   - For Visual Studio:
     ```powershell
     cmake .. -G "Visual Studio 17 2022"
     ```
   - For MinGW:
     ```powershell
     cmake .. -G "MinGW Makefiles"
     ```
5. Build the project:
   - For Visual Studio, open the generated `.sln` file and build the project.
   - For MinGW:
     ```powershell
     mingw32-make
     ```
6. Run the executable:
   ```powershell
   .\university-thesis.exe
   ```

# License

This project is licensed under the GNU General Public License (GPL). You are free to use, modify, and distribute this software, but any derivative work must also be open-sourced under the same license. For more details, see the [LICENSE](./LICENSE) file.
