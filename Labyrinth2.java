import java.util.*;

class Labyrinth2
{
    private static String getPath(int pr, int pc, char g[][])
    {
        StringBuilder sb = new StringBuilder();
        // Since g[br][bc] was overwritten with the last direction character,
        // we start accumulating directions directly.
        while(g[pr][pc] != 'A')
        {
            char ch = g[pr][pc];
            sb.append(ch);
            if(ch=='U') pr++;
            else if(ch=='L') pc++;
            else if(ch=='R') pc--;
            else if(ch=='D') pr--;
        }
        return sb.reverse().toString();
    }
    
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt(), C = sc.nextInt(); sc.nextLine();
        char[][] g = new char[R][C];
        for(int row=0; row<R; row++)
        {
            g[row] = sc.nextLine().toCharArray();
        }
        
        Queue<int[]> q = new LinkedList<>();
        for(int row=0; row<R; row++)
        {
            for(int col=0; col<C; col++)
            {
                if(g[row][col]=='A')
                {
                    q.add(new int[]{row,col});
                    row = R; break;
                }
            }
        }

        int hops = -1, br=-1, bc=-1;
        boolean found = false;
        // diff indices: 0 -> (0,1), 1 -> (1,0), 2 -> (0,-1), 3 -> (-1,0)
        int[] diff = {0,1,0,-1,0};
        // Matched exact directions: (0,1) is 'R', (1,0) is 'D', (0,-1) is 'L', (-1,0) is 'U'
        final String dir = "RDLU";
        
        while(!q.isEmpty())
        {
            int qsize = q.size();
            hops++;
            
            while(qsize-- > 0)
            {
                int[] cell = q.poll();
                int row = cell[0], col=cell[1];
                
                // If we popped destination cell, print immediately using current hops count
                if(found && row == br && col == bc)
                {
                    System.out.println("YES");
                    System.out.println(hops);
                    System.out.println(getPath(br, bc, g));
                    sc.close();
                    return;
                }

                for(int i=0; i<4; i++)
                {
                    int ar = row+diff[i], ac = col+diff[i+1];
                    if(ar>=0 && ar<R && ac>=0 && ac<C)
                    {
                        char ch = g[ar][ac];
                        if(ch=='.')
                        {
                            q.add(new int[]{ar,ac});
                            g[ar][ac] = dir.charAt(i);
                        }
                        else if(ch=='B')
                        {
                            found = true;
                            br = ar; bc = ac;
                            q.add(new int[]{ar,ac});
                            g[ar][ac] = dir.charAt(i);
                        }
                    }
                }
            }
        }
        System.out.println("NO");
        sc.close();
    }
}