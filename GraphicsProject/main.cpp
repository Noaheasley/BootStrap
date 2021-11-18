#include "Engine.h"
#include "BuddhaWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Graphics");

	BuddhaWorld* world = new BuddhaWorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}