#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class square {
    private:
        static unsigned int m_counter;
        
        unsigned int m_width;
        unsigned int m_height;
        
    public:
        square() {
            m_counter++;
            m_width = rand()%20 + 1;
            m_height = rand()%20 + 1;
            cout << "created square with width: " << m_width 
                 << " and height: " << m_height << endl;
        }
        ~square() {
            m_counter--;
            cout << "deleted square with width: " << m_width 
                 << " and height: " << m_height << endl;
        }
        
        inline static unsigned int get_counter() { return m_counter; } 
};
unsigned int square::m_counter = 0;

int main() {
    srand(time(0) );
    
    int number;
    square* squares = NULL;

    do {
        cout << endl;
        cout << "-----" << endl;
        cout << "number of squares: " << square::get_counter() << endl;
        cout << endl;
        cout << "how many squares (0=exit)? ";
        cin >> number;
        
        if(number > 0) {
            if(squares) delete[] squares;
            cout << endl;
            squares = new square[number];
        }
    } while(number != 0);
    
    if(squares) delete[] squares;
    
    return 0;
}
