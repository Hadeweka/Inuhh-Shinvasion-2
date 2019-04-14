#include "Main.h"
#include <mruby/variable.h>
#include <mruby/data.h>

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



static void free_primitive(mrb_state* mrb, void* p_) {
	reinterpret_cast<Primitive*>(p_)->~Primitive();
}

static mrb_value ruby_primitive_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable(mrb, self, "@prim", "primitive", new Primitive(PrimitiveType::ELLIPSE));

	std::cout << "init works!" << std::endl;

	return self;

}

static mrb_value ruby_primitive_test(mrb_state* mrb, mrb_value self) {

	auto type = DATA_TYPE(mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@prim")));

	Primitive* primitive;
	Data_Get_Struct(mrb, mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@prim")), type, primitive);

	std::cout << "Type: " << static_cast<unsigned int>(primitive->get_type()) << std::endl;

	return mrb_nil_value();

}




int main() {

	auto mrb = mrb_open();

	mrb_load_string(mrb, "class Test;def initialize(arg); puts arg; end; end");
	mrb_load_string(mrb, "Test.new('This is a test')");

	test(mrb);

	mrb_example_gem_init(mrb);
	mrb_load_string(mrb, "example_method");



	auto ruby_primitive_class = mrb_define_class(mrb, "Primitive", mrb->object_class);

	mrb_define_method(mrb, ruby_primitive_class, "initialize", ruby_primitive_init, MRB_ARGS_REQ(0));
	mrb_define_method(mrb, ruby_primitive_class, "test", ruby_primitive_test, MRB_ARGS_REQ(0));

	mrb_load_string(mrb, "p = Primitive.new;p.test");

	if (mrb->exc) mrb_print_error(mrb);
	


	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Inuhh Shinvasion 2");
	window->setVerticalSyncEnabled(true);

	while (window->isOpen()) {
		window->clear();
		window->display();
	}

	mrb_close(mrb);

	return 0;

}
