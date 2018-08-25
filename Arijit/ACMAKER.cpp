#include <bits/stdc++.h>

using namespace std;

int main() 
{
    while(1) 
    {
        int n; 
        cin >> n; 
        if (n == 0) 
        	return 0;
        set<string> insignificant;
        
        for (int i = 0; i < n; i++) 
        {
            string s; 
            cin >> s; 
            insignificant.insert(s);
        }

        while(1) 
        {
            string acro; 
            cin >> acro; 
            cin.ignore();
            string phrase; 
            getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            vector<string> words;
            for (;;) 
            {
                string word; 
                iss >> word;
                if (word == "") 
                	break;
                if (insignificant.find(word) == insignificant.end())
                    words.push_back(word);
            }
           
            int dp[151][151], dp2[151][151]; 
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            
            for (int i = 0; i < words.size(); i++) 
            {
                for (int j = 0; j < acro.length(); j++) 
                {
                    int mx = min(acro.length() - j, words[i].length());
                    for (int k = 0; k <= words[i].length(); k++) 
                        dp2[k][0] = 1;

                    for (int k = 1; k <= mx; k++)
                        dp2[0][k] = 0;
                    
                    for (int k = 0; k < words[i].length(); k++) 
                    {
                        for (int m = 0; m < min(mx,k+1); m++) 
                        {
                            dp2[k+1][m+1] = dp2[k][m+1];
                            if (words[i][k] == tolower(acro[j+m]))
                                dp2[k+1][m+1] += dp2[k][m];
                        }
                    }

                    for (int k = 1; k <= mx; k++)
                        dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
                }
            }

            if (dp[words.size()][acro.length()] == 0)
                cout << acro << " is not a valid abbreviation" << endl;
            else
                cout << acro << " can be formed in " << dp[words.size()][acro.length()] << " ways" << endl;
        }
    }
}