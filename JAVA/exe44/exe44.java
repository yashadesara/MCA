import java.util.Arrays;

class exe44
{
    public static <T> void add(T[] arr) 
    {
        T temp = arr[0];
        arr[0] = arr[1];
        arr[1]  = temp;
    }

    public static void main(String args[]) 
    {
        Integer[] arr = {1, 2};
        String[] arr2 = {"A","B"};
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arr2));
        add(arr);
        add(arr2);
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arr2));
        
    }
}
