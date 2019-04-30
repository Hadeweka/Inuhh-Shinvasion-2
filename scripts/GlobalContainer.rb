class GlobalContainer

	def initialize
		@values = {}		
	end

	def add(subclass, element, index = nil)
		if !@values[subclass] then
			@values[subclass] = [element]
		else
			if index then
				@values[subclass][index] = element
			else
				@values[subclass].push(element)
			end
		end

		return @values[subclass].size
	end

	def get_all(subclass)
		return @values[subclass]
	end

	def get(subclass, index)
		if !@values[subclass] then
			return nil
		else
			return @values[subclass][index]
		end
	end

	def size(subclass)
		return @values[subclass].size
	end

end
