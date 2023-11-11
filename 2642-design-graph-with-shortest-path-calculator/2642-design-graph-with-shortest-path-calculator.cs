public class Graph {
    List<List<(int destination, int distance)>> graph = new List<List<(int, int)>>();
    private int nodes;
    public Graph(int n, int[][] edges) {
        nodes = n;
        for(int i = 0; i < n; i++)
        {
            graph.Add(new List<(int, int)>());
        }

        foreach(var edge in edges)
        {
            graph[edge[0]].Add((edge[1], edge[2]));
        }
    }
   
    public void AddEdge(int[] edge) {
        graph[edge[0]].Add((edge[1], edge[2]));
    }
   
    public int ShortestPath(int node1, int node2) {
        var currentVistedAt = new int[nodes];
        Array.Fill(currentVistedAt, int.MaxValue);
        currentVistedAt[node1] = 0;
        var queue = new PriorityQueue<int, int>();
        queue.Enqueue(node1, 0);
        while(queue.Count > 0)
        {
            var current = queue.Dequeue();
            var neighbors = graph[current];
            foreach(var neighbor in neighbors)
            {
                var visitedAt = currentVistedAt[current] + neighbor.distance;
                if(currentVistedAt[neighbor.destination] > visitedAt)
                {
                    currentVistedAt[neighbor.destination] = visitedAt;
                    queue.Enqueue(neighbor.destination, visitedAt);
                }
            }
           
        }

        return currentVistedAt[node2] == int.MaxValue ? - 1: currentVistedAt[node2];
    }
}