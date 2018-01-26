/* Booth's algorithm : Basically it is modified prefix function of the KMP algo */
int lowest_string_rotation(string & P){
	P+=P;
	vi f(P.length(),-1);
	int s = 0;									/* denotes starting index of lexicographically smallest string */
	for (int i = 1; i < P.size(); ++i)
	{
		char sj = P[i];
		int k = f[i-s-1];						/* k denotes the offset from s to check with i */
		while (k!=-1 && sj != P[s+k+1]){
			/* change k, change s only if lexicographically smaller */
			if(sj < P[s+k+1])					/* this part is extra compared to KMP */
				s = i-k-1;
			k = f[k];
		}
		if (sj != P[s+k+1]){
			if (sj < P[s])						/* this part is extra compared to KMP */
				s = i;
			f[i-s] = -1;
		}
		else
			f[i-s] = k+1;
	}
	return s;
}
