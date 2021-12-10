#define OLC_PGE_APPLICATION
#include <iostream>
#include "Headers/olcPixelGameEngine.h"

class PGE001 : public olc::PixelGameEngine {
public:
	PGE001() {
		// TODO:I really need to change this at somepoint
		sAppName = "PGE1";
	};
public:
	// On Start
	bool OnUserCreate() override {
		return true;
	};
	// On Every Frame
	bool OnUserUpdate(float fTime) override {
		// Generates a colourful static image
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 63-25+1, rand() % 256, rand() % 256));

		return true;
	}
};

int main() {
	// Create an instance of PGE
	PGE001 app;
	// Width, Height, Scale X, Scale Y
	if (app.Construct(256, 240, 4, 4))
		app.Start();
	else{
		// Literally here to catch in the case of the game engine not being able to start.
		std::cout << "Error Starting PGE";
		// Need to figure out the OS Agnostic version of this.
		system("pause");
	}
};