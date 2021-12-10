#define OLC_PGE_APPLICATION
#include <iostream>
#include "olcPixelGameEngine.h"

class PGE001 : public olc::PixelGameEngine {
public:
	PGE001() {
		sAppName = "PGE1";
	};
public:
	bool OnUserCreate() override {
		return true;
	};

	bool OnUserUpdate(float fTime) override {
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

		return true;
	}
};

int main() {
	PGE001 app;

	if (app.Construct(256, 240, 2, 2))
		app.Start();
	else{
		std::cout << "Error Starting PGE";
		system("pause");
	}
};