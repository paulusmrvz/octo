#include "core/window.h"
#include "core/device.h"

#include <iostream>

int main() {
	try {
		std::shared_ptr<Octo::Window> pWin{};
		Octo::Device device{pWin};

		while (!pWin->IsShouldClose()) {
			pWin->GetInput();
			pWin->PollEvents();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}

	return 0;
}