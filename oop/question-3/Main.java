class Food {
    String type;

    Food(String type) {
        this.type = type;
    }
}

class Animal {
    String name;
}

class Lion extends Animal { // IS-A
    Food food; // HAS-A

    Lion(String name, String foodType) {
        this.name = name;
        this.food = new Food(foodType);
    }

    void show() {
        System.out.println(name + " eats " + food.type);
    }

    public static void main(String[] args) {
        Lion l = new Lion("Lion", "Meat");
        l.show();
    }
}