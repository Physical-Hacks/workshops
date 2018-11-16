#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

class Vector2 {
public:
  Vector2(float x, float y) : x(x), y(y) { }

  Vector2 operator+(const Vector2 &v) const { return Vector2(x + v.x, y + v.y); }
  Vector2 operator*(float value) const { return Vector2(x * value, y * value); }
  Vector2& operator+=(const Vector2 &v) { x += v.x; y += v.y; return *this; }
  Vector2& operator*=(float v) { x *= v; y *= v; return *this; }

  friend Vector2 operator*(float f, const Vector2 &v) {
    return Vector2(f * v.x, f * v.y);
  }

  std::string toString() const {
    return "[" + std::to_string(x) + ", " + std::to_string(y) + "]";
  }
private:
  float x, y;
};


namespace py = pybind11;

PYBIND11_MODULE(testVector2, m) {
  m.doc() = "pybind11 wrapper for Vector2 class";

  py::class_<Vector2>(m, "Vector2")
    .def(py::init<float, float>())
    .def(py::self + py::self)
    .def(py::self += py::self)
    .def(py::self *= float())
    .def(float() * py::self)
    .def(py::self * float())
    .def("__repr__", &Vector2::toString);
}
