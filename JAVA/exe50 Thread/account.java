public class account implements Runnable {
    static int bal = 1000;
    int with;

    account(int with) {
        this.with = with;
    }

    public void run() {
        withdraw();
    }

    synchronized void withdraw() {
        bal = bal - with;
        System.out.println(bal);
    }

    public static void main(String args[]) {
        account a = new account(300);
        account a2 = new account(400);
        Thread t1 = new Thread(a);
        Thread t2 = new Thread(a2);
        t1.start();
        t2.start();
    }
}
