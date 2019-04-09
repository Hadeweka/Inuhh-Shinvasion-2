#include "Primitive.h"
#include <vector>
#include <mruby.h>
#include <mruby/dump.h>

enum class ShapeType {
	NONE = 0,		//! No shape type assigned
	HITBOX,		//! A shape which may damage others
	HURTBOX,	//! A shape which may damage the owning entity
	INERT		//! A shape which triggers collisions, but does nothing else
};

class Shape {

public:

	Shape(ShapeType shape_type = ShapeType::NONE, unsigned int reserve_size = 5);

	void add_primitive(Primitive&& primitive);

	Primitive& get_primitive(unsigned int main_index);
	ShapeType get_shape_type();

private:

	std::vector<Primitive> primitives;
	ShapeType shape_type;

};
