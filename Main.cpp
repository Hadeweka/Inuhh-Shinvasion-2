#include "Main.h"

using namespace std;

int main() {
	auto mrb = RubyWrapper();
	mrb.exec("class Test;def initialize(arg); puts arg; end; end");
	mrb.exec("Test.new('This is a test')");

	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Inuhh Shinvasion 2");
	window->setVerticalSyncEnabled(true);

	while (window->isOpen()) {
		window->clear();
		window->display();
	}

	return 0;
}
