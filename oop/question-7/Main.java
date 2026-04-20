import java.util.*;

class Cart {

    HashMap<String, Integer> products = new HashMap<>();
    ArrayList<String> history = new ArrayList<>();

    void add(String name, int qty) {
        products.put(name, products.getOrDefault(name, 0) + qty);
    }

    void checkout() {
        history.add(products.toString());
        products.clear();
    }

    void showCart() {
        System.out.println(products);
    }

    void showHistory() {
        for (String h : history) {
            System.out.println(h);
        }
    }

    public static void main(String[] args) {
        Cart c = new Cart();

        c.add("Pen", 2);
        c.add("Book", 1);

        c.showCart();

        c.checkout();

        c.showHistory();
    }
}