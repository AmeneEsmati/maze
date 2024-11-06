#include <cstring>
#include <iostream>
#include <stack>
#include<list>
#include <vector> 

using namespace std;



class node {
public:
	int x, y;
	int dir;

	node(int i, int j)
	{
		x = i;
		y = j;
		
	
		dir = 0;
	}
};

int z;
int M=z;
int N=z;
int r=0;
int n ,m;
stack<node> h;
int fx, fy;

list<int> t;

void printStack(stack<node> h)
{
    	for (int g=0;g<r;g++)
    
        {
            
         t.push_front(h.top().x*z+h.top().y);
            h.pop();
         }
    for (auto v : t)
        cout << v+1<<" " ;
 }

bool isReachable(vector<vector<int>> &maze,vector<vector<int>> &visited )
{
	int i = 0, j = 0 ;
	
	stack<node> s;
	node temp(i, j);
	
	s.push(temp);

	while (!s.empty()) {

		temp = s.top();

	
		int d = temp.dir;
		i = temp.x, j = temp.y;


		temp.dir++;
		s.pop();
		s.push(temp);


		if (i == fx and j == fy) {
			return true;
		}
		if (d == 3) {
			if (i - 1 >= 0 and maze[i - 1][j] and visited[i - 1][j]) {
				node temp1(i - 1, j);
				visited[i - 1][j] = false;
				s.push(temp1);
				h.push(temp1);
				r++;
			}
		}

	
		else if (d == 2) {
			if (j - 1 >= 0 and maze[i][j - 1] and	visited[i][j - 1]) {
				node temp1(i, j - 1);
				visited[i][j - 1] = false;
				s.push(temp1);
		
				h.push(temp1);
				r++;
				
			}
		}
		else if (d == 1) {
			if (i + 1 < n and maze[i + 1][j] and
									visited[i + 1][j]) {
				node temp1(i + 1, j);
				visited[i + 1][j] = false;
				s.push(temp1);
		
				h.push(temp1);
				r++;
			}
		}

		
		else if (d == 0) {
			if (j + 1 < m and maze[i][j + 1] and visited[i][j + 1]) {
				node temp1(i, j + 1);
				visited[i][j + 1] = false;
				s.push(temp1);
				h.push(temp1);
				r++;
			}
		}

	
		else {
			visited[temp.x][temp.y] = true;

			s.pop();
			h.pop();
			r--;
		}
		


	}



	return false;
}


int main()
{



cin >> z;

vector<vector<int>> visited( z , vector<int> (z));

for (int i=0;i<z;i++){
    for (int j=0;j<z;j++){
         visited[i][j]=1;
    }
}


vector<vector<int>> maze( z , vector<int> (z));

	fx = z-1;
	fy = z-1;
    m=z;
    n=z;
    int e;
for (int i=0;i<z;i++){
    for (int j=0;j<z;j++){
        cin >> e;
        maze[i][j]=!e;
    }
}




   
	if (isReachable(maze,visited)) {
	    cout << 1<<" ";
	 	printStack(h);
	}
	else
		cout << -1 ;
		
	

	return 0;
	
}
