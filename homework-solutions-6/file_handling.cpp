// g++ -std=c++14 file_handling.cpp
#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using namespace std;

class File {
    shared_ptr<FILE> file;
    public:
        // pass a name and the deleter function to the initiator
        File(const string& name, void (*deleter)(FILE*)) {
            FILE* rawFile = fopen(name.c_str(), "w");
            if (!rawFile) {
                throw runtime_error("Failed to open file");
            }
            file = shared_ptr<FILE>(rawFile, deleter);
            cout << "File created: " << name.c_str() << endl;
        }

        ~File() {
            cout << "File object is being destroyed." << endl;
            // No need to close the file explicitly here
            // shared_ptr will call deleteFile automatically
        }
};


void deleteFile(FILE* file) {
    std::cout << "Closing file" << std::endl;
    fclose(file);
};

int main() {
    // Wrap the temporary shared_ptr with another shared_ptr that uses a custom deleter
    auto f = File("new_file.txt", deleteFile);


    /*
        When we make f2 own the object as well,
        we can see the object destructor method is being called twice, once for each instance of the object,
        yet the deleteFile function which is triggered when the file pointer is truly released only runs once.

        This is because deleteFile only happens once when all the instances of the object File are deleted
        bc its a smart pointer.
    */
    auto f2 = f;

    return 0;
}
