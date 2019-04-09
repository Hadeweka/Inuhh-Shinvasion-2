#include "Shape.h"

Shape::Shape(ShapeType shape_type, unsigned int reserve_size) {

	this->shape_type = shape_type;
	primitives.reserve(reserve_size);

}

void Shape::add_primitive(Primitive&& primitive) {

	primitives.push_back(std::move(primitive));

}

Primitive& Shape::get_primitive(unsigned int main_index) {

	return primitives[main_index];

}

ShapeType Shape::get_shape_type() {

	return shape_type;

}
