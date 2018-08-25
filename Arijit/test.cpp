#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void kMarsh(vector<string> grid) {
    
    int m = grid.size();
    int n = grid[0].length();
    
    int left[m+1][n+1], up[m+1][n+1];
    
    for( int j = 0; j < n; j++ )
    {
        for( int i = 0; i < m; i++ )
        {
            if( grid[i][j] == 'x' )
                up[i][j] = 0;
            else
                if( i == 0 )
                    up[0][j] = 1;
                else
                    up[i][j] = up[i-1][j] + 1;
        }
    }

    int ans = INT_MIN;  
    for(int i=0;i<n-1;i++)
        for(int j= i+1;j<n;j++)
        {
            int val = -1;
            for(int k=0;k<m;k++)
            {
                int up1 = (grid[i][k] == 'x')?0:1;
                if((up[j][k] - up[i][k] + up1) == (j-i+1))
                {
                    if(val==-1)
                        val=k;
                    else
                    {
                        if( (k-val)>0 && (j-i)>0  )
                            ans = max(ans,(2*(k-val)) + (2*(j-i)));
                    }
                        
                }
                if(grid[i][k] == 'x' || grid[j][k] == 'x')
                    val = -1;
            }
        }
    if( ans <= 0 )
        cout<<"impossible"<<endl;
    else
        cout<<ans<<endl;
    return;
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    vector<string> grid(m);

    for (int grid_itr = 0; grid_itr < m; grid_itr++) {
        string grid_item;
        getline(cin, grid_item);

        grid[grid_itr] = grid_item;
    }

    kMarsh(grid);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

