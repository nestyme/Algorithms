#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


class GameObject
{	private:
	int x;
	int y;
    public:
    int size;
        GameObject(int x_, int y_)
        {   
            x = x_;
            y = y_;
        }                  
        virtual char symbol() const
        {
        	return '?';
        }
        virtual void print() const
        {
        	cout << '(' << x << ',' << y << ')' << '\n';
        }
        int get_x() const
        {
        	return x;
        }
        int get_y() const
        {
        	return y;
        }
        int get_size() const
        {
        	return size;
        }
        void change_x(int new_value)
        {
        	x = new_value;
        }
        void change_y(int new_value)
        {
        	y = new_value;
        }
        void change_size(int new_value)
        {
        	size = new_value;
        }
        void move(int x_, int y_)
        {
        	x = x_;
        	y = y_;
        }
        

}; 
  class Creature : public GameObject
        {   
        	private:
        		int hp;
        	public:
            Creature(int hp_, int x_, int y_, int size_): GameObject(x_, y_)
                {
                    hp = hp_;
                    size = size_;
                };
               void print() const
                {
                    cout << "Creature:" << '(' << get_x() << ',' << get_y() << ')' << get_hp() << '\n';
        		}
        		char symbol() 
        		{
        			return '?';
        		}
        		
        		int get_hp() const
        		{
        			return hp;
        		}
        };
    class Hero: public Creature
    	{
    		private:
    			string name;
    		public:
    			Hero(int hp_, int x_, int y_, int size_, string name_): Creature(hp_, x_,y_, size_)
    			{
    				name = name_;
    				size = size_;
    			}
    			void print() 
    			{
    				cout << "Hero: " << '(' << get_x() << ',' << get_y() << ')' << ' ' << get_name() << ' ' << get_hp() << '\n';
    			}
    			char symbol() const
    			{	
					return name[0];
    			}
    			string get_name() const
    			{
    				return name;
    			}
    	};
    class Monster : public Creature
    	{	private:
    			int line;
    		public:
    			Monster(int hp_, int x_, int y_, int size_, int line_) : Creature(hp_, x_, y_, size_)
    			{
    				line = line_;
    				size = 1;
    			}
    			void print() const
    			{
    				cout << "Monster: " << '(' << get_x() << ',' << get_y() << ')' << ' ' << "line:" << get_line() << '\n';
    			}
    			int get_line() const
    			{
    				return line;
    			}
    			char symbol()
    			{
    				return 'M';
    			}
    	};
    class Terrain : public GameObject
    {
    	public:
    		Terrain(int x_, int y_, int size_) : GameObject(x_, y_)
    		{
    			size = size_;
    		}
    		void print() const
    		{
    			cout << "Terrain: " << '(' << get_x() << ',' << get_y() << ')' << '\n';
    		}
    		char symbol()
    		{
    			return '?';
    		}
    };
    class Forest : public Terrain
    {	public:
    	Forest(int x_, int y_, int size_):Terrain(x_, y_, size_)
    	{};
    	void print()
    	{
    		cout << "Forest: " << '(' << get_x() << ',' << get_y() << ')' << ' ' << get_size() << '\n';
    	}
    	char symbol()
    	{
    		return '`';
    	}
    };
    class Mountain : public Terrain
    {
    	private:
    		int heigth;
    	public:
    	Mountain(int x_, int y_, int size_, int heigth_) : Terrain(x_, y_, size_)
    	{
    		heigth = heigth_;
    	}
    	void print() const
    	{
    		cout << "Mountain: " << '(' << get_x() << ',' << get_y() << ')' << ' ' << "heigth = " << get_heigth() << get_size() <<  '\n';
    	}
    	int get_heigth() const
    	{
    		return heigth;
    	}
    	char symbol() const
    	{
    		return '^';
    	}
    
   	};
    
    class Lake : public Terrain
    {
    	private:
    		int depth;
    	public:
    		int get_depth() const
    		{
    			return depth;	
    		}
    		Lake(int x_, int y_, int size_, int depth_) : Terrain(  x_,  y_, size_)
    		{
    			depth = depth_;
   			}
   			void print() const
   			{
   				cout << "Lake: " << '(' << get_x() << ',' << get_y() << ')' << ' ' << "depth = " << get_depth() << get_size() << '\n';
    		}
   			char symbol() const
   			{
   				return '~';
   			}
    };
    
 class World
{
	private:
		int width;
		int heigth;
		int objects_count;
		GameObject* Objects[10];
		char* map;
		void render()
		{
    		map = (char*)malloc( sizeof(char) * (heigth * (2 * width + 1) + 1));
    		for (int i = 1 ; i < heigth * (2 * width + 1) + 1; ++i)
    			{
        			if (i / 2 != 0)
            			map[i] = '.';
        				else map[i] = ' ';
    			}
   			for (int i = 1; i <= heigth; ++i)
    			{
    				map [(2 * width + 1) * i] = '\n';
    			}
		}
		bool render(GameObject& object_)
		{
        	int size = object_.get_size();
        	int x = object_.get_x();
        	int y = object_.get_y();
        	char c = object_.symbol();
        	
        	if ((x + size > width) || (y + size > heigth))
        		{
        			cout << "Error!" << '\n';
        			return 0;
        		}
        	else
        	{

	        	for (int i = 0; i < size; ++i)
    	    	{
        	    	for (int j = 0; j < size; ++j)
            		{
            			map[(y - 1 + i) * (width * 2 + 1) + (x - 1) * 2 + 1 + j ] = c;
					}	
				}
				
			};
		}
	public:
		World(int width_, int heigth_)
		{
    		width = width_;
    		heigth = heigth_;
    		objects_count=0;
    		render ();
		}
 		void print_map ()
		{
    		for (int i = 1; (i < heigth*(2*width+1)+1); ++i)
    			{
    				cout << map[i];
    			};
		}
		void add_object(GameObject* object)
		{	
    		 Objects[objects_count] = object;
   			 objects_count++;
   			 render(*object);
		}
}; 
int main ()
{
	//setlocale(LC_ALL, "Russian");
	cout << "1. See an example" << '\n' << "2.Enter your own map" << '\n';
	int n;
	cin >> n;
	if (n == 1)
			   {
					World ex(20,20);
    				Hero Abbadon (100,3,4,2,"Abbadon");
    				Abbadon.print();
   					Lake l (5,4,2,10);
   					l.print();
   					Forest F (13,7,2);
   					F.print();
   					Mountain M(7,8,2,5);
   					M.print();
    				ex.add_object (&Abbadon);
    				ex.add_object(&l);
    				ex.add_object(&M);
    				ex.add_object(&F);
    				ex.print_map();
   					system("pause");
   					return 0;
				};
	cout << "Enter width and heigth:" << '\n';
	int m;
	cin >> n >> m;
	cout << "Enter GameObject(first letter):" << '\n'<<"Monster - M, Mountain - N, Q - quit"<<'\n';
	World a(n, m);
	a.print_map();
	char c;
	while(1)
	{	int quit = 0;
		cin >> c;
		
		switch (c)
		{
			case 'H':
				{	
					cout << "Enter the name of the Hero, x, y, size, health points " << '\n';
					string name_tmp = new char [15];
					int x,y;
					int size;
					int h_p;
					cin >> name_tmp >> x >> y >> size >> h_p;
					Hero H(h_p, x, y, size, name_tmp);
					a.add_object(&H);
					break;
					
				}
			case 'M':
				{
					cout << "Enter the line of the Monster, x, y, size, health points " << '\n';
					int line;
					int x,y;
					int size;
					int h_p;
					cin >> line >> x >> y >> size >> h_p;
					Monster M(h_p, x, y, size, line);
					a.add_object(&M);
					break;
				}
			case 'L':
				{
					cout << "Enter the depth of the Lake, x, y, size" << '\n';
					int depth;
					int x,y;
					int size;
					cin >> depth >> x >> y >> size;
					Lake L(x, y, size, depth);
					a.add_object(&L);
					break;
				}
			case 'F':
				{
					cout << "Enter x, y, size" << '\n';
					int x,y;
					int size;
					cin >> x >> y >> size;
					Forest F(x, y, size);
					a.add_object(&F);
					break;
				}
			case 'N':
				{
					cout << "Enter the heigth of the Mountain, x, y, size" << '\n';
					int heigth;
					int x,y;
					int size;
					cin >> heigth >> x >> y >> size;
					Mountain Mn(x, y, size, heigth);
					a.add_object(&Mn);
					break;
				}
			case 'Q':
				{
					++quit;
					break;
				}

		a.print_map();
		if (quit)
			{
				break;
			}
		}
	}
    system("pause");
}
      
        
        
               
            
            
            

