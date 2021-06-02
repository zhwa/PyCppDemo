# PyCppDemo

## Preparation

1. Set up the git repo.
2. Add essential submodules: put all 3rd party libraries in a folder, and manage them with ```git submoudle```.

  ```
  cd third_party\eigen
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

  Other libraries can be added as well.