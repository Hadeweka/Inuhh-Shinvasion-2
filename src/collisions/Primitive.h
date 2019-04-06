class Primitive {

public:

	Primitive();

};

class PrimitiveRectangle : public Primitive {

public:

	PrimitiveRectangle(double width, double height);

	double width;
	double height;

};

class PrimitiveEllipse : public Primitive {

public:

	PrimitiveEllipse(double half_width, double half_height);

	double half_width;
	double half_height;

};

class PrimitiveTriangle : public Primitive {

public:

	PrimitiveTriangle(double dx1, double dy1, double dx2, double dy2);

	double dx1;
	double dy1;
	double dx2;
	double dy2;

};