#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
template <typename T>
class Vector
{	
		public:
		int size;
		T* arr;

Vector(int _size)
	{
		size = _size;
		for(int i = 0; i < size; i++)
			{
				arr[i] = 0;
			}
	};
Vector(T* _arr,int _size)
	{
		arr = _arr;
		size = _size;
	};
int get_value(const int i)
	{
		return arr[i];
	};
const int size_of_arr()
{
	return size;
}
int size_of_arr(Vector* A)
{
    return A->size;
}
void sort()
{
	for(int i = 0; i < size; i++)
		for(int j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j])
				{
					int tmp;
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
		}
}

void delete_element(int i)
{
	for(int j = i; j < size; j++)
	{
		arr[j] = arr[j + 1];
	}
	size--;
	arr = (T*)realloc(arr, sizeof(T)*size);
}

void insert_element(const int i, const T elem)
{
	size++;
	arr = (T*)realloc(arr, sizeof(T)*size);
	for(int k = size - 1; k > i; k--)
	{
		arr[k] = arr[k - 1];
	}
	arr[i] = elem;
}
void resize(int const new_size)
{
	arr = (T*)realloc(arr, sizeof(T)*new_size);
	if (size < new_size)
		{
			for(int i = size; i < new_size; i++)
			{
				arr[i] = 0;
			}
		}

	size = new_size;
}
void change_data(int i, T new_data)
{
		arr[i] = new_data;
}
bool operator ==(Vector* A)
    {
        int tmp = 0;
        if (size_of_arr() == A->size_of_arr())
           {
               while ((A->arr[tmp] == arr[tmp])&&(tmp <= size_of_arr()))
                {
                    tmp++;
                }
           }
        if (tmp == size_of_arr())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
template <typename D>
  class iterator
{   private:
        int idx;
        Vector<D> v;
    public:
        iterator(int _idx, Vector<D> _v)
        {
            idx = _idx;
            v = _v;
        }
    iterator begin()
    {
        return iterator(0,v);
    }
    iterator end()
    {
        return iterator(v->size, v);
    };
    iterator* operator ++()
    {
        int u = idx + 1;
        iterator w  = iterator(u, v);
        return &w;
    }
    iterator* operator --()
    {
        int u = idx - 1;
        iterator w  = iterator(u, v);
        return &w;
    }
    bool operator !=(iterator* a)
    {
        if ((idx == a->idx) && (*v == a->v))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    };
};
};

int main()
{
	char* a;
	int size;
	cout << "Enter size of your array:";
	cout << '\n';
	cin >> size;
	a = (char*)malloc(sizeof(char)*size);
	Vector<char> Vect = Vector<char>(a, size);
	cout << "Enter your array:";
	cout << '\n';
	for(int i = 0; i < (&Vect)->size_of_arr(); i++)
		{
			
			char tmp;
			cin >> tmp;
			(&Vect) -> arr[i] = tmp;
		}
	cout << '\n';
	cout << "--------FUNCTIONS--------" << '\n' << "Enter number of desired action from this list:" <<'\n';
	cout << "1 -> get value of element by index" << '\n';
	cout << "2 -> delete element " << '\n';
	cout << "3 -> insert element" << '\n';
	cout << "4 ->sort" << '\n';
	cout << "5 -> get size of array" << '\n';
	cout << "6 ->resize array" << '\n';
	cout << "7 -> change data" << '\n';
	cout << "8 -> compare " << '\n';
	cout << "press 0 to quit" << '\n';
	while (1)
	{	int choice = -1;
		cout << "Make the choice:" << '\n';
		cin >> choice;
		if (choice == 0)
			{
				system("pause");
				return 0;
			}
		else
		switch (choice)
		{
			case 1:
				{
					cout << "What index of the element are you searching for?" << '\n';
					int index;
					cin >> index;
					cout <<'\n';
					int tmp = Vect.size_of_arr();
					if ( index > tmp)
						{
							cout << '\n' << "Error! Going beyond the array"<<'\n';
							break;
						}
					int value = Vect.get_value(index);
					cout << "Your element is: " << value << '\n';
					break;
				}
			case 2:
				{
					cout << "What index of the element would you like to delete?" << '\n';
					int ind;
					int tmp = Vect.size_of_arr();
					cin >> ind;
					if ( ind > tmp)
						{
							cout << '\n' << "Error! Going beyond the array" << '\n';
							break;
						}
					Vect.delete_element(ind);
					cout << "Now your array:" << '\n';
					break;
				}
			case 3:
				{
					cout << "What element would you like to insert?" << '\n';
					int val;
					cin >> val;
					cout << '\n' << "Where?" << '\n';
					int in;
					cin >> in;
					int tmp = Vect.size_of_arr();
					if (( in > tmp) || (in < 0))
						{
							cout << '\n' << "Error! Going beyond the array" << '\n';
							break;
						}
					Vect.insert_element(in,val);
					cout << "Now your array:" << '\n';
					break;
				}
			case 4:
				{	int tmp = Vect.size_of_arr();
					if (tmp == 0)
						{
							cout << '\n' << "Error! Zero size of array"<<'\n';
							break;
						}
					Vect.sort();
					cout << "Your array after sorting:" << '\n';
					break;
				}
			case 5:
				{
					int size = Vect.size_of_arr();
					cout <<'\n' << "Current size of array:" << size << '\n';
					break;
				}
			case 6:
				{
					cout <<"Enter new size of array:"<<'\n';
					int new_size;
					cin >> new_size;
					Vect.resize(new_size);
					break;
				}
			case 7:
				{
					cout << "Enter data and index to change:" << '\n';
					int index;
					int data;
					int tmp = Vect.size_of_arr();
					cin >> data >> index;
					if (index > tmp)
					{
						cout << '\n' <<"Error! Going beyond the array" <<'\n';
							break;
					}
					Vect.change_data(index, data);
					break;
				}
            case 8:
                {   cout << '\n' << "Size of second array:" << '\n';
                    int size_2;
                    cin >> size_2;
                    char* b;
                    b = (char*)malloc(sizeof(char)*size_2);
                    Vector<char> Vect_2 = Vector<char>(b, size_2);
                    for(int i = 0; i < Vect_2.size_of_arr(); i++)
                    {
                        char tmp;
                        cin >> tmp;
                        Vect_2.arr[i] = tmp;
                    }
                    if ( Vect_2.operator==(&Vect))
                        cout << '\n' << "Equal";
                    else
                        cout << '\n' << "Not equal"<<'\n';
                    break;
                }
			default:
				{
					cout << '\n' << "Wrong data!"<<'\n';
					system("pause");
				}
		}
	cout << "_________________________" << '\n';
	for(int j = 0; j < Vect.size_of_arr(); j++)
		{
				cout << Vect.arr[j] << " ";
		}
	cout << '\n';
	cout << "_________________________";
	cout << '\n';
	}
	return 0;
}
