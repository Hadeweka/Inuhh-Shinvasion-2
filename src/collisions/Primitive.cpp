#include "Primitive.h"

Primitive::Primitive(PrimitiveType type, double param_1, double param_2, double param_3, double param_4) {

	this->type = type;

	this->param_1 = param_1;
	this->param_2 = param_2;
	this->param_3 = param_3;
	this->param_4 = param_4;

}

PrimitiveType Primitive::get_type() { return type; }

double& Primitive::width() { return param_1; }
double& Primitive::height() { return param_2; }

double& Primitive::half_width() { return param_1; }
double& Primitive::half_height() { return param_2; }

double& Primitive::dx1() { return param_1; }
double& Primitive::dy1() { return param_2; }
double& Primitive::dx2() { return param_3; }
double& Primitive::dy2() { return param_4; }