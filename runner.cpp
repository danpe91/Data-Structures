#include <iostream>
#include <cstdlib>

using namespace std;
int main(int a, char * ar[]) {
    
    cout << a << endl;
    int i;
    i = ar[1][0] == '1' ? 1 : ar[1][0] == '2' ? 2 : 0;
    string name[] = {"breadt_first_search", "depth_first_search", "depth_first_search_recursive"};
    string commands[] = { "input_aristas", "input_aristas2", "input_aristas3", "input_aristas4", "input_aristas5", "input_aristas6", "input_aristas7", "input_aristas8"};
    
    for (int j = 0; j < 8; ++j)
    {
        
        system((("cat " + commands[j]) + " | ./" + name[i]).c_str());
    }

}
