class EcomException extends Exception {
    EcomException(String msg) {
        super(msg);
    }
}

class PaymentException extends EcomException {
    PaymentException(String msg) {
        super(msg);
    }
}

class InventoryException extends EcomException {
    InventoryException(String msg) {
        super(msg);
    }
}

class ShippingException extends EcomException {
    ShippingException(String msg) {
        super(msg);
    }
}

class TestEx {
    static void checkPayment(int amt) throws PaymentException {
        if (amt < 100)
            throw new PaymentException("Payment failed");
    }

    public static void main(String[] args) {
        try {
            checkPayment(50);
        } catch (EcomException e) {
            System.out.println(e.getMessage());
        }
    }
}