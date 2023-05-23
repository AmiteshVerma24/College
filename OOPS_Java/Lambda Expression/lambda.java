import java.util.*;

interface factorial{
    public void find_factorial(int num);
}

class lambda{
   public static void main(String[] args) {
        factorial f = (num) -> {
            int fac = 1;
            for (int i = 1 ; i <= num ; i++){
                fac = fac * i;
                }
            System.out.format("The factorial of number is %d.",fac);
        };
        f.find_factorial(10);
    }

}
