#include "Main.h"

//! Test 1

void test(mrb_state* mrb) {

	MrbWrap::execute_bytecode_file(mrb, "scripts/test.mrb");

}

mrb_value example_method(mrb_state* mrb, mrb_value self)
{
	puts("Executing example command!");
	return self;
}

void mrb_example_gem_init(mrb_state* mrb)
{
	mrb_define_method(mrb, mrb->kernel_module, "example_method", example_method, MRB_ARGS_NONE());
}

//! Test 2

static mrb_value ruby_primitive_init(mrb_state* mrb, mrb_value self) {

	int primitive_type;

	mrb_get_args(mrb, "i", &primitive_type);

	MrbWrap::convert_to_instance_variable<Primitive>(mrb, self, "@prim", "primitive", static_cast<PrimitiveType>(primitive_type));

	std::cout << "init works!" << std::endl;

	return self;

}

static mrb_value ruby_primitive_test(mrb_state* mrb, mrb_value self) {

	auto primitive = MrbWrap::convert_from_instance_variable<Primitive>(mrb, self, "@prim");

	std::cout << "Type: " << static_cast<unsigned int>(primitive->get_type()) << std::endl;

	return mrb_nil_value();

}

//! Actual main method

int main() {

	auto mrb = mrb_open();

	//! Test 1

	MrbWrap::execute_string(mrb, "class Test;def initialize(arg); puts arg; end; end");
	MrbWrap::execute_string(mrb, "Test.new('This is a test')");

	test(mrb);

	mrb_example_gem_init(mrb);
	MrbWrap::execute_string(mrb, "example_method");

	//! Test 2

	auto ruby_primitive_class = mrb_define_class(mrb, "Primitive", mrb->object_class);

	mrb_define_method(mrb, ruby_primitive_class, "initialize", ruby_primitive_init, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, ruby_primitive_class, "test", ruby_primitive_test, MRB_ARGS_REQ(0));

	MrbWrap::execute_string(mrb, "p = Primitive.new(1);p.test");
	MrbWrap::execute_string(mrb, "q = Primitive.new(2);q.test");

	if (mrb->exc) mrb_print_error(mrb);
	
	//! Actual code

	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Inuhh Shinvasion 2");
	window->setVerticalSyncEnabled(true);

	while (window->isOpen()) {
		window->clear();
		window->display();
	}

	mrb_close(mrb);

	return 0;

}
