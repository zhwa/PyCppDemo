#pragma once

// pybind11
#include <pybind11.h>
#include <stl.h>
#include <stl_bind.h>
#include <numpy.h>
#include <eigen.h>
#include <functional.h>
#include <complex>

//Eigen
#include <Eigen/Core>
#include <Eigen/Geometry>

// RowMajor matrix can be directly cast to numpy array. Ref: https://pybind11.readthedocs.io/en/stable/advanced/cast/eigen.html#storage-orders.
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> EigenMatrix;