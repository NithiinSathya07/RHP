import java.util.Scanner;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter N: ");
        int N = sc.nextInt();
        for(int i=1; i<=N; i=i+2)
        {
            
            System.out.println(i);
            
        }
        sc.close();
    }
}