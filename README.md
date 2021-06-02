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
  git checkout 3.4-rc1
  cd ..
  ```

  * [Eigen](https://gitlab.com/libeigen/eigen)
  ```
  git submodule add https://github.com/pybind/pybind11.git pybind11
  cd pybind11
  git checkout v2.6.2
  cd ..
  ```

  Other libraries like [JSON](https://github.com/nlohmann/json) can be added as well. Note: it's highly recommended to checkout to the latest stable release of each submodule.

3. Create the DLL project:

  * In VS, create a new DLL project, whose name is the same as the desired Python module name.
  * Add the path to all submodules into additional include path.
  * Specify the output file ext to be ```pyd```.
  * Install the desired [Python NuGet Package](https://www.nuget.org/packages/python).
  * Add the path to Python headers into additional include path.
  * Add path to ```python3.lib``` and ```python3X.lib``` to the input of the linker.