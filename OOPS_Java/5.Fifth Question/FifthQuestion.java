import java.util.*;

class matrix{
    int rows, columns;
    int mat[][];
    public matrix(int r , int c){
        this.rows = r;
        this.columns = c;
        this.mat = new int[r][c];
    }
    public void takeInput(){
        Scanner sc = new Scanner(System.in);
        for (int i = 0 ; i < this.rows ; i++){
            for (int j = 0 ; j < this.columns ; j++){
                System.out.format("Enter the %d , %d element of the matrix:- ",i,j);
                this.mat[i][j] = sc.nextInt();
            }
        }
        sc.close();
    }
    public void display(){
        for (int i = 0 ; i < this.rows ; i++){
            for (int j = 0 ; j < this.columns ; j++){
                System.out.format(" %d ",this.mat[i][j]);
            }
            System.out.println();
        }
    }
    public int getRows(){
        return this.rows;
    }
    public int getColumns(){
        return this.columns;
    }

}
public class FifthQuestion {
    static void matrixMultiply(matrix m1 , matrix m2){
        System.out.println("Multiply Matrix");
        matrix result = new matrix(m1.getRows(), m2.getColumns());
        for(int i = 0 ; i < m1.getRows() ; i++){
            for (int j = 0 ; j < m2.getColumns() ; j++){
                for (int k = 0 ; k < m2.getRows() ; k++){
                    result.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
                }
            }

        }
        System.out.println("The multiplication matrix is: ");
        result.display();
    }
    public static void main(String[] args) {
        int r1, r2, c1, c2;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows of first Matrix: ");
        r1 = sc.nextInt();
        System.out.print("Enter the number of column of first Matrix: ");
        c1 = sc.nextInt();
        System.out.print("Enter the number of rows of second Matrix: ");
        r2 = sc.nextInt();
        System.out.print("Enter the number of column of second Matrix: ");
        c2 = sc.nextInt();
        matrix m1 = new matrix(r1,c1);
        matrix m2 = new matrix(r2 , c2);
        if(m1.getColumns() == m2.getRows()){
            System.out.println("Enter elements of first matrix: ");
            m1.takeInput();
            System.out.println("Enter elements of second matrix: ");
            m2.takeInput();
            System.out.println("Elements of first matrix are: ");
            m1.display();
            System.out.println("Elements of second matrix are: ");
            m2.display();
            matrixMultiply(m1 , m2);
        }else{
            System.out.println("MATRIX MULTIPLICATION NOT POSSIBLE!");
        }
        sc.close();

    }
}