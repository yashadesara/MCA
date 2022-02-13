public class exe32 {
    public static void main(String[] args) {
        try {
            System.out.println(10 / 0);
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            System.out.println("This is executed weather error is ocuurs or not");
        }
    }
}
