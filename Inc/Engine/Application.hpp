#pragma once

#include "Common.hpp"

#include "Window.hpp"
#include "Framework.hpp"


enum ApplicationState {
	APPLICATION_UNINITIALIZED,
	APPLICATION_WORKING,
	APPLICATION_CLOSED
};


class Application {

	ApplicationState state;

	Framework* framework;

	void createFramework();
	void destroyFramework();
	int _run();

	void onException();

protected:

	Framework* getFramework();
	

	virtual void onStart() {}
	virtual void onExit() {}
	virtual void onUpdate();
	virtual void onRefresh() {}

	virtual int mainLoop();

	HINSTANCE hInstance;
	HINSTANCE hPrevInstance; 
	LPTSTR lpCmdLine;
	int nCmdShow;

public:
	
	Application() : framework(nullptr) {}

	bool isClosed() const { return state == APPLICATION_CLOSED; }

	//int run();
	//int run(int argc, char* argv[]);
	int run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);

};

