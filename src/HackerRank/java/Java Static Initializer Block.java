/*
Static initialization blocks are executed when the class is loaded, and you can initialize static variables in those blocks.
*/


    static Scanner sc = new Scanner(System.in);
    static int B = sc.nextInt();
    static int H = sc.nextInt();
    static boolean flag = false;
    static {
    if ( (B <= 0 || B > 100) || (H <= 0 || H > 100) ) {
        System.out.print("java.lang.Exception: Breadth and height must be positive");
        flag = false;
    }
        else 
        flag = true;
}

