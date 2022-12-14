#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{	
	string line; 
	ifstream myfile ("input.txt");
	
		
	long count = 0;
	long current_max = 0;
	long num = 0;
	long place2 = 0;
	long place3 = 0;

	if (myfile.is_open())
	{
		while(getline (myfile, line))
		{       
			//cout << line << endl;

			if(line != "")
			{
				num = stol(line);
				count = count + num;
			}
			else 
			{
				if(count > current_max)
				{
					place3 = place2;
					place2 = current_max;	
					current_max = count;

				}

				else if(count < current_max && count > place2)
				{
					place3 = place2;
					place2 = count;
				}

				else if(count < place2 && count > place3)
				{
					place3 = count;
				}
				count = 0;			
			}

				
		}
		myfile.close();

		cout << current_max + place2 + place3 << endl;
	}

	else cout << "Unable to open file";
	return 0;
}
