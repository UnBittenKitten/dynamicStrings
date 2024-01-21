#include <iostream>
#include <string.h>

#define MAXSIZE 20 
using namespace std;

class dynStr {
    private: 
        char** str;
        int lfe;
        int limit;

    public:
        dynStr() {
            str = (char**)malloc(sizeof(char*));
            *str = (char*)malloc(sizeof(char)*MAXSIZE);
            lfe = 0;
            limit = MAXSIZE;
        }

        void del() {
            free(*str);
            free(str);
        }

        void add(string newstr) {
            if(newstr.length() + 1 > limit - lfe - 1) {
                //cout << "INCREASING SIZE" << endl;
                limit *= 2;
                str = (char**)realloc(str, limit);
            }

            int i = 0;
            while(i < newstr.length()) {
                //cout << "adding " << newstr[i] << endl;
                *(*str + lfe) = newstr[i];
                lfe++;
                i++;
            }
            *(*str + lfe) = 0;
        }

        void print(bool printendl) {
            cout << *str;
            if(printendl) {
                cout << endl;
            }
        }


};

int main(int argc, char* argv[]) {
    dynStr test;
    test.add("apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.add(" apoco si tilin");
    test.print(1);
    test.del();

    
    
    
    return 0;
}