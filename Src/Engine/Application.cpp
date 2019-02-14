#include "Application.hpp"


void Application::createFramework() {

	framework = new Framework();
	framework->init();
}

void Application::destroyFramework() {

	framework->shutdown();
	delete framework;
}

Framework* Application::getFramework() {
	return framework;
}

void Application::onUpdate() {



}

int Application::mainLoop() {

	return  0;
}

/*
int Application::run() {
	

	return 0;

}

int Application::run(int argc, char* argv[]) {

	return 0;
}
*/

int Application::_run() {

	int *i = nullptr;
	//*i = 0;

	int exitCode = 0;

	createFramework();
	onStart();

	mainLoop();

	onExit();
	destroyFramework();

	return exitCode;
}

void Application::onException() {

}

int WriteMiniDump(const char* applicationName, void* exceptionPointers)
{
	return 0;
}

int Application::run(HINSTANCE hInstance_, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {

#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif


	hInstance = hInstance_;

	int exitCode = 0;

	
	__try { 
		exitCode = _run();
	} 	
	__except (WriteMiniDump("", GetExceptionInformation())) {
	} 
	
	return exitCode;
}



