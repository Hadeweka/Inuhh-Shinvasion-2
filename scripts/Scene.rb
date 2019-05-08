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
	end

	def main_update
		update

		# The frequency of the Garbage Collector may be subject to change
		GC.start
	end

	def main_draw
		$window.clear
		draw
		$window.display
	end

	# Change these at will if inherited

	def at_init

	end

	def at_exit

	end

	def update
		
	end

	def draw

	end

	def process_events

	end

end