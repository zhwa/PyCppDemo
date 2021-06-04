#include "pch.h"
#include "MyModule.h"

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<Fraction>);

PYBIND11_MODULE(PyCppDemo, m)
{
	m.def("square", &square, "Given a list of float numbers, return a list of float numbers in which each input element is squared.");
	m.def("unique", &unique, "Find the unique elements from the given list");
	m.def("counter", &counter, "Counts of each unique element in the given list");
	m.def("char_count", &char_count, "Char count in the given string");
	m.def("inv", &inv, "Inverse a given 2-d matrix.");
	m.def("det", &det, "Det of a given matrix");

	py::class_<Fraction>(m, "Fraction")
		.def(py::init<double, double>())
		.def("mul", &Fraction::mul, "Multiply the faction by given value.")
		.def("__repr__", [](const Fraction& f) { return f.str(); })
		.def("print", &Fraction::print);

	// Opaque example: https://pybind11.readthedocs.io/en/stable/advanced/cast/stl.html#making-opaque-types.
	py::class_<std::vector<Fraction>>(m, "FractionList")
		.def(py::init<>())
		.def("clear", &std::vector<Fraction>::clear)
		.def("pop_back", &std::vector<Fraction>::pop_back)
		.def("append", (void(std::vector<Fraction>::*)(const Fraction&)) &std::vector<Fraction>::push_back)
		.def("__getitem__", (Fraction&(std::vector<Fraction>::*)(size_t)) &std::vector<Fraction>::at, py::return_value_policy::reference_internal)
		.def("__len__", [](const std::vector<Fraction>& v) { return v.size(); })
		.def("__iter__", [](std::vector<Fraction>& v) { return py::make_iterator(v.begin(), v.end()); }, py::keep_alive<0, 1>());

	m.def("mul_fraction", &mul_fraction, "Multiply each faction in the list");
}