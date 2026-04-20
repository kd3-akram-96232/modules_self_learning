class GenMin {

    static <T extends Number> T findMin(T[] arr) {
        T min = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i].doubleValue() < min.doubleValue()) {
                min = arr[i];
            }
        }

        return min;
    }

    public static void main(String[] args) {
        Integer[] a = {5, 2, 9, 1, 3};

        System.out.println(findMin(a));
    }
}