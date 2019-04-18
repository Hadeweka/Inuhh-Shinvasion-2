#INCLUDE_AS_C

class Scene

	# Methods for internal stuff, don't change these if inherited

	def initialize

	end

	def main_update
		$game.update
		update
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