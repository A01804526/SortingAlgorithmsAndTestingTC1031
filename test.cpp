#include "algorithms.hpp"

void time_the_algorithm(vector<int>& a) {
    auto start = std::chrono::high_resolution_clock::now();
    ALGORITHMTOTEST(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    cout << total_time << ","; 
}

stringstream algorithm_time_to_ss(vector<int>& a) {
    stringstream res;
    auto start = std::chrono::high_resolution_clock::now();
    ALGORITHMTOTEST(a);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    res << total_time << ","; 
    return res;
}


int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    cout << PRINTALG(ALGORITHMTOTEST) << endl;
    stringstream un;
    stringstream in;
    stringstream de;
    // allows for visual check to see if the test is valid.
    stringstream verif0;
    stringstream verif1;
    vector<int> a(10);
    vector<int> b(50);
    vector<int> c(100);
    vector<int> d(247);
    vector<int> e(500);
    vector<int> f(100000);

    // random vectors random vectors random vectors random vectors random vectors random vectors
    /*
    fill_random(a,MAXNUMBERINVECS);
    fill_random(b,MAXNUMBERINVECS);
    fill_random(c,MAXNUMBERINVECS);
    fill_random(d,MAXNUMBERINVECS);
    fill_random(e,MAXNUMBERINVECS);
    fill_random(f,MAXNUMBERINVECS);
    
    verif0  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());

    cout << "u,";
    time_the_algorithm(a);
    time_the_algorithm(b);
    time_the_algorithm(c);
    time_the_algorithm(d);
    time_the_algorithm(e);
    time_the_algorithm(f);
    cout << "\n";

    verif1  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());
        */
    // increasing vectors increasing vectors increasing vectors increasing vectors increasing vectors
    fill_incremental(a,MAXNUMBERINVECS);
    fill_incremental(b,MAXNUMBERINVECS);
    fill_incremental(c,MAXNUMBERINVECS);
    fill_incremental(d,MAXNUMBERINVECS);
    fill_incremental(e,MAXNUMBERINVECS);
    fill_incremental(f,MAXNUMBERINVECS);
    
    verif0  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());
            
    cout << "i,";
    time_the_algorithm(a);
    time_the_algorithm(b);
    time_the_algorithm(c);
    time_the_algorithm(d);
    time_the_algorithm(e);
    time_the_algorithm(f);
    cout << "\n";

    verif1  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());

    // decremental vectors decremental vectors decremental vectors decremental vectors decremental vectors
    fill_decremental(a,MAXNUMBERINVECS);
    fill_decremental(b,MAXNUMBERINVECS);
    fill_decremental(c,MAXNUMBERINVECS);
    fill_decremental(d,MAXNUMBERINVECS);
    fill_decremental(e,MAXNUMBERINVECS);
    fill_decremental(f,MAXNUMBERINVECS);
    
    verif0  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());
            
    cout << "d,";
    time_the_algorithm(a);
    time_the_algorithm(b);
    time_the_algorithm(c);
    time_the_algorithm(d);
    time_the_algorithm(e);
    time_the_algorithm(f);
    cout << "\n";

    verif1  << is_sorted(a.begin(),a.end()) 
            << is_sorted(b.begin(),b.end())
            << is_sorted(c.begin(),c.end())
            << is_sorted(d.begin(),d.end())
            << is_sorted(e.begin(),e.end())
            << is_sorted(f.begin(),f.end());

    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    double total_time = duration.count() / 1'000'000.0;
    cout <<"time_whole_test,"<<total_time<< "\n";
    cout << verif0.str() << "\n" << verif1.str() << endl;
}