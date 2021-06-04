#include "pch.h"
#include "MyModule.h"

namespace py = pybind11;

PYBIND11_MODULE(PyCppDemo, m)
{
	m.def("square", &square, "Given a list of float numbers, return a list of float numbers in which each input element is squared.");
	m.def("unique", &unique, "Find the unique elements from the given list");
	m.def("counter", &counter, "Counts of each unique element in the given list");
	m.def("char_count", &char_count, "Char count in the given string");
	m.def("inv", &inv, "Inverse a given 2-d matrix.");
	m.def("det", &det, "Det of a given matrix");
}