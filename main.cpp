#include <vector>
#include <iostream>
#include <string.h>

#include "histogram.h"
#include "text.h"
#include "svg.h"
#include "Header.h"

//using namespace std;

struct Input {
    std::vector<double> numbers;
    size_t bin_count{};
    
};

Input
input_data() {
    using std::cerr;
    using std::cin;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    Input in;
    in.numbers.resize(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cerr << "Enter number " << i + 1 << ": ";
        cin >> in.numbers[i];
    }
    cerr << "Enter bin count: ";
    cin >> in.bin_count;


    return in;
}



int main()
{

    auto in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}
