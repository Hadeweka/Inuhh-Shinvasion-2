#pragma once

class Tile {

public:

	Tile() = default;
	~Tile() = default;

	bool is_solid();
	bool is_animation_frame();

	void set_as_solid();

	unsigned int get_animation_frame(unsigned int frame_counter);

	void set_animation(unsigned int index_of_first_animation_frame,
		unsigned int index_of_first_other_animation_frame,
		unsigned int number_of_animation_frames,
		unsigned int time_per_animation_frame);

private:

	bool solid = false;
	bool animation_frame = false;

	unsigned int index_of_first_animation_frame;
	unsigned int index_of_first_other_animation_frame;
	unsigned int number_of_animation_frames;
	unsigned int time_per_animation_frame;

};