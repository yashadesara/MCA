public class exe17 {
    int radius, count = 0;

    exe17(String str) {
        System.out.println("parametrized Constructor");
    }

    exe17() {
        this("hello");
        System.out.println("default Constructor");
        count++;
    }

    public static void main(String[] args) {
        exe17 e = new exe17();
        System.out.println("count is " + e.count);
    }
}
