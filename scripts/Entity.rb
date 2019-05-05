class Entity < CoreEntity

	@@boxes = GlobalContainer.new
	@@shapes = GlobalContainer.new
	@@textures = GlobalContainer.new
	
	def self.add_box(box, index: nil)
		@@boxes.add(self, box, index)
	end

	def self.add_shape(shape, index: nil)
		@@shapes.add(self, shape, index)
	end

	def self.add_texture(texture, index: nil)
		@@textures.add(self, texture, index)
	end

	def initialize
		super	# Call the CoreEntity super method to initialize the underlying C++ structure

		load_boxes
		load_shapes
		load_textures
	end

	# Create local copies of all boxes/shapes/...

	def load_boxes
		@boxes = []
		subclass = self.class

		0.upto(@@boxes.size(subclass) - 1) do |i|
			element = @@boxes.get(subclass, i)
			@boxes[i] = element.dup if element
		end
	end

	def load_shapes
		@shapes = []
		subclass = self.class

		0.upto(@@shapes.size(subclass) - 1) do |i|
			element = @@shapes.get(subclass, i)
			@shapes[i] = element.dup if element
		end
	end

	def load_textures
		@textures = []
		subclass = self.class

		0.upto(@@textures.size(subclass) - 1) do |i|
			element = @@textures.get(subclass, i)
			@textures[i] = element.dup if element
		end
	end

end

class TestEntity < Entity

	attr_reader :boxes

	add_box("Hello")
	add_box("Bla", index: 2)

	def initialize
		super
	end

end

a = TestEntity.new
b = TestEntity.new

a.boxes[2] = "New Test"

puts a.boxes
puts b.boxes