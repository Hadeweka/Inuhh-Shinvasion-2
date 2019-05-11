class TestEntity < Entity

	attr_reader :boxes

	add_box("Hello")
	add_box("Bla", index: 2)

	def initialize
		super
	end

end

class Scene

	# Methods for internal stuff, don't change these if inherited

	def initialize
		at_init
		@sprites = []
	end

	def main_update
		update
	end

	def main_draw
		$window.clear
		draw
		$window.display
	end

	# Change these at will if inherited

	def at_init
		@c = ResourceManager.new
	end

	def at_exit

	end

	def update
		@c.test
		@c.test2
		#c.position = Coordinates.new(3, 2)
		#puts c.position.inspect
	end

	def draw

	end

	def process_events

	end

end