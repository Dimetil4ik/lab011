#include "svg.h"
#include "histogram.h"
#include <math.h>


using namespace std;

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text){
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill){
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width * 3 << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

void
show_histogram_svg(const vector<size_t>& bins) {
    double max_count;
    max_count = bins[0];
    for (double x : bins) {
        if (x > max_count) {
            max_count = x;
        }
    }
    //10 - (bin * 9) / max_count
    string fill;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(400, 300);
    double top = 0;
    for (size_t bin : bins) {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        fill = "#" + to_string(int(10 - (bin * 9) / max_count))+ to_string(int(10 - (bin * 9) / max_count))+ to_string(int(10 - (bin * 9) / max_count));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red", fill);
        top += BIN_HEIGHT;
}
    svg_end();
}
