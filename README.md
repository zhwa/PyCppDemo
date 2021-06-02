# PyCppDemo

## Preparation

1. Set up the git repo
2. Add essential submodules:

  * [Pybind11](https://github.com/pybind/pybind11)
  ```
  git submodule add https://gitlab.com/libeigen/eigen.git third_party\eigen
  cd third_party\eigen
  git checkout 3.4-rc1
  ```

  * [Eigen](https://gitlab.com/libeigen/eigen)
  ```
  git submodule add https://github.com/pybind/pybind11.git third_party\pybind11
  cd third_party\pybind11
  git checkout v2.6.2
  ```

