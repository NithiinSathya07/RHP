import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KarenAndCoffee {
    // The maximum possible temperature given in the problem constraints is 200,000
    private static final int MAX_TEMP = 200000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        // Difference array to count recipe coverage efficiently
        // We use size MAX_TEMP + 2 to avoid OutOfBounds when marking r + 1
        int[] diff = new int[MAX_TEMP + 2];

        // Read all recipes and apply range updates to the difference array
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            diff[l]++;
            diff[r + 1]--;
        }

        // Build the frequency array and transform it into the admissible prefix sum array
        int[] prefSum = new int[MAX_TEMP + 2];
        int currentRecipes = 0;

        for (int i = 1; i <= MAX_TEMP; i++) {
            currentRecipes += diff[i]; // This recovers the actual recipe count for temperature i
            
            int isAdmissible = (currentRecipes >= k) ? 1 : 0;
            
            // Build the prefix sum array of admissible temperatures
            prefSum[i] = prefSum[i - 1] + isAdmissible;
        }

        // Process queries in O(1) time each
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            // Number of admissible integer temperatures between a and b inclusive
            int result = prefSum[b] - prefSum[a - 1];
            sb.append(result).append("\n");
        }

        // Print all outputs at once
        System.out.print(sb.toString());
    }
}