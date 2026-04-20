import java.util.*;

class GenSort {

    static <T> void selectionSort(T[] arr, Comparator<T> c) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (c.compare(arr[i], arr[j]) > 0) {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {

        Integer[] arr = {5, 2, 9, 1, 3};

        selectionSort(arr, (a, b) -> a - b);

        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}