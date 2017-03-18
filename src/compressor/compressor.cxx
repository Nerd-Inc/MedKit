
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <limits>
#include <exception>

using namespace std;
using COMPRESSOR = uint16_t;

namespace MEDKIT {
    const COMPRESSOR dictionary_max_size {
        numeric_limits <COMPRESSOR>::max()
    };
}
// Usage Information
void print_usage(const string &custom_error = "", bool show_usage_info = true)
{
    if (!custom_error.empty())
        cout << "\n ERROR: " << custom_error << endl;

    if (show_usage_info)
    {
        cout << "\n Usage:" <<endl;
        cout << "\t program -flag input output" <<endl;
        cout << "Flags: -c compress -d decompress" <<endl;
        cout << "Examples: " <<endl;
        cout << "\t ./compressor -c sample_file.txt output_file.grimm" <<endl;
        cout << "\t ./compressor -d output_file.grimm sample_file.txt" <<endl;
    }

    cout << endl;
}

vector<char> operator + (vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}

// Compressor.
void compress(istream &is, ostream &os)
{
    map<vector<char>, COMPRESSOR> dictionary;
    const auto dict_reset = [&dictionary] {
        dictionary.clear();

        const long int minc = numeric_limits<char>::min();
        const long int maxc = numeric_limits<char>::max();

        for (long int c = minc; c <= maxc; ++c)
        {
            const COMPRESSOR dictionary_size = dictionary.size();

            dictionary[{static_cast<char> (c)}] = dictionary_size;
        }
    };

        dict_reset();

    vector<char> s; 
    char c;

    while (is.get(c))
    {
        if (dictionary.size() == MEDKIT::dictionary_max_size)
            dict_reset();

        s.push_back(c);

        if (dictionary.count(s) == 0){
            const COMPRESSOR dictionary_size = dictionary.size();

            dictionary[s] = dictionary_size;
            s.pop_back();
            os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (COMPRESSOR));
            s = {c};
        }
    }

    if (!s.empty())
        os.write(reinterpret_cast<const char *> (&dictionary.at(s)), sizeof (COMPRESSOR));
}

// Decompress
void decompress(istream &is, ostream &os){
    vector<vector<char> > dictionary;
    const auto dict_reset = [&dictionary] {
        dictionary.clear();
        dictionary.reserve(MEDKIT::dictionary_max_size);

        const long int minc = numeric_limits<char>::min();
        const long int maxc = numeric_limits<char>::max();

        for (long int c = minc; c <= maxc; ++c)
            dictionary.push_back({static_cast<char> (c)});
    };

    dict_reset();
    vector<char> s; 
    COMPRESSOR k; // code key

    while (is.read(reinterpret_cast<char *> (&k), sizeof (COMPRESSOR))){
        if (dictionary.size() == MEDKIT::dictionary_max_size)
            dict_reset();

        if (k > dictionary.size())
            throw runtime_error("Invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else
        if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        os.write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw runtime_error("corrupted compressed file");
}

// return EXIT_FAILURE    failed
// return EXIT_SUCCESS    success
int main(int argc, char *argv[]){   
    if (argc != 4) {
        print_usage("Wrong number of arguments.");
        return EXIT_FAILURE;
    }

    enum class Flag {
        Compress,
        Decompress
    };
    Flag flag_state;

    if (string(argv[1]) == "-c")
        flag_state = Flag::Compress;
        
    else if (string(argv[1]) == "-d")
        flag_state = Flag::Decompress;
    else {
        print_usage(string("flag `") + argv[1] + "` is not recognized.");
        return EXIT_FAILURE;
    }

    ifstream input_file(argv[2], ios_base::binary);
    if (!input_file){
        print_usage(string("the file `") + argv[2] + "` could not be opened for input.");
        return EXIT_FAILURE;
    }

    ofstream output_file(argv[3], ios_base::binary);
    if (!output_file.is_open()) {
        print_usage(string("the file `") + argv[3] + "` could not be opened for output.");
        return EXIT_FAILURE;
    }
    try {
        input_file.exceptions(ios_base::badbit);
        output_file.exceptions(ios_base::badbit | ios_base::failbit);

        if (flag_state == Flag::Compress)
            compress(input_file, output_file);
        else
        if (flag_state == Flag::Decompress)
            decompress(input_file, output_file);
    }
    catch (const ios_base::failure &f) {
        print_usage(string("File input/output failure: ") + f.what() + '.', false);
        return EXIT_FAILURE;
    }
    catch (const exception &e) {
        print_usage(string("Caught exception: ") + e.what() + '.', false);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
