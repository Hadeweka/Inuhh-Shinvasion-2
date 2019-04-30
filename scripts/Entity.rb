class Entity

	@@boxes = GlobalContainer.new
	
	def self.add_box(box, index: nil)
		@@boxes.add(self, box, index)
	end

	def initialize(x, y)
		@x = x
		@y = y

		load_boxes
	end

	# Create local copies of all boxes
	def load_boxes
		@boxes = []
		subclass = self.class

		0.upto(@@boxes.size(subclass) - 1) do |i|
			element = @@boxes.get(subclass, i)
			@boxes[i] = element.dup if element
		end
	end

end

class TestEntity < Entity

	add_box("Hello")
	add_box("Bla", index: 2)

	def initialize(x, y)
		super(x, y)
		puts "Value = " + @boxes.inspect
	end

end

TestEntity.new(3, 3)