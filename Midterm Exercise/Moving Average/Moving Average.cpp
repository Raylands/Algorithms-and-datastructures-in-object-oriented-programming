#include "Filehandling.hpp"

using namespace std;

int main(int argc, char** argv) {
	string file_location;
	cout << "File name of input file (leave empty for data.txt): ";
	std::getline(std::cin, file_location);
	if (file_location.empty()) file_location = "data.txt";

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) break;

		if (!check_change(file_location)) continue;
		if (!read_data(file_location)) {
			cout << "\nFile not found!" << endl;
			return EXIT_FAILURE;
		}

		cout << "\nJust update the file to update the data.\n\nPress SPACE to exit!\n";
	}

	return EXIT_SUCCESS;
}