# Minimal example of a CMake-enabled C++ project

This is an example C++ project that includes tests using GTest and documentation using Doxygen+Sphinx+breathe. The project is built using CMake.

## Prerequisites

Install the dependencies:

```bash
conda env create -f environment.yml
```

This will create a conda environment called `cppdev` which you can activate with:

```bash
conda activate cppdev
```

### Building the project

To build the project, create a build directory and run CMake from there:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

You can now run the tests:

```bash
ctest
```

It might be called ctest.exe in Windows.

The documentation will also be generated in the `build/docs/sphinx/index.html` directory. Open the `index.html` file in a web browser to view it.

## Cleaning the project

To clean the project, just remove the `build` directory:

```bash
rm -rf build
```

## Running plotting.py

To be able to run the matplotlib visualization you need to run the cpp files to generate the frequency.txt files.

In the build directory:

```bash
./bin/main_zipfs_containers
```

After this, "frequency_old_text.txt" and "frequency.txt" files should be generated at the root folder.

Run the following command to generate the visuals.

Note: you may need to install matplotlib if not installed.

```bash
make run_plotting
```
