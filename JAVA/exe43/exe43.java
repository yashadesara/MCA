import java.util.function.Predicate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class counter 
{
    public static <T> int countIf(List<T> list, Predicate<T> p) 
    {
        int count = 0;
        for (T elem : list) 
        {
            if (p.test(elem)) 
            {
                ++count;
            }
        }
        return count;
    }
}

class Operation 
{
    public static boolean checkEven(final int num) {
        return num % 2 == 0;
    }

    public static boolean checkOdd(final int num) {
        return num % 2 != 0;
    }

    public static boolean checkPrime(final int num) {
        if (num == 0 || num == 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean checkPelindrome(Integer num) {
        int r, sum = 0, temp;
        temp = num;
        while (num > 0) {
            r = num % 10;
            sum = (sum * 10) + r;
            num = num / 10;
        }
        return (temp == sum);
    }
}

public class exe43 {
    public static void main(String args[]) 
    {
        List <Integer> list = Arrays.asList(1,2,5,7,8);
        int count=0;
        count = counter.countIf(list, Operation::checkOdd);
        System.out.println("Number of odd: "+count);
        
        count = counter.countIf(list, Operation::checkEven);
        System.out.println("Number of even: "+count);
        
        count = counter.countIf(list, Operation::checkPrime);
        System.out.println("Number of prime: "+count);
        
        count = counter.countIf(list, Operation::checkPelindrome);
        System.out.println("Number of pelindrome: "+count);
    }
}