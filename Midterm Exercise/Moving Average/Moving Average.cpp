#include "Global.hpp"
#include "Vector_implementation.hpp" 
#include "Deque_implementation.hpp"

using namespace std;

extern deque<float> Deque::file_data;
extern vector<float> Vector::file_data;

int main(int argc, char** argv) {
	string file_location;
	cout << "File name of input file (leave empty for data.txt): ";
	std::getline(std::cin, file_location);
	if (file_location.empty()) file_location = "data.txt";

	cout << "What method should be used? (0) Performance test, (1) Use Vetor, (2) Use Deque: ";
	string tmp;
	std::getline(std::cin, tmp);
	int using_method = stoi(tmp);

	int filter_site_input = 0;
	if (using_method != 0) {
		cout << "What should be the filter size? (leave empty for whole dataset):  ";
		string tmp2;
		std::getline(std::cin, tmp2);

		if (!tmp2.empty())
			filter_site_input = stoi(tmp2);
	}

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) break;

		if (!check_change(file_location)) continue;
		
		switch (using_method)
		{
		case 0: // Performance test
		{
			cout << "First measuring Vector..." << endl << endl;

			auto measure_start = chrono::high_resolution_clock::now();
			if (!Vector::read_data(file_location, true, true)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto vector_measure_sort_steps = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();

			measure_start = chrono::high_resolution_clock::now();
			if (!Vector::read_data(file_location, true, false)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto vector_measure_sort = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();

			measure_start = chrono::high_resolution_clock::now();
			if (!Vector::read_data(file_location, false, true)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto vector_measure_steps = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();

			measure_start = chrono::high_resolution_clock::now();
			if (!Vector::read_data(file_location, false, false)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto vector_measure_raw = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();

			cout << "\n\nNow measuring Deque..." << endl << endl;

			measure_start = chrono::high_resolution_clock::now();
			if (!Deque::read_data(file_location, true)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto deque_measure_steps = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();

			measure_start = chrono::high_resolution_clock::now();
			if (!Deque::read_data(file_location, false)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
			auto deque_measure_raw = (chrono::duration<double>(chrono::high_resolution_clock::now() - measure_start)).count();


			cout << "\nResults: " << endl;
			cout << "Vector with sorting and single step calculation: " << vector_measure_sort_steps << " seconds" << endl;
			cout << "Vector with sorting: " << vector_measure_sort << " seconds" << endl;
			cout << "Vector with single step calculation: " << vector_measure_steps << " seconds" << endl;
			cout << "Vector no sort and end calculation: " << vector_measure_raw << " seconds" << endl << endl;

			cout << "Deque with single step calculation: " << deque_measure_steps << " seconds" << endl;
			cout << "Deque only end calculation: " << deque_measure_raw << " seconds" << endl;
		}
			break;

		case 1: // Using Vector
		{
			if (!Vector::read_data(file_location, false, false, filter_site_input)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
		}
			break;

		case 2: // Using Deque
		{
			if (!Deque::read_data(file_location, false, filter_site_input)) {
				cout << "\nFile not found!" << endl;
				return EXIT_FAILURE;
			}
		}
			break;

		default:
			cout << "Invalid input! Terminating..." << endl;
			return EXIT_FAILURE;
			break;
		}

		cout << "\nJust update the file to update the data.\n\nPress SPACE to exit!\n";
	}

	return EXIT_SUCCESS;
}