To run:
* Download the code into a folder
* Open a terminal in said folder
* Compile using g++: g++ main.cpp -o ./executablefile
* Run: ./executablefile

In settings.hpp you can select the algorithm to test by typing its name in the ALGORITHMTOTEST macro.
You can change the sizes of the tests from main or test. They both do the same, but they let you test two different batches of sizes at a time. I used test to make sure everything works as intended, and main for the actual time consuming tests.
