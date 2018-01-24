DFSUtil(int s, vector<bool> &visited)
{
	// Create a stack for DFS
	stack<int> stack;
 
	// Puah the current source node.
	stack.push(s);
 
	while (!stack.empty())
	{
		// Pop a vertex from stack and print it
		s = stack.top();
		stack.pop();
 
		// Stack may contain same vertex twice. So
		// we need to print the popped item only
		// if it is not visited.
		if (!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}
 
		// Get all adjacent vertices of the popped vertex s
		// If a adjacent has not been visited, then puah it
		// to the stack.
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	}
}
 
// prints all vertices in DFS manner
DFS()
{
	// Mark all the vertices as not visited
	vector<bool> visited(V, false);
 
	for (int i = 0; i < V; i++)
		if (!visited[i])
			DFSUtil(i, visited);
}