#include "text.h"
#include <math.h>

using namespace std;

void
show_histogram_text(vector<size_t>& bins, size_t bin_count, float n){
    if (n != 0){
        cout << "bin count = " << bin_count;
        if (n == 1)
            cout << " using 1st" << '\n';
        else
            cout << " using 2nd" << '\n';}
    for (size_t i = 0; i < bin_count; i++) {
        if (bins[i]<100)
            cout << " ";
        if (bins[i]<10)
            cout << " ";
        cout << bins[i] << "|";
        for (size_t j = 0; j < bins[i]; j++){
            cout << "*";}
        cout << '\n';}
}
