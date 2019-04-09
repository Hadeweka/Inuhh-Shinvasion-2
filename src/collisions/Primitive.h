enum class PrimitiveType {
	DUMMY = 0,
	RECTANGLE,
	ELLIPSE,
	TRIANGLE
};

class Primitive {

public:

	Primitive(PrimitiveType type, double param_1 = 0.0, double param_2 = 0.0, double param_3 = 0.0, double param_4 = 0.0);

	PrimitiveType get_type();
	
	double& width();
	double& height();

	double& half_width();
	double& half_height();

	double& dx1();
	double& dy1();
	double& dx2();
	double& dy2();

private:

	PrimitiveType type;

	double param_1;
	double param_2;
	double param_3;
	double param_4;

};
