import java.util.Scanner;

public class Banking {
    int amm = 0;

    void deposite(int d) {
        amm += d;
    }

    void withdraw(int w) throws Exception {
        amm = amm - w;
        if (amm < 0)
            throw new Exception("Insufficiant balance");
        else
            System.out.println("left Rs." + amm);
    }

    public static void main(String[] args) {
        try {
            int d;
            Scanner sc = new Scanner(System.in);
            Banking b = new Banking();
            System.out.println("Enter deposite: ");
            d = sc.nextInt();
            b.deposite(d);
            System.out.println("Enter withdraw amm: ");
            d = sc.nextInt();
            b.withdraw(d);
            d = sc.nextInt();
            b.withdraw(d);
            d = sc.nextInt();
            b.withdraw(d);
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
