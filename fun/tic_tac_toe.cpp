#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class game {
    private:
        int m_table[9];
        int m_status;
        
        bool check_end_condition() {
            bool end = 0;
            for(int i=1; i<5; i++)
                if(m_table[4] && m_table[4]==m_table[4+i] && m_table[4]==m_table[4-i])
                    end=1;
            for(int i=0; i<3; i++)
                if(m_table[i] && m_table[i]==m_table[i+3] && m_table[i]==m_table[i+6])
                    end=1;
            for(int i=0; i<9; i+=3)
                if(m_table[i] && m_table[i]==m_table[i+1] && m_table[i]==m_table[i+2])
                    end=1;
            if(end) m_status +=3;
            else {
                for(int i=0; i<9; i++)
                    if(m_table[i]==0)
                        return 0;
                m_status = 2;
            }
            return 1;
        }
        
    public:
        game() {
            for(int i=0; i<9; i++) m_table[i]=0;
            m_status = std::rand()%2;
        }
        
        int get_status() { return m_status-3; }
        int get_on_move() { return m_status<2 ? m_status : -1; }
        
        bool play_move(int n) {
            if(m_status>1 || m_table[n]) return 0;
            m_table[n] = 1+m_status;
            if(!check_end_condition() ) m_status = 1-m_status;
            return 1;
        }
        
        bool is_running() { return m_status<2; }
        void print() {
            for(int y=0; y<3; y++) {
                for(int x=0; x<3; x++)
                    switch(m_table[x+3*y]) {
                        case 1:  std::cout << "X"; break;
                        case 2:  std::cout << "O"; break;
                        default: std::cout << "_"; break;
                    }
                std::cout << std::endl;
            }
        }
};

int main() {
    srand(time(0) );
    game theGame;
    int n;
    
    while(theGame.is_running() ) {
        theGame.print();
        
        switch(theGame.get_on_move() ) {
            case 0: std::cout << "player X is on move" << std::endl; break;
            case 1: std::cout << "player O is on move" << std::endl; break;
            default: break;
        }
        
        do {
            std::cout << "move 0 1 2" << std::endl;
            std::cout << "     3 4 5" << std::endl;
            std::cout << "     6 7 8: ";
            std::cin >> n;
        } while(!theGame.play_move(n) );
    }
    
    std::cout << std::endl;
    theGame.print();
    std::cout << std::endl;
    switch(theGame.get_status() ) {
        case 0: std::cout << "Player X is winner!" << std::endl; break;
        case 1: std::cout << "Player O is winner!" << std::endl; break;
        default: std::cout << "No winner in this game!" << std::endl; break;
    }
    
    return 0;
}
