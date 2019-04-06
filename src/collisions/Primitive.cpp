#include "Primitive.h"

Primitive::Primitive() {

}

PrimitiveRectangle::PrimitiveRectangle(double width, double height) {

	this->width = width;
	this->height = height;

}

PrimitiveEllipse::PrimitiveEllipse(double half_width, double half_height) {

	this->half_width = half_width;
	this->half_height = half_height;

}

PrimitiveTriangle::PrimitiveTriangle(double dx1, double dy1, double dx2, double dy2) {

	this->dx1 = dx1;
	this->dy1 = dy1;
	this->dx2 = dx2;
	this->dy2 = dy2;

}