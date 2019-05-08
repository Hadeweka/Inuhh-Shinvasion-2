begin

	$window = Window.new('Inuhh Shinvasion 2', 800, 600)
	$window.enable_vertical_sync

	$scene = Scene.new

	while $window.is_open? do
		$scene.main_draw
		$scene.process_events
		$scene.main_update
	end

	$window.close

rescue Exception => exc

	f = File.open("log.txt", "a")

	f.puts "Error in main loop at #{Time.now}:"
	f.puts exc.inspect
	f.puts ""

	f.close

	puts exc.inspect

	raise exc

end