import apack.A;

public class Rectangle {
    int length = 10, width = 20;
    static int count = 0;

    Rectangle() {
        count = length + width;
        System.out.println(count);
    }

    Rectangle(int l, int w) {
        this.length = l;
        this.width = w;
        count = l + w;
        System.out.println(count);
    }

    Rectangle(Rectangle r) {
        length = r.length;
        width = r.width;
        count = r.length + r.width;
        System.out.println(count);
    }

    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        Rectangle r1 = new Rectangle(10, 20);
        Rectangle r2 = new Rectangle(r1);
    }

}
