#include <vector>
#include <iostream>
#include <string.h>

#include "histogram.h"
#include "text.h"
#include "svg.h"


using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count{};
    float n;
};

Input
input_data() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    Input in;
    in.numbers.resize(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cerr << "Enter number " << i+1 << ": ";
        cin >> in.numbers[i];}
    cerr << "Enter bin count: ";
    cin >> in.bin_count;

    in.n = 0;
    if (in.bin_count==0){
        in.bin_count = sqrt(number_count);
        in.n = 1;
        if (in.bin_count > 25){
            in.bin_count = 1 + log2(number_count);
            in.n = 2;}}

    return in;
}



int main()
{

    auto in = input_data();
    auto bins = make_histogram(in.numbers, in.bin_count);
    show_histogram_svg(bins);
    return 0;
}
