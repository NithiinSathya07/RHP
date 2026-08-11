//https://www.hackerrank.com/challenges/bfsshortreach/problem
//https://www.hackerrank.com/challenges/bfsshortreach/submissions/code/479891612
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'bfs' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER m
     *  3. 2D_INTEGER_ARRAY edges
     *  4. INTEGER s
     */

    public static List<Integer> bfs(int n, int m, List<List<Integer>> edges, int s) {
    // Build adjacency list using Map
    Map<Integer, List<Integer>> g = new HashMap<>();
    for (int i = 1; i <= n; i++) {
        g.put(i, new ArrayList<>());
    }
    for (List<Integer> edge : edges) {
        int a = edge.get(0);
        int b = edge.get(1);
        g.get(a).add(b);
        g.get(b).add(a);
    }

    // Queue for BFS storing {node, edgesCount}
    Queue<int[]> q = new LinkedList<>();
    int INF = (int) 2e9;
    int[] dist = new int[n + 1];
    Arrays.fill(dist, INF);

    q.add(new int[]{s, 0});
    dist[s] = 0;

    while (!q.isEmpty()) {
        int[] curr = q.poll();
        int node = curr[0];
        int edgeCount = curr[1];

        for (int oth : g.get(node)) {
            if (dist[oth] > edgeCount + 1) {
                dist[oth] = edgeCount + 1;
                q.add(new int[]{oth, edgeCount + 1});
            }
        }
    }

    List<Integer> ans = new ArrayList<>();
    for (int node = 1; node <= n; node++) {
        if (node == s) continue;
        ans.add(dist[node] == INF ? -1 : dist[node] * 6);
    }

    return ans;
}

}

class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                int n = Integer.parseInt(firstMultipleInput[0]);

                int m = Integer.parseInt(firstMultipleInput[1]);

                List<List<Integer>> edges = new ArrayList<>();

                IntStream.range(0, m).forEach(i -> {
                    try {
                        edges.add(
                            Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                                .map(Integer::parseInt)
                                .collect(toList())
                        );
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                });

                int s = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> result = Result.bfs(n, m, edges, s);

                bufferedWriter.write(
                    result.stream()
                        .map(Object::toString)
                        .collect(joining(" "))
                    + "\n"
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}