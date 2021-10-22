# PyCppDemo

## Preparation

1. Set up the git repo.

2. Add essential submodules: put all 3rd party libraries in a folder, and manage them with ```git submoudle```.

  ```
  cd third_party
  ```

  * [Pybind11](https://github.com/pybind/pybind11)
  ```
  git submodule add https://gitlab.com/libeigen/eigen.git eigen
  cd eigen
  git checkout 3.4
  cd ..
  ```

  * [Eigen](https://gitlab.com/libeigen/eigen)
  ```
  git submodule add https://github.com/pybind/pybind11.git pybind11
  cd pybind11
  git checkout v2.8.0
  cd ..
  ```

  Other libraries like [JSON](https://github.com/nlohmann/json) can be added as well. Note: it's highly recommended to checkout to the latest stable release of each submodule.

3. Create the DLL project:

  * In VS, create a new DLL project, whose name is the same as the desired Python module name.
  * Add the path to all submodules into additional include path:
    * Properties --> Configuration Properties --> VC++ Directories --> Include Directories
    * Add  ```$(SolutionDir)```, ```$(ProjectDir)```, ```$(SolutionDir)..\third_party\pybind11\include\pybind11``` and ```$(SolutionDir)..\third_party\eigen```.
  * Specify the output file ext to be ```pyd```:
    * Properties --> Configuration Properties --> Advanced --> Target File Extension: ```.pyd```.
  * Install the desired [Python NuGet Package](https://www.nuget.org/packages/python).
  * Add the path to Python headers into additional include path:
    * Properties --> Configuration Properties --> VC++ Directories --> Include Directories
    * Add $(ProjectDir)packages\python.3.8.10\tools\include
  * Add path to ```python3.lib``` and ```python3X.lib``` to the input of the linker:
    * Properties --> Linker --> Input --> Additional Dependencies
    * add ```$(ProjectDir)packages\python.3.8.10\tools\libs\python3.lib``` and ```$(ProjectDir)packages\python.3.8.10\tools\libs\python38.lib``` into the list, separated by ```;```.

  A few Windows specific steps:

  * If the pyd file is going to be shared, it's better to use the static version of runtime library:
    * Properties --> C/C++ --> Code Generation --> Runtime Library
    * For ```Release``` build: Multi-threaded (/MT)
    * For ```Debug``` build: Multi-threaded Debug (/MTd)
  * If the build time isn't too long, there's no need to use ```Precompiled Headers```:
    * Properties --> C/C++ --> Precompiled Headers --> Precompiled Header: ```Not Using Precompiled Headers```.
  * If Windows APIs are called, add ```WindowsApp.lib``` into the input of the linker:
    * Properties --> Linker --> Input --> Additional Dependencies: add WindowsApp.lib into the list, separated by ```;```.

## Reuse This Repo

Clone the repo:

```
git clone https://github.com/zhwa/PyCppDemo.git
cd PyCppDemo
git submodule update --init --recursive
```

Change the Python NuGet package version: start Python and check the Python version. Right click project --> Manage NuGet Packages... --> Updates --> Version.