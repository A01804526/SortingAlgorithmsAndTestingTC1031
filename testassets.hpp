#include "includes.hpp"
// preprocessor function to print the algorithm used
#define EXPANDALG(x) #x
#define PRINTALG(c) EXPANDALG(c)

// as provided in the site (vector generators)
void fill_random(std::vector<int>& values, int max_value) {
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}
void fill_incremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}
void fill_decremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = values.size() - 1; i >= 0; --i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}
// as seen in class (20 oct 2026)
void print_vector(vector<int>& v) { //const
    for (int x : v){
        cout << x << " ";
    } cout << "\n";
}