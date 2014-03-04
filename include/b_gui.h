//battle gui
#ifndef b_gui
#define b_gui
#include <shaders.h>
#include <glfw/glfw3>
#include <cairo.h> //include the cairo header

class b_gui
{
	public
		b_gui(opperating environment,otherstuff idk whatelse); //constructor
		void init(); //load window init render context etc
		void unit(position as in place1 etc, image location, task);//task as in create or attack animation, defend animation etc
		void 