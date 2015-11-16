#include <iostream>
#include <sstream>
using namespace std;

struct cData {
	int number;
	
	void input() {
		cout << "Number: ";
		cin >> number;
	}
	
	void show() {
		cout << "Number: " << number << endl;
	}
};


/**
 * Stack structure.
 */
class cStack {
	
	public:
		
		/** 
		 * Used to add element to stack (on top of it).
		 * 
		 * @arg cData data 		data to add on top of stack
		 */
		void push(cData data) {
			cElem* elem = new cElem;
			elem->data = data;
			elem->prev = m_top;
			m_top = elem;
		}
		
		/** 
		 * Used to remove top element from stack.
		 * 
		 * @throw string 		if called on empty stack
		 */
		void pop() {
			if(!m_top)
				throw new string("Stack is empty!");
			cElem* elem = m_top;
			m_top = m_top->prev;
			delete elem;
		}
		
		/** 
		 * Used to get data from stack's top element.
		 * 
		 * @return cData		data taken from top element
		 * @throw string 		if called on empty stack
		 */
		cData top() {
			if(!m_top)
				throw new string("Stack is empty!");
			return m_top->data;
		}
		
		/** 
		 * Returns if stack is empty or not.
		 * 
		 * @return bool			is stack empty (true) or not (false)
		 */
		bool isEmpty() {
			return !m_top;
		}
		
		/** 
		 * Allocates new empty stack.
		 */
		cStack() {
			m_top = NULL;
		}
		
		/** 
		 * Deallocates stack
		 */
		~cStack() {
			while(!isEmpty() )
				pop();
		}
		
	protected:
		
		/** 
		 * Structure used for elements of stack.
		 */
		struct cElem {
			cData data;
			cElem* prev;
		};
		
		/** 
		 * Represents top element of stack.
		 * 
		 * @var cElem*		NULL if stack is empty
		 */
		cElem* m_top;
};

class cScreen {
	public:
		void add(string text, int x, int y) {
			int n = text.length() + x;
			if(n>30) n = 30;
			for(int i=x, j=0; i<n; i++, j++)
				m_screen[y][i] = text[j];
		}
		
		void render() {
			for(int y=0; y<20; y++) {
				for(int x=0; x<30; x++)
					cout << m_screen[y][x];
				cout << endl;
			}
			cout << endl;
		}
		
		void clear() {
			for(int y=0; y<20; y++)
				for(int x=0; x<30; x++)
					m_screen[y][x] = ' ';
		}
		
		cScreen() {
			for(int y=0; y<20; y++)
				for(int x=0; x<30; x++)
					m_screen[y][x] = ' ';
		}
		~cScreen() {}
		
	protected:
		char m_screen[20][30];
};

class cApp {
	
	public:
		bool run() {
			m_screen.add("< << Menu >> >", 3, 1);
			m_screen.add("[1] Add element to stack", 1, 2);
			m_screen.add("[2] Remove element from stack", 1, 3);
			m_screen.add("[3] Show top element", 1, 4);
			m_screen.add("[4] Empty stack", 1, 5);
			m_screen.add("[0] Exit", 1, 6);
			render();
			try {
				return input();
			} catch(string s) {
				cout << "Error: " << s << endl;
				return 1;
			}
		}
		
	protected:
		void show_stack(int y=10, int x=20) {
			if(y>19 || m_stack.isEmpty() )
				return;
			cData data = m_stack.top();
			m_stack.pop();
			
			show_stack(y+1);
			
			stringstream ss;
			if(y == 10) ss << "top: ";
			ss << '<' << data.number << '>';
			
			m_screen.add(ss.str(), y==10?x-5:x, y);
			
			m_stack.push(data);
		}
		
		void render() {
			show_stack();
			m_screen.render();
			m_screen.clear();
		}
		
		int input() {
			int x;
			cin >> x;
			switch(x) {
				case 0:
					break;
					
				case 1:
					cout << endl;
					cout << "Element to add: " << endl;
					m_data.input();
					m_stack.push(m_data);
					break;
					
				case 2:
					cout << endl;
					cout << "Removed element: " << endl;
					m_stack.top().show();
					m_stack.pop();
					break;
					
				case 3:
					cout << endl;
					cout << "Element at top of the stack: " << endl;
					m_stack.top().show();
					break;
					
				case 4:
					cout << endl;
					cout << "Elements removed from stack: " << endl;
					while(!m_stack.isEmpty() ) {
						m_stack.top().show();
						m_stack.pop();
					}
					break;
					
				default:
					cout << "Wrong input!" << endl;
			}
			return x;
		}
		
		cData m_data;
		cStack m_stack;
		cScreen m_screen;
};

int main() {
	
	cApp app;
	while(app.run() );
	
	return 0;
}
