#include "Main.h"

using namespace std;

static mrb_value mrb_greet(mrb_state* mrb, mrb_value self) {
	printf("Hello, mrubyyyy!\n");
	return mrb_nil_value();
}

int main()
{
	mrb_state *mrb = mrb_open();

	mrb_define_method(mrb, mrb->object_class, "greet!", mrb_greet, MRB_ARGS_NONE());

	char code[] = "greet!";

	mrb_load_string(mrb, code);
	return 0;
}
