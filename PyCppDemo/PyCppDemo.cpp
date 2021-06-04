#include "pch.h"
#include "MyModule.h"

namespace py = pybind11;

PYBIND11_MODULE(PyCppDemo, m)
{
	m.def("square", &square, "Given a list of float numbers, return a list of float numbers in which each input element is squared.");
}